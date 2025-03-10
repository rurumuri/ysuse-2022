using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3_6_IP地址转换
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string str = Console.ReadLine();
            int temp = 0;
            for(int i = 7,index=0;index<32; i--,index++)
            {
                temp += (int)Math.Pow(2, i) * (str[index]-48);
                if(i<=0)
                {
                    Console.Write($"{temp}");
                    i = 8;
                    temp = 0;
                    if (index != 31)
                        Console.Write(".");
                }//注意\b不好使注意\b不好使注意\b不好使注意\b不好使注意\b不好使注意\b不好使注意\b不好使注意\b不好使注意\b不好使注意\b不好使注意\b不好使注意\b不好使注意\b不好使注意\b不好使注意\b不好使注意\b不好使注意\b不好使注意\b不好使注意\b不好使注意\b不好使注意\b不好使
            }
            Console.WriteLine();
        }
    }
}
