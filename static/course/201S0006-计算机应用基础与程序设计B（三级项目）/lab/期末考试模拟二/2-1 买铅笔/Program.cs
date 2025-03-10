using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2_1_买铅笔
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(Math.Ceiling(double.Parse(Console.ReadLine()) / double.Parse(Console.ReadLine())) * int.Parse(Console.ReadLine()));
        }
    }
}
