using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _7_31_求组合数
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] inp = Array.ConvertAll(Console.ReadLine().Trim().Split(), int.Parse);
            Console.WriteLine($"result = {Fact(inp[1]) / (Fact(inp[0]) * Fact(inp[1] - inp[0]))}");
        }

        static double Fact(int n)
        {
            double s=1;
            for (int i=n; i > 0; i--)
                s *= i;
            return s;
        }
    }
}
