using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1_10_计算阶乘和
{
    internal class Program
    {
        static void Main(string[] args)
        {
            double n = double.Parse(Console.ReadLine());
            double sum = 0;
            for(double i = 1; i <= n; i++)
            {
                sum += Jc(i);
            }
            Console.WriteLine(sum);
        }
        static double Jc(double n)
        {
            double jc = 1;
            for(double i = 1; i <= n; i++)
            {
                jc *= i;
            }
            return jc;
        }
    }
}
