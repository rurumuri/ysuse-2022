using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1_4_计算个人所得税//审题，你个砂滤！！！
{
    internal class Program
    {
        static void Main(string[] args)
        {
            double ori = double.Parse(Console.ReadLine());
            double tax = 0;
            if (ori > 1600) tax = 0.05 * (ori-1600);
            if (ori > 2500) tax = 0.1 * (ori-1600);
            if (ori > 3500) tax = 0.15 * (ori - 1600);
            if (ori > 4500) tax = 0.2 * (ori - 1600);
            Console.WriteLine($"{tax:f2}");
        }
    }
}
