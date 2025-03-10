using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2_4_创新学分计算
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine()),valid=n,sum=0;
            int[] arr = new int[n];
            for(int i=0; i<n; i++)
            {
                arr[i]=int.Parse(Console.ReadLine());
                sum += arr[i];
                if (arr[i] == 0) { valid--; }
            }
            for (int i = 0; i < n; i++)
            {
                if (arr[i] == 0) { Console.WriteLine(0); }
                else if (arr[i] <= sum / valid) { Console.WriteLine(1); }
                else if (arr[i] > sum / valid) { Console.WriteLine(2); }
            }
        }
    }
}
