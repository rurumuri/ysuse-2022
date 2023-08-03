using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace NumOfCharacter
{
    class Program
    {
        static void Main(string[] args)
        {
            string str =
Console.ReadLine()
;
            char[] charOne = str.ToCharArray();
            int count = 0;
            for (int i = 0; i <
 str.Length
 ; i++)
            {
                if (charOne[i] == 'y')
                 {
                    count++;
                }
            }
            Console.WriteLine(
count
);
            Console.ReadKey();
        }
    }
}