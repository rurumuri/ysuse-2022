using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1_2_字符三角形
{
    internal class Program
    {
        static void Main(string[] args)
        {
            char ch;
            string str = Console.ReadLine();
            ch = str[0];
            int n = Convert.ToInt32(Console.ReadLine());
            for (int i = 1; i <= n; i++)
            {
                for (int j = 0; j <
n - i
; j++)
                    Console.Write(' ');
                for (int j = 0;
j < i
; j++)
                    Console.Write("{0}", ch);
                Console.WriteLine();
            }
            }
    }
}
