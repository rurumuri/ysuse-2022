using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _7_5_求奇数分之一序列前N项和
{
    internal class Program
    {
        static void Main(string[] args)
        {
            double n = double.Parse(Console.ReadLine());
            double sum = 0;
            for(double i = 0; i < n; i++)
            {
                sum += 1 / (2 * i+1);
            }
            Console.WriteLine("sum = {0:f6}",sum);
        }
    }
}
