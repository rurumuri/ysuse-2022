using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2_6_判断能否被3_5_7整除
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int input = int.Parse(Console.ReadLine());
            if (input % 3 == 0 && input % 5 == 0 && input % 7 == 0)
                Console.Write("3 5 7");
            if (input % 3 != 0 && input % 5 != 0 && input % 7 != 0)
                //  Console.Write("n");  //草 是小写字符！！！！！！
                Console.Write('n');
            if (input % 3 != 0 && input % 5 == 0 && input % 7 == 0)
                Console.Write("5 7");
            if (input % 3 == 0 && input % 5 != 0 && input % 7 == 0)
                Console.Write("3 7");
            if (input % 3 == 0 && input % 5 == 0 && input % 7 != 0)
                Console.Write("3 5");
            if (input % 3 != 0 && input % 5 != 0 && input % 7 == 0)
                Console.Write("7");
            if (input % 3 != 0 && input % 5 == 0 && input % 7 != 0)
                Console.Write("5");
            //if (input % 3 == 0 && input % 5 != 0 && input % 7 == 0)
            if (input % 3 == 0 && input % 5 != 0 && input % 7 != 0)  //细心细心细心细心细心细心细心细心细心细心细心细心细心细心细心细心细心细心细心细心细心细心细心细心细心细心细心细心细心细心细心细心细心细心细心细心

                Console.Write("3");


            //bool a, b, c;
            //a = input % 3 == 0;
            //b = input % 5 == 0;
            //c = input % 7 == 0;
            //if (a)
            //    Console.Write("3 ");
            //if (b)
            //    Console.Write("5 ");
            //if (c)
            //    Console.Write("7");
            //if (!a &&!b &&!c)
            //    Console.Write('n');
        }
    }
}
