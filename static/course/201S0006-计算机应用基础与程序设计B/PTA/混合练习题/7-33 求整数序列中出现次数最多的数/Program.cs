using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _7_33_求整数序列中出现次数最多的数
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] ori = Array.ConvertAll(Console.ReadLine().Trim().Split(), int.Parse);//你知道啥叫审题🐎？
            Array.Sort(ori);

            int thisn = ori[1], themostn = ori[1], countt = 0, countmax = 0;//猜猜你为啥把3个0改成了3个1 usbsbsbsbsbsbsb
            for (int i = 1; i < ori.Length; i++)
            {
                if (ori[i] == thisn)
                {
                    countt++;
                }
                if (ori[i] != thisn||i==ori.Length-1)
                {
                    if (countt > countmax)
                    {
                        countmax = countt;
                        themostn = thisn;
                    }
                    thisn = ori[i];
                    countt = 1;
                }
            }
            if (countmax == 0)
            {
                countmax = countt;
                themostn = thisn;
            }
            Console.WriteLine($"{themostn} {countmax}");

        }
    }
}
