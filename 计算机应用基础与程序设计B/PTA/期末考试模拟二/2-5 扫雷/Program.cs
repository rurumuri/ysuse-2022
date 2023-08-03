using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2_5_扫雷
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] arr = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            int[,] space = new int[arr[0]+2, arr[1]+2];//新思路：建一个比它大一圈的，规避边界问题（注意后续对应的更改）

            for (int i = 1; i < arr[0]+1; i++)
            {
                int[] arrin = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
                for (int j = 1; j < arr[1]+1; j++)
                    space[i, j] = arrin[j-1];
            }

            int[] tar = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            if (space[tar[0], tar[1]] == 1) { Console.WriteLine("B"); }
            else
            {
                int b = 0;
                for (int i = tar[0] - 1; i < tar[0] + 2; i++)
                {
                    for (int j = tar[1] - 1; j < tar[1] + 2; j++)
                    {
                        if (space[i, j] == 1) { b++; }
                    }
                }
                Console.WriteLine(b);
            }


        }
    }
}
