using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _7_3_统计学生平均成绩与及格人数
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int count = 0, sum = 0;
            double ave;
            string inp = Console.ReadLine();
            if (n==0)
            {
                ave = sum = 0;
            }
            else
            {
                string[] arr = inp.Split(' ');
                int[] arrr = new int[arr.Length];
                for (int i = 0; i < arrr.Length; i++)
                    arrr[i] = int.Parse(arr[i]);
                for (int i = 0; i < arrr.Length; i++)
                {
                    sum += arrr[i];
                    if (arrr[i] >= 60)
                        count++;
                }
                ave = (double)sum / n;
            }
            Console.WriteLine("average = {0:f1}\ncount = {1}",ave,count);
        }
    }
}
