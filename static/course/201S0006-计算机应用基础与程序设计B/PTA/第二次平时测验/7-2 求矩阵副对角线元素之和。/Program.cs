using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _7_2_求矩阵副对角线元素之和_
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[,] arr = new int[4,4];
            for(int i=0;i<4;i++)
            {
                int[] arrr = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
                for (int j = 0; j < 4; j++)
                    arr[i,j] = arrr[j];
            }

            int sum = 0;
            for (int i = 0; i < 4; i++)
            {
                sum += arr[3 - i, i];
            }
            Console.WriteLine(sum);
        }
    }
}
