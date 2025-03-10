using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Math;

namespace _7_6_求N分之一交错序列前N项和
{
    internal class Program
    {
        static void Main(string[] args)
        {
            double n = double.Parse(Console.ReadLine());
            double sum = 0;
            for (double i = 1; i <= n; i++)
            {
                sum += (1 / i)* Pow(-1, i+1);
            }
            Console.WriteLine("sum = {0:f3}", sum);
        }
    }
}
