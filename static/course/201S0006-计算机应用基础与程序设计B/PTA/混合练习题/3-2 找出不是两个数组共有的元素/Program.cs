using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3_2_找出不是两个数组共有的元素
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string[] l1 = Console.ReadLine().Split();
            string[] l2 = Console.ReadLine().Split();
            for(int i = 1; i < l1.Length; i++)
            {
                string temp = l1[i];//麻烦在于：判断之后该项被抹掉，无法继续用于判断，所以需要缓存temp用于比较
                for(int j = 1; j < l2.Length; j++)//以第一列元素对照第二列，除第二列中的该元素
                {
                    if(temp == l2[j])
                    {
                        l1[i] = l2[j] = "x";
                    }
                }
                for (int k = i + 1; k < l1.Length; k++)//除去同列重复元素
                {
                    if (l1[k] == temp)
                    {
                        l1[k] = "x";
                    }
                }
            }
            ArrayList res =new ArrayList(); //存储，便于输出的同时 根据索引添加" "
            //for (int i = 1; i < l1.Length; i++)
            //{
            //    if (l1[i] != "x")
            //    {
            //        for (int k = i + 1; k < l1.Length; k++)
            //        {
            //            if (l1[k] == l1[i])
            //            {
            //                l1[k] = "x";
            //            }
            //        }
            //        res.Add(l1[i]);
            //    }
            //}
            for (int i = 1; i < l1.Length; i++)
            {
                //string temp = l1[i];
                //for (int k = i + 1; k < l1.Length; k++)
                //{
                //    if (l1[k] == temp)
                //    {
                //        l1[k] = "x";
                //    }
                //}                                                                //这里的部分前移了，为了和判断第二列时的元素接上，避免 1 1 1 和 1 1 1 2，得1 1 1，x x x 2，最后1仍然输出的问题。
                if (l1[i] != "x")
                {
                    res.Add(l1[i]);
                }
            }


            for (int i = 1; i < l2.Length; i++)
            {
                if (l2[i] != "x")
                {
                    for (int k = i + 1; k < l2.Length; k++)
                    {
                        if (l2[k] == l2[i])
                        {
                            l2[k] = "x";
                        }
                    }
                    res.Add(l2[i]);
                }
            }

            for(int i = 0; i < res.Count; i++)
            {
                Console.Write(res[i]);
                if (i != res.Count - 1)
                    Console.Write(" ");//事实证明\b非常不好用，在禁止多余空格的情况下，建议保存所有答案，逐个输出并选择性添加空格
            }
        }
    }
}
