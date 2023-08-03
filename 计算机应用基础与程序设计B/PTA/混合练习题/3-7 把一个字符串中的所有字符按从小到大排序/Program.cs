using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3_7_把一个字符串中的所有字符按从小到大排序
{
    internal class Program
    {
        static void Main(string[] args)
        {
            char[] arr = Console.ReadLine().ToCharArray();
            Array.Sort(arr);
            for(int i = 0; i < arr.Length; i++)
                Console.Write(arr[i]);
            Console.WriteLine();
        }
    }
}
