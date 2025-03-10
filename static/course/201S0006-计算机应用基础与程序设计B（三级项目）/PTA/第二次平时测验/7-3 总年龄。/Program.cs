using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _7_3_总年龄_
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[,] arr = new int[3, 4];
            for (int i = 0; i < 3; i++)
            {
                int[] arrr = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
                for (int j = 0; j < 4; j++)
                    arr[i, j] = arrr[j];
            }

            for (int i = 0; i < 4; i++)
            {
                int sum = 0;
                for (int j = 0; j < 3; j++)
                    sum+= arr[j,i];
                Console.WriteLine(sum);
            }

        }
    }
}
