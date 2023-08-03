using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Math;

namespace _7_4_最大公约数和最小公倍数
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string[] inp=Console.ReadLine().Split(' ');
            int a=int.Parse(inp[0]),b=int.Parse(inp[1]),x,y;
            for(int i=Math.Max(a,b); ;i--)
            {
                if (a % i == 0 && b % i == 0)
                {
                    x = i;
                    break;
                }
            }
            for (int i = Math.Max(a, b); ; i++)
            {
                if (i % a == 0 && i % b == 0)
                {
                    y = i;
                    break;
                }
            }
            Console.WriteLine($"{x} {y}");
        }
    }
}
