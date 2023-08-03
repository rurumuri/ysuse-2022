using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication2
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            for (int i = 1; i <= N;
i++
)
            {
                if (i % 9 != 0)
                {

                    Console.Write("");
                }
                else
                {
                    Console.Write("{0} ", i);
                }
            }
            Console.ReadKey();
        }
    }
}