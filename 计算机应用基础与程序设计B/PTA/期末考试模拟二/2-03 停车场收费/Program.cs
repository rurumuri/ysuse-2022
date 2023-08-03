using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2_03_停车场收费
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] inp = Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
            int time = inp[2] * 60 + inp[3] - inp[0] * 60 - inp[1];
            int fee = 0;
            if(time<0) { time += 1440; }
            if(time>20)
            {
                fee = (int)Math.Ceiling(time / 60.0)*3;
            }
            if(fee>40) { fee = 40; }
            Console.WriteLine(fee);
        }
    }
}
