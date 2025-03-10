using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1_7_求整数的位数及各位数字之和
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string inputo = Console.ReadLine();
            int n= inputo.Length;
            int sum = 0;
            for(int i= 0; i < n; i++)
            {
                sum += int.Parse(inputo[i].ToString());
            }
            Console.Write("{0} ",n);
            Console.Write(sum);       
        }
    }
}
