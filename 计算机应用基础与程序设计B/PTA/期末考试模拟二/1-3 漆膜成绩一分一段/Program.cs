using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1_3_漆膜成绩一分一段
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int n, score = 0, rank;
            n =
int.Parse(Console.ReadLine())
;//读入人数
            int[] grades = new int[101];//存储每个分数的人数
            for (int i = 0; i < 101; i++)
            {
                grades[i] =
0
;//为数组元素指定初始值
            }
            for (int i = 0; i < n; i++)
            {
                score = Convert.ToInt32(Console.ReadLine());
                grades[score] =
grades[score] + 1
;
            }
            rank = 0;//存储累计人数
            Console.WriteLine("分数\t人数\t累计人数");
            for (int i = 100; i >= 0; i--)
            {
                if (grades[i] != 0)
                {
                    rank =
rank + grades[i]
;
                    Console.WriteLine("{0}\t{1}\t{2}", i, grades[i], rank);
                }
            }
        }
    }
}
