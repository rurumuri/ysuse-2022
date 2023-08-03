using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1_7_求整数的位数及各位数字之和
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string inp =Console.ReadLine();
            double sum = 0;
            for(int i = 0; i < inp.Length; i++)
            {
                sum += (inp[i]-48);
            }
            Console.WriteLine($"{inp.Length} {sum}");
        }
    }
}
