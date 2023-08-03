using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace 编程题
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine().Trim());
            int sum = 0;
            for (int i = 1;
i <= N
;
i += 2
)
            {

                sum += i
                ;
            }
            Console.WriteLine(sum);
            Console.ReadLine();
        }
    }
}