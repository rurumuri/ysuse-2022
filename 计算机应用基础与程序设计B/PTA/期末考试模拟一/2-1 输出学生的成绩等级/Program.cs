using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2_1_输出学生的成绩等级
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int mark = int.Parse(Console.ReadLine());
            if(mark >= 90 && mark<=100)
            {
                Console.WriteLine("A");
            }
            if (mark >= 80 && mark <= 89)
            {
                Console.WriteLine("B");
            }
            if (mark >= 70 && mark <= 79)
            {
                Console.WriteLine("C");
            }
            if (mark >= 60 && mark <= 69)
            {
                Console.WriteLine("D");
            }
            if (mark <60)
            {
                Console.WriteLine("F");
            }

        }
    }
}
