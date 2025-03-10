using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _4_4_猴子选大王
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] arr = new int[1000];
            int n = int.Parse(Console.ReadLine());
            for (int i = 0,count=1; i < n - 1; i++,count++)
            {
                if (count ==3)
                {
                    arr[i] = 1;
                    count = 0;
                }
                if (arr[i] != 1)
                    count++;
            }
            for (int i = 0, count = 1; i < n - 1; i++, count++)
            {
                if (count == 3 && arr[i] != 1)
                {
                    arr[i] = 1;
                    count = 0;
                }
            }
            for (int i = 0; i < n-1; i++)
            {
                Console.WriteLine(arr[i]);
            }
        }
    }
}
