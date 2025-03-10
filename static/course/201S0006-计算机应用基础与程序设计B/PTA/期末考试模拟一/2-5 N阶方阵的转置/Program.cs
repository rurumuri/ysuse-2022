using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2_5_N阶方阵的转置
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[,] arr = new int[n, n];
            for (int i = 0; i < n; i++)
            {
                int[] arrin = Array.ConvertAll(Console.ReadLine().Trim().Split(), int.Parse);
                for (int j = 0; j < n; j++)
                    arr[j,i] = arrin[j];
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    Console.Write($"{arr[i, j]}");
                    if (j != n - 1) Console.Write(" ");
                }
                Console.Write("\n");
            }

        }
    }
}
