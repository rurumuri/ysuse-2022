using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2_2_奇数偶数
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int input = Int32.Parse(Console.ReadLine());
            if (input % 2 == 0)
                Console.WriteLine("Even");
            if (input % 2 != 0)
                Console.WriteLine("Odd");
            Console.ReadLine();
        }
    }
}
