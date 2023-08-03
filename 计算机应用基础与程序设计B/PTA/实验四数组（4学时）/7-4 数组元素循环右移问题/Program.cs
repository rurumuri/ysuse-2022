using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _7_4_数组元素循环右移问题
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string[] meta = Console.ReadLine().Split(' ');
            int n = int.Parse(meta[0]);
            int d = int.Parse(meta[1]);
            if(d>=n)
            {
                d = d % n;
            }
            string[] arr = Console.ReadLine().Split(' ');
            int[] arrr = new int[arr.Length];
            for (int i = 0; i < arrr.Length; i++)
                arrr[i] = int.Parse(arr[i]);
            for(int i = 0; i < d; i++)
                Console.Write($"{arrr[n - d + i]} ");
            for(int i = 0; i < n-d; i++)
            {
                Console.Write($"{arrr[i]}");
                if (i != n - d-1)
                    Console.Write(" ");
            }
        }
    }
}
