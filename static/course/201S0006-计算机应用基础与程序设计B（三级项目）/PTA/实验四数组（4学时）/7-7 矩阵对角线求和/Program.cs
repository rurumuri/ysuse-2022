using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _7_7_矩阵对角线求和
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int x = int.Parse(Console.ReadLine());
            int[,] space = new int[x, x];
            for (int i = 0; i < x; i++)
            {
                string[] arr = Console.ReadLine().Split(' ');
                for (int j = 0; j < x; j++)
                    space[i, j] = int.Parse(arr[j]);
            }
            int sum = 0;
            for(int i = 0; i < x; i++)
            {
                sum+=space[i, i];
            }
            Console.WriteLine(sum);
        }
    }
}
