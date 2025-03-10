using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _7_12_sdut_循环_5_百钱买百鸡
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int i, j, k;
            for (i = 0; i < 100 / 5; i++)
            {
                for (j = 0; j < 100 / 3; j++)
                {
                    for (k = 0; k < 100; k++)
                    {
                        if (5 * i + 3 * j + k == 100 && i + j + 3 * k == 100)
                        {
                            string x = i.ToString().PadLeft(2, ' ');
                            string y = j.ToString().PadLeft(2, ' ');
                            string z = (3 * k).ToString().PadLeft(2, ' ');
                            Console.WriteLine($"公鸡{x}只，母鸡{y}只，小鸡{z}只");
                        }
                    }
                }
            }
        }
    }
}
