using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _7_34_简化的插入排序
{
    internal class Program
    {
        static void Main(string[] args)
        {
            double n = double.Parse(Console.ReadLine()), count = 0;
            if (n != 0)
            {
                double[] arr = Array.ConvertAll(Console.ReadLine().Trim().Split(' '), double.Parse);
                double x = double.Parse(Console.ReadLine());
                for (int i = 0; i < arr.Length; i++)
                {
                    if (i == 0 && arr[i] >= x && count == 0)
                    {
                        Console.Write($"{x} ");
                        count++;
                    }
                    else if ((i != 0 && i != n - 1) && arr[i] >= x && arr[i - 1] <= x && count == 0)
                    {
                        Console.Write($"{x} ");
                        count++;
                    }
                    Console.Write($"{arr[i]} ");
                    if (i == n - 1 && arr[i] <= x && count == 0)
                    {
                        Console.Write($"{x} ");
                        count++;
                    }
                }
            }
            else
            {
                Console.ReadLine(); //第二行空白输入
                Console.Write(Console.ReadLine()+' '); //插入的元素
            }
        }
    }
}
