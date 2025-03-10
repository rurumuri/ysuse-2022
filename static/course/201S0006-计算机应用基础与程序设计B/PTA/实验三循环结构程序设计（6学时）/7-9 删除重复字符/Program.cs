using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace _7_9_删除重复字符
{
    internal class Program
    {
        static void Main(string[] args)
        {
            char[] arr = Console.ReadLine().ToCharArray();
            Array.Sort(arr);
            StringBuilder sb = new StringBuilder();
            sb.Append(arr[0]);
            for (int i = 1; i < arr.Length; i++)
            {
                char temp = arr[i - 1];
                if (arr[i] != temp)
                {
                    sb.Append(arr[i]);
                }
            }
            Console.WriteLine(sb.ToString());
        }
    }
}
