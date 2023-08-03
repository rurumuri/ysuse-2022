using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1_2_输出闰年
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int pause = int.Parse(Console.ReadLine());
            if (pause < 2001 || pause > 2100)
                Console.WriteLine("Invalid year!");
            else
            {
                int count = 0;
                for (int i = 2001; i <= pause; i++)
                {
                    if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
                    {
                        Console.WriteLine(i);
                        count++;
                    }
                }
                if (count == 0) Console.WriteLine("None");
            }
        }
    }
}
