using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3_1_求最大值及其下标
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.ReadLine();
            int[] inp = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            int max = inp[0],index=0;
            for(int i = 1; i < inp.Length; i++)
            {
                if(inp[i] > max)
                {
                    max = inp[i];
                    index= i;
                }
            }
            Console.WriteLine($"{max} {index}");
        }
    }
}
