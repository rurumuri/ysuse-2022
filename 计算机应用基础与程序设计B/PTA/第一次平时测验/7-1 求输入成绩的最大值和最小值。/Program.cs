using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _7_1_求输入成绩的最大值和最小值_
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int max, min, temp;
            temp = int.Parse(Console.ReadLine());
            max = min = temp;
            for (int i = 0; i < 9; i++)
            {
                temp = int.Parse(Console.ReadLine());
                if (max<=temp)
                    max = temp;
                if(min>=temp)
                    min = temp;
            }
            Console.WriteLine($"{max} {min}");
        }
    }
}
