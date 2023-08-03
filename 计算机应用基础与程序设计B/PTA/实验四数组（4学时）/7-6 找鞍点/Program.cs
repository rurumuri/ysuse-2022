using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _7_6_找鞍点
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int x = int.Parse(Console.ReadLine());
            int[,] space = new int[x, x];
            for (int i = 0; i < x; i++)
            {
                string[] arr = Console.ReadLine().Split(' ');
                for (int j = 0; j < x; j++)
                    space[i, j] = int.Parse(arr[j]);
            }

            int havean = 0;
            for(int i = 0; i < x; i++)
            {
                int max = space[i,0], temp1 = 0,temp2=0,count=0;

                for (int j = 0; j < x; j++)
                {
                    if (space[i, j] >= max)
                    {
                        max = space[i, j];
                        temp1 = j;
                    }
                }


                for (int j=0; j < x; j++)
                {
                    if (space[j, temp1] < space[i,temp1])
                    {
                        count++;
                    }
                }

                if (count==0)
                {
                    havean++;
                    Console.WriteLine($"{i} {temp1}");
                }
            }

            if (havean == 0)
                Console.WriteLine("NONE");
        }
    }
}
