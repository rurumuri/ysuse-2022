using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication3
{
    class Program
    {
        static void Main(string[] args)
        {
            long product =
1
;
            int n = int.Parse(Console.ReadLine());
            do
            {
                product =product * (n--);
            } while (
n > 1
);
            Console.WriteLine(product);
            Console.ReadKey();
        }
    }
}