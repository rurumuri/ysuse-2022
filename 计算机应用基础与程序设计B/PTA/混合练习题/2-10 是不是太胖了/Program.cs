using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2_10_是不是太胖了
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine($"{(double.Parse(Console.ReadLine()) - 100) * 0.9 * 2:f1}");
        }
    }
}
