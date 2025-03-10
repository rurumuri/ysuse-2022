using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Math;

namespace _2_4_求一元二次方程的根
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string[] input = (Console.ReadLine()).Split(' ');
            double[] inputs = new double[input.Length];
            int t = 0;
            foreach (string inputItem in input)
            {
                inputs[t++] = double.Parse(inputItem);
            }
            double a = inputs[0],b = inputs[1],c=inputs[2];
            double delta = b * b - 4 * a * c, x1, x2;
            if (a == 0 && b == 0 && c == 0)
                Console.WriteLine("Zero Equation");
            else if (a == 0 && b == 0 && c != 0)
                Console.WriteLine("Not An Equation");
            else if (a == 0 && b != 0 && c != 0)
                Console.WriteLine($"{-c/b:f2}");
            else if (a == 0 && b != 0 && c == 0)
                Console.WriteLine(0);
            else
            {
                if (delta == 0)
                {
                    x1=-b/(2*a);
                    Console.WriteLine($"{x1:f2}");  //我猜是这里的毛病 还真是。。。格式非常严格wtf
                }
                else if (delta > 0)
                {
                    x1 = (-b + Sqrt(delta)) / (2 * a);
                    x2 = (-b - Sqrt(delta)) / (2 * a);
                    Console.WriteLine($"{x1:f2}\n{x2:f2}");
                }
                else if (delta < 0)
                {
                    double x12 = -b / (2 * a);
                    x1 = (Sqrt(-delta)) / (2 * a);
                    x2 = -(Sqrt(-delta)) / (2 * a);
                    Console.WriteLine($"{x12:f2}+{x1:f2}i\n{x12:f2}{x2:f2}i");  //倒不是这里的问题
                }
            }
        }
    }
}
