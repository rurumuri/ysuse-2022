using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _7_1_求素数的个数
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] arr =Array.ConvertAll(Console.ReadLine().Split( ),int.Parse);
            int count = 0;
            for(int i=0;i<arr.Length;i++)
            {
                count += Su(arr[i]);
            }
            Console.WriteLine(count);
        }

        static int Su(int a)
        {
            int res = 0;
            if(a!=1)
            {
                res = 1;
                for (int i = 2; i < a; i++)
                {
                    if (a % i == 0) res= 0;
                }
            }
            if(a==2) res = 1;
            return res;
        }
    }
}
