using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Math;

namespace _2_9_到底是不是太胖了_单条数据_
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int h = int.Parse(input[0]);    //身高
            double w = double.Parse(input[1]);    //体重市斤
            double std = (h - 100) * 0.9;   //标准体重
            double delta = w/2 - std;
            if (-delta >= std * 0.1)
                Console.WriteLine("You are tai shou le!");
            else if (delta >= std * 0.1)
                Console.WriteLine("You are tai pang le!");
            else if (Abs(delta) < std * 0.1)
                Console.WriteLine("You are wan mei!");
        }
    }
}
