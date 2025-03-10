using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1_3_计算油费
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string[] input =Console.ReadLine().Split(' ');
            double plus =double.Parse(input[0]);
            int kind =int.Parse(input[1]);
            string service =input[2];
            double fee = 0;
            switch (kind)
            {
                case 90:
                    fee = plus * 6.95;
                    break;
                case 93:
                    fee = plus * 7.44;
                    break;
                case 97:
                    fee = plus * 7.93;
                    break;
            }
            switch(service)
            {
                case "m":
                    fee *= 0.95;
                    break;
                case "e":
                    fee *= 0.97;
                    break;
            }
            Console.WriteLine("{0:f2}",fee);
        }
    }
}
