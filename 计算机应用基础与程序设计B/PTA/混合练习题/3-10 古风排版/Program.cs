using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3_10_古风排版
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int n =int.Parse(Console.ReadLine());//读入每竖排字符个数
            char[] arrin = Console.ReadLine().ToCharArray();//读入所有字符
            int line = (int)Math.Ceiling((double)arrin.Length/n);//计算容纳字符串所需的横排个数
            char[,] arr = new char[n,line];//建立“容器”

            for (int j = line-1,c=0; j >= 0; j--)//输入容器，先逐排后逐列（所以外循环为列），从右向左列大始
            {
                for(int i = 0; i < n; i++,c++)//c作为即将输入的字符索引
                {
                    if(c < arrin.Length)//验证索引值有效
                        arr[i, j] = arrin[c];
                    else//超过索引，下面开始为第一列最后的空白，！！！小心！！！字符数组初始化为空，什么都不输出，要逐个改' '(这也是下面输出错位的原因)
                        arr[i,j] = ' ';
                }
            }

            for(int i = 0; i < n; i++)//输出
            {
                for(int j = 0; j<line;j++)
                    Console.Write(arr[i,j]);
                Console.Write("\n");
            }
        }
    }
}
