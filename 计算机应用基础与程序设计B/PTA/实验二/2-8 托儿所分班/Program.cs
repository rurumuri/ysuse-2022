using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2_8_托儿所分班
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int age =int.Parse(Console.ReadLine());
            string c="";
            switch (age)
            {
                case 2:
                case 3:
                    c = "Lower class";
                    Console.WriteLine($"age {age},enter {c}.");
                    break;
                case 4:
                    c = "Middle class";
                    Console.WriteLine($"age {age},enter {c}.");
                    break;
                case 5:
                case 6:
                    c = "Higher class";
                    Console.WriteLine($"age {age},enter {c}.");
                    break;
                default:
                    Console.WriteLine("Error.");
                    break;
            }
        }
    }
}
