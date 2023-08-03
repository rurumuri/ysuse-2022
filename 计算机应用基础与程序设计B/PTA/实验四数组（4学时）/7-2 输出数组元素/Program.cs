using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _7_2_输出数组元素
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] arrr = Array.ConvertAll(Console.ReadLine().Trim().Split(' '), int.Parse);

            for (int i = 0; i < arrr.Length-1; i++)
            {
                Console.Write($"{arrr[i + 1] - arrr[i]}");
                if (i % 3 != 2 && i != arrr.Length - 2)
                    Console.Write(" ");
                if (i % 3 == 2)
                    Console.Write("\n");
            }
        }
    }
}
