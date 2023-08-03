using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _7_32_英文单词排序
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string[] str = new string[20];//给了上限，大大简化了问题难度orz 快谢谢老师
            int[] length =new int[20];

            string t;
            for (int i=0; ( t = Console.ReadLine()) != "#"; i++)
            {
                str[i] = t;
                length[i] = t.Length;
            }
            for(int i=1;i<10;i++)
            {
                for(int j=0;j<20;j++)
                {
                    if (i == length[j] )
                        Console.Write($"{str[j]} ");
                }
            }


        }
    }
}
