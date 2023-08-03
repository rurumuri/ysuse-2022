using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _7_11_猴子吃桃问题
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine()),p=1;
            for(int i = 0; i < n-1; i++)
            {
                p = 2 * (p + 1);
            }
            Console.WriteLine(p);
        }
    }
}
