using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1_9_厘米换算英尺英寸
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int cm = int.Parse(Console.ReadLine());
            double foot = cm / 30.48;
            int fooot = (int)foot;

            double inch = (foot - fooot) * 12;


            int f = (int)foot;
            int i = (int)inch;
            Console.WriteLine("{0} {1}", f, i);
            Console.ReadLine();
        }
    }
}
