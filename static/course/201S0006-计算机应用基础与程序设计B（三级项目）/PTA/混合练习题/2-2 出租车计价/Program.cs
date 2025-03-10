using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2_2_出租车计价
{
    internal class Program
    {
        static void Main(string[] args)
        {
            double[] arrin = Array.ConvertAll(Console.ReadLine().Split(), double.Parse);
            double x = arrin[0], y = arrin[1], sum = 10;
            if(x>0)
            {
                if (x > 10)
                {
                    sum += (x - 10) * 3;
                    x = 10;
                }
                if (x > 3)
                    sum += (x - 3) * 2;
            }
            if (x == 0) sum = 0;
            if (y > 5) sum += 2 * (y / 5);
            Console.WriteLine($"{sum:f0}");
        }
    }
}
