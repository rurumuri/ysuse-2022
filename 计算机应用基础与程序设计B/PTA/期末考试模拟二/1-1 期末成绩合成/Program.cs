using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1_1_期末成绩合成
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] sc;
            double s;
            int n;
            n = Convert.ToInt32(Console.ReadLine());
            for (int i = 0; i < n; i++)
            {
                sc = Array.ConvertAll(Console.ReadLine().Split(new char[] { ' ' }), int.Parse);//将三个成绩依次放到整型数组sc中

                s = Math.Round(0.4*sc[0] + 0.1*sc[1] + 0.5*sc[2],0);
                Console.WriteLine(s);
            }
        }
    }
}
