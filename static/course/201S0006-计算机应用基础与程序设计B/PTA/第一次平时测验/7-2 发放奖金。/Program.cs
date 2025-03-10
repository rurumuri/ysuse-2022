using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//10 20 40 60 100
//0.1 0.075 0.05 0.03 0.01
namespace _7_2_发放奖金_
{
    internal class Program
    {
        static void Main(string[] args)
        {
            double sum=0,i = double.Parse(Console.ReadLine());
            if(i>100)
            {
                sum += (i - 100) * 0.01;
                i = 100;
            }
            if (i > 60)
            {
                sum += (i - 60) * 0.015;
                i = 60;
            }
            if (i > 40)
            {
                sum += (i - 40) * 0.03;
                i = 40;
            }
            if (i > 20)
            {
                sum += (i - 20) * 0.05;
                i = 20;
            }
            if (i > 10)
            {
                sum += (i - 10) * 0.075;
                i = 10;
            }
            sum += i * 0.1;
            Console.WriteLine("{0:f6}",sum);
        }
    }
}
