using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1_8_分段计算居民水费
{
    internal class Program
    {
        static void Main(string[] args)
        {
            double inp = double.Parse(Console.ReadLine());
            double outp = 0;
            if (inp <= 15)
                outp = (4.0 * inp) / 3.0;
            if(inp>15)
                outp = 2.5 * inp - 17.5;
            Console.WriteLine($"{outp:f2}");
        }
    }
}
