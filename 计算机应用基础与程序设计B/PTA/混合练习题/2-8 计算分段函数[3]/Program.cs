using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2_8_计算分段函数_3_
{
    internal class Program
    {
        static void Main(string[] args)
        {
            double x = double.Parse(Console.ReadLine()),fx=0;
            if (x == 10)
                fx = 0.1;
            else
                fx = x;
            Console.WriteLine($"f({x:f1}) = {fx:f1}");
        }
    }
}
