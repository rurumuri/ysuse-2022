using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _7_3_兔子繁衍问题
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            long n1 = 1, n2 = 0, n3=0, sum = 1, count = 2;
            if (n <= 1)
                count = 1;
            while(n>1)
            {
                if(sum>=n)
                    break;
                else
                {
                    count++;
                    n3 = n1 + n2;
                    sum += n3;
                    n1 = n2;
                    n2 = n3;
                }
            }
            Console.WriteLine(count);
        }
    }
}
