using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3_5_螺旋方阵
{
    internal class Program
    {
        static void Main(string[] args)
        {
            double n = double.Parse(Console.ReadLine());
            int[,] space = new int[(int)n, (int)n];
            double tx = 0, ty = 0, dx = 0, dy = 1;//依次为：当前x，当前y，变x，变y
            for (int i = 1; i < n * n + 1; i++)
            {
                if (space[(int)tx, (int)ty] != 0)//圈末错位
                {
                    tx += 1;
                    ty += 1;
                }
                space[(int)tx, (int)ty] = i;
                tx += dx;
                ty += dy;

                if (((n + 1) / 2 - tx - 1) * ((n + 1) / 2 - tx - 1) == ((n + 1) / 2 - ty - 1) * ((n + 1) / 2 - ty - 1))//对角线变向
                {
                    double temp = -dx;
                    dx = dy;
                    dy = temp;
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    Console.Write(space[i, j].ToString().PadLeft(3, ' '));
                }
                Console.WriteLine();
            }
            //int tx = 0, ty = 0, dx = 0, dy = 1, scale = n, countb = scale-1, countc=4;//依次为：当前x，当前y，变x，变y，当前圈规模，每行循环
            //for(int i = 0; i < ; i+=dx)
            //{
            //    for(int j=0; )
            //}

            //space[0, 0] = 1;
            //for (int i = 2; i < n * n + 1; i++)
            //{
            //    if (countc -1== 0&&countb-1==0)
            //    {
            //        scale -= 2;
            //        countc = 4;
            //        tx += 1;
            //        ty += 2;
            //        i++;
            //    }
            //    if (countb == 0)
            //    {
            //        int temp = -dx;
            //        dx = dy;
            //        dy = temp;
            //        countb = scale - 1;
            //        countc--;
            //    }
            //    tx += dx;
            //    ty += dy;
            //    space[tx, ty] = i;
            //    countb--;
            //}


            //for(int i = 2; i < n*n+1; i++)
            //{
            //    if (countc == 0)
            //    {
            //        countc = 3;
            //        scale -= 2;
            //        tx += 1;
            //        ty += 1;
            //    }
            //    tx += dx;
            //    ty += dy;
            //    space[tx, ty] = i;
            //    countb--;
            //    if(countb == 0)
            //    {
            //        int temp = -dx;
            //        dx = dy;
            //        dy = temp;
            //        countb = scale - 1;
            //        countc--;
            //    }
            //}

            //for(int i = 1; i <= n*n; i++,tx+=dx,ty+=dy)
            //{
            //    if (countb == 0)
            //    {
            //        if (countc == 0)
            //        {
            //            countc = 3;
            //            scale -= 2;
            //        }
            //        int temp = -dx;
            //        dx = dy;
            //        dy = temp;
            //        countb = scale - 1;
            //        countc--;
            //    }
            //    space[tx, ty] = i;
            //    countb--;
            //}
        }
    }
}
