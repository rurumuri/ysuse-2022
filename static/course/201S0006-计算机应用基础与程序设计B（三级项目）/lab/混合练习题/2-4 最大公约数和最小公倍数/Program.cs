using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2_4_最大公约数和最小公倍数
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] arrin = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            int x = arrin[0], y = arrin[1];
            for (int i = Math.Min(x, y); i > 0; i--)
            {
                if (x % i == 0 && y % i == 0)
                {
                    Console.Write($"{i} ");
                    break;
                }
            }
            for (int i = Math.Max(x, y); i > 0; i++)
            {
                if (i % x == 0 && i % y == 0)
                {
                    Console.Write($"{i} ");
                    break;
                }
            }
        }
    }
}
