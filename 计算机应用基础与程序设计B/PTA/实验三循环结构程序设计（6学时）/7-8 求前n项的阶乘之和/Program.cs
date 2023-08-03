using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _7_8_求前n项的阶乘之和
{
    internal class Program
    {
        static void Main(string[] args)
        {
            long n =long.Parse(Console.ReadLine());
            long sum = 0;
            for(long i = 0; i < n; i++)
            {
                sum += Jc(i+1);
            }
            Console.WriteLine(sum);
        }
        static long Jc(long i)
        {
            long j = 1;
            for(long j2 = 0; j2 < i; j2++)
            {
                j *= j2+1;
            }
            return j;
        }
    }
}
