using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2_2_求各位数字之和_
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string str = Console.ReadLine();
            int sum = 0;
            for(int i = 0;i<str.Length;i++)
                sum+= str[i]-48;
            Console.WriteLine(sum);
        }
    }
}
