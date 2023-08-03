using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1_6_求N分之一序列前N项和
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            double sum = 0;
            for (double i = 1; i <= n; i++) sum += 1 / i;
            Console.WriteLine($"sum = {sum:f6}");
        }
    }
}
