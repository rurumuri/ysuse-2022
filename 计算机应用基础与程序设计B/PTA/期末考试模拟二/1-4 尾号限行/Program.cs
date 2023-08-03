using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1_4_尾号限行
{
    internal class Program
    {
        static void Main(string[] args)
        {
            DateTime d1;
            string cardNum = "", strResult = "";
            int n = Convert.ToInt32(Console.ReadLine());
            for (int count = 0; count < n; count++)
            {
                string[] sa = Console.ReadLine().Split(new char[] { ' ' });
                d1 = Convert.ToDateTime(sa[0]);//日期
                int[,] FibidDay = { { 4, 9 }, { 5, 0 }, { 1, 6 }, { 2, 7 }, { 3, 8 } };
                //将星期1至星期5限行的尾号存入二维数组，每天占1行
                int dayofWeek = (int)d1.DayOfWeek - 1;
                //得到星期几存入变量dayofWeek中，星期日用-1表示，星期一用0表示，星期二用1表示......，星期六用5表示 
                cardNum = sa[1];//车牌号
                strResult = "";
                int tailNum;
                if (
dayofWeek == 5 || dayofWeek == 6
)//5：周六；-1周日，不限行
                    strResult = "Permit";
                else if (
cardNum.Length > 5
)//新能源汽车不限行
                    strResult = "Permit";
                else
                {
                    int i =
cardNum.Length - 1
;
                    while (cardNum[i] < '0' || cardNum[i] > '9')
                        i--;
                    tailNum = cardNum[i] - '0';
                    if (tailNum==FibidDay[dayofWeek,0]|| tailNum == FibidDay[dayofWeek, 1]
)
                        strResult = "Forbid";
                    else
                        strResult = "Permit";
                }
                Console.WriteLine(strResult);
            }
        }
    }
}
