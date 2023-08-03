using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2_3_求奇数和
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] inp = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            int sum = 0;
            for(int i = 0; i < inp.Length && inp[i]>0; i++)
            {
                if (inp[i]%2!=0) sum += inp[i];
            }
            Console.WriteLine(sum);
        }
    }
}
