using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2_2_优惠购物
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string rank = Console.ReadLine();
            int b = int.Parse(Console.ReadLine());
            switch(rank)
            {
                case "P":
                    {
                        Console.WriteLine((b * 0.7).ToString("#0.00"));
                        break;
                    }
                case "G":
                    {
                        Console.WriteLine((b * 0.8).ToString("#0.00"));
                        break;
                    }
                case "S":
                    {
                        Console.WriteLine((b * 0.9).ToString("#0.00"));
                        break;
                    }
                default:
                    {
                        Console.WriteLine((b * 0.95).ToString("#0.00"));
                        break;
                    }
            }
        }
    }
}
