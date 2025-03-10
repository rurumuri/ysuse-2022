using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2_3_找出给定的_n_个数中的最大值_和n个数的和_
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.ReadLine();
            int[] arr = Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
            Array.Sort(arr);
            int sum = 0;
            for (int i = 0; i < arr.Length; i++)
                sum += arr[i];
            Console.WriteLine($"{arr[arr.Length-1]} {sum}");
        }
    }
}
