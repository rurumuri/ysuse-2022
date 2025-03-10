using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _7_10_字符排队
{
    internal class Program
    {
        static void Main(string[] args)
        {
            char[] arr = Console.ReadLine().ToCharArray();//读取输入字符串并转化为字符数组
            Array.Sort(arr);//偷的
            string.Concat(arr);//把字符数组本身连接成字符串
            Console.WriteLine(arr);
        }

        static void Main2(string[] args)//正规方法
        {
            char[] arr = Console.ReadLine().ToCharArray();//读取输入字符串并转化为字符数组
            StringBuilder res = new StringBuilder();//创建可变字符串，存每次取的值
            for (int i = 0; i < arr.Length; i++)//有n个字符，就得找n回最小值 并 取走
            {
                char min = (char)127;//从小到大排，设初始值为ascii码中最大值  并显式转化为char类型
                int temp = 0;//缓存

                for (int j = 0; j < arr.Length; j++) //一次循环中挨个跟最大值比
                {
                    if (arr[j] <= min)//如果比它小，就让它成为新的最小值
                    {
                        min = arr[j];
                        temp = j;//缓存一次循环中最小的值的索引
                    }
                }

                res.Append(min);//存入结果
                arr[temp] = (char)127;//把这一轮中最小的值改成最大的，那么之后新的循环里，再找最小值时就不会重复找到它了 （相当于把它“取走”了）
            }
            Console.WriteLine(res);
        }
    }
}


