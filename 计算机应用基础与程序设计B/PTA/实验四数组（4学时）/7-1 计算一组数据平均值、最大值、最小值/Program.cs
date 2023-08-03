using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _7_1_计算一组数据平均值_最大值_最小值
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string[] arr =Console.ReadLine().Split(' ');
            int[] arrr = new int[arr.Length];
            for(int i = 0; i < arrr.Length; i++)
                arrr[i] = int.Parse(arr[i]);
            Array.Sort(arrr);
            int sum = 0;
            for (int i = 0; i < arrr.Length; i++)
            {
                sum += arrr[i];
            }
            Console.WriteLine($"{sum/arrr.Length} {arrr[arrr.Length-1]} {arrr[0]}");
        }
    }
}
