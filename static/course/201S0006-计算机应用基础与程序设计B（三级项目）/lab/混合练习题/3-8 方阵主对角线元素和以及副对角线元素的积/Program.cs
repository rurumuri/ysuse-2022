using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3_8_方阵主对角线元素和以及副对角线元素的积
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[,] arr = new int[5, 5];
            for(int i = 0; i < 5; i++)
            {
                int[] arrt = Array.ConvertAll(Console.ReadLine().Trim().Split(), int.Parse);
                for (int j = 0; j < 5; j++)
                    arr[i,j] = arrt[j];
            }

            int sum1 = 0, sum2 = 1;
            for(int i = 0; i < 5; i++)
                sum1+=arr[i,i];
            for(int i = 0; i < 5; i++)
                sum2*=arr[i,4-i];

            Console.WriteLine($"s={sum1},t={sum2}");
        }
    }
}
