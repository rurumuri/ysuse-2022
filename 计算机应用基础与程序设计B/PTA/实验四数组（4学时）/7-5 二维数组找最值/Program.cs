using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _7_5_二维数组找最值
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string[] meta = Console.ReadLine().Split(' ');
            int x = int.Parse(meta[0]);
            int y = int.Parse(meta[1]);
            int[,] space = new int[x, y];
            for(int i = 0; i < x; i++)
            {
                string[] arr = Console.ReadLine().Split(' ');
                for (int j = 0; j < y; j++)
                    space[i,j] = int.Parse(arr[j]);
            }
            int max = space[0, 0];
            int a=0, b=0;
            for(int i = 0; i < x; i++)
            {
                for(int j = 0; j < y; j++)
                {
                    if (space[i,j]>=max)
                    {
                        a = i;
                        b = j;
                        max = space[i, j];
                    }
                }
            }
            Console.WriteLine($"{max},{a},{b}");
        }
    }
}
