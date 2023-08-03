using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2_7_sdut_运输计费问题
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            double w = double.Parse(input[0]);
            double d = double.Parse(input[1]);
            double off=1;
            if (d < 250)
                off = 1;
            if (250 <= d && d<500)
                off = 0.98;
            if (500 <= d && d < 1000)
                off = 0.95;
            if (1000 <= d && d < 2000)
                off = 0.92;
            if (2000 <= d && d < 3000)
                off = 0.9;
            if (d >= 3000)
                off = 0.85;
            Console.WriteLine(Convert.ToInt32(w * d * off));
        }
    }
}
