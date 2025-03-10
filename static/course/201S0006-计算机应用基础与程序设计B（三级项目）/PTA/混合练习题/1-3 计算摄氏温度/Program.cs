using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1_3_计算摄氏温度
{
    internal class Program
    {
        static void Main(string[] args)
        {
            double outp = 5.0 * (100 - 32) / 9.0;
            Console.WriteLine($"fahr = 100, celsius = {(int)outp}");
        }
    }
}
