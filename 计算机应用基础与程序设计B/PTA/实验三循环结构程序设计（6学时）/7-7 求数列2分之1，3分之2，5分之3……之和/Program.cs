using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _7_7_求数列2分之1_3分之2_5分之3之和
{
    internal class Program
    {
        static void Main(string[] args)
        {
            double n = double.Parse(Console.ReadLine());
            double sum = 0;
            double t1 = 1, t2 = 2,t3;
            for (double i = 0; i < n; i++)
            {
                sum += t2 / t1;
                t3 = t1 + t2;
                t1 = t2;
                t2 = t3;
            }
            Console.WriteLine("{0:f3}", sum);
        }
    }
}
