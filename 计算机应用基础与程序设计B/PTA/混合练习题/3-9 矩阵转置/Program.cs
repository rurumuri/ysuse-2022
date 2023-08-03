using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3_9_矩阵转置
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] inp = Array.ConvertAll(Console.ReadLine().Trim().Split(), int.Parse);
            int[,] arr = new int[3, 3];
            for(int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                    arr[j, i] = inp[3 * i + j];
            }
            for(int i = 0; i < 3; i++)
            {
                //for (int j = 0; j < 3; j++)
                //    string o = arr[i, j].ToString().PadLeft(4, ' ');    ???若加上{}则不会报错
                for (int j = 0; j < 3; j++)
                {
                    Console.Write(arr[i, j].ToString().PadLeft(4, ' '));
                    if ((3 * i + j + 1) % 3 == 0)
                        Console.Write('\n');
                }
            }
        }
    }
}
