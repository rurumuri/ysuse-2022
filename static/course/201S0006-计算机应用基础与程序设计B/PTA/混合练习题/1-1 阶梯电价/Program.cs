using System;
using System.Collections.Generic;
using System.Diagnostics.CodeAnalysis;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace _1_1_阶梯电价
{
    internal class Program
    {
        static void Main(string[] args)
        {
            double d = double.Parse(Console.ReadLine()), cost = 0;
            if(d<0)
            {
                Console.WriteLine("Invalid Value!");
            }
            else
            {
                if(d>50)
                {
                    cost += (d-50) * 0.58;
                    d = 50;
                }
                cost += d * 0.53;
                if(cost!=0)
                {
                    Console.WriteLine("cost = {0:f2}", cost);
                }
            }
        }
    }
}
