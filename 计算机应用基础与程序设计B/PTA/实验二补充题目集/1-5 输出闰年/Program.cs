using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1_5_输出闰年
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int year = int.Parse(Console.ReadLine());
            if(year<=2000||year>3000)
            {
                Console.WriteLine("Invalid year!");
            }
            else
            {
                int count = 0;
                for(int i=2001;i<3000;i++)
                {
                    if(i%4==0&&i%100!=0&&i<=year)
                    {
                        count++;
                        Console.WriteLine(i);
                    }
                }
                if (count == 0)
                    Console.WriteLine("None");
            }
        }
    }
}
