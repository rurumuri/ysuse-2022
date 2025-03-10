using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1_15_查询水果价格
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("[1] apple\n[2] pear\n[3] orange\n[4] grape\n[0] exit");
            string[] arr = Console.ReadLine().Split(' ');
            int[] arrr=new int[arr.Length];
            int j = 0;
            foreach (string s in arr)
            {
                arrr[j]=int.Parse(s);
                j++;
            }
            int count = 0;
            for(int i=0; i<arrr.Length; i++)
            {
                switch (arrr[i])
                {
                    case 0:
                        count = 255;
                        break;
                    case 1:
                        Console.WriteLine("price = 3.00"); 
                        count++;
                        break;
                    case 2:
                        Console.WriteLine("price = 2.50");
                        count++;
                        break;
                    case 3:
                        Console.WriteLine("price = 4.10");
                        count++;
                        break;
                    case 4:
                        Console.WriteLine("price = 10.20");
                        count++;
                        break;
                    default:
                        Console.WriteLine("price = 0.00");
                        count++;
                        break;
                }
                if (count > 4)
                    break;
            }
        }
    }
}
