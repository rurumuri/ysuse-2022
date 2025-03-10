using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2_4_求矩阵周边元素的和
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] arr = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            int[,] space = new int[arr[0], arr[1]];
            for(int i = 0;i< arr[0];i++)
            {
                int[] arrin = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
                for (int j = 0; j < arr[1]; j++)
                    space[i,j] = arrin[j];
            }

            int sum = 0;
            for (int i = 0; i < arr[0]; i++)
                for (int j = 0; j < arr[1]; j++)
                    if (i == 0 || i == arr[0] - 1 || j == 0 || j == arr[1]-1)
                        sum+=space[i,j];
            Console.WriteLine(sum);
        }
    }
}
