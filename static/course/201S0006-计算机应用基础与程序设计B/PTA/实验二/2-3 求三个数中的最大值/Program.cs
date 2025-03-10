using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2_3_求三个数中的最大值
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string[] input = (Console.ReadLine()).Replace("  "," ").Split(' ');
            int[] inputs = new int[input.Length];
            int t = 0;
            foreach (string inputItem in input)
            {
                inputs[t++] = int.Parse(inputItem);
            }
            Array.Sort(inputs);
            Console.WriteLine(inputs[input.Length-1]);
        }
    }
}
