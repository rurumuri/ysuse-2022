using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2_6_兔子繁衍问题//a1=0 a2=1 ...发现an=Sn-2,则an-1=Sn-3,作差得an=an-1+an-2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int tar = int.Parse(Console.ReadLine()),sum=1,a1=1,a2=0,at=0,count=2;
            while(sum<tar)
            {
                sum += (at = a1 + a2);
                count++;
                a1 = a2;
                a2 = at;
            }
            if (tar == 1) count = 1;
            Console.WriteLine(count);
        }
    }
}
