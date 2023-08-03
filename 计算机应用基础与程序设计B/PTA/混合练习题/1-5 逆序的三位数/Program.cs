using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1_5_逆序的三位数
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string temp = "";
            while((temp=Console.ReadLine())!=null)
            {
                temp = String.Join("",temp.Reverse()); //？注意：不能以空字符连结        str.Reverse返回字符数组？？？    //另外这行挺有用，建议记住
                int t=int.Parse(temp);
                Console.WriteLine(t);
            }
        }
    }
}
