using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;


namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            for (int x = 0; x < n; x++)
            {
                string A = Console.ReadLine();
                bool Flag = true;
                for (int i = 0; i < A.Length; i++)
                {
                    if (A[i] != A[A.Length - 1 - i])
                    {
                        Flag = false;
                        break;
                    }
                }
                if (Flag)
                    Console.WriteLine("Yes");
                else Console.WriteLine("No");
            }
        }
    }
}