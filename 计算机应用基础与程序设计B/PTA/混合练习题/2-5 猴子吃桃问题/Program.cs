using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2_5_猴子吃桃问题
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int days = int.Parse(Console.ReadLine()),n=1;
            for (int i = 0; i < days - 1; i++) n = 2 * (n + 1);
            Console.WriteLine(n);
        }
    }
}
