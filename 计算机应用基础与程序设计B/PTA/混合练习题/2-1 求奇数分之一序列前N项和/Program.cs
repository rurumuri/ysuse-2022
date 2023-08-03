using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2_1_求奇数分之一序列前N项和
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            double sum = 0;
            for(double i = 0; i < n; i++) sum += 1 / (2 * i + 1);
            Console.WriteLine($"sum = {sum:f6}");
        }
    }
}
