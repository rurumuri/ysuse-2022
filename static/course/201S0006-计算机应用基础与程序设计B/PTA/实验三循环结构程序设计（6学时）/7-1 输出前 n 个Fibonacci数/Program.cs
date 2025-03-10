using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _7_1_输出前_n_个Fibonacci数
{
    internal class Program
    {
        static void Main(string[] args)
        {
            long inp = long.Parse(Console.ReadLine());
            if (inp < 1)
            {
                Console.WriteLine("Invalid.");
            }
            else
            {
                long cnt = 0;
                long n1 = 1, n2 = 1, n3 = 0;
                Console.Write("          1");
                cnt++;
                if (inp >= 2)
                {
                    Console.Write("          1");
                    cnt++;
                }
                if (inp == 1 || inp == 2)
                {
                    Console.WriteLine();
                }
                for (long i = 2; i < inp; i++)
                {
                    n3 = n1 + n2;
                    n1 = n2;
                    n2 = n3;
                    Console.Write(n3.ToString().PadLeft(11, ' '));
                    cnt++;
                    if (cnt == 5 || i + 1 == inp)
                    {
                        Console.Write("\n");
                        cnt = 0;
                    }
                }
            }
        }
    }
}
