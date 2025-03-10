using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3_3_求矩阵各行元素之和
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] inp = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            int[,] arr = new int[inp[0], inp[1]];
            for (int i = 0; i < inp[0]; i++)
            {
                int[] inn = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
                for (int j = 0; j < inp[1]; j++)
                    arr[i, j] = inn[j];
            }
            for (int i = 0; i < inp[0]; i++)
            {
                int sum = 0;
                for (int j = 0; j < inp[1]; j++)
                {
                    sum += arr[i, j];
                }
                Console.WriteLine(sum);
            }
        }
    }
}
