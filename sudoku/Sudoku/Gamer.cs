using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net.Sockets;
using System.Security.Policy;
using System.Text;
using System.Threading.Tasks;
using static Sudoku.Game;

namespace Sudoku
{
    public class Gamer
    {
        public static string[] nowGamer;
        public static int NumofGamer;

        public int GamerIndex;
        public string GamerName;
        public int totalmark;
        public int[] gameProgress;
        public GameMode lastTimeGameMode;
        public int[,] lastTimeGameSpace;

        public Gamer(string gamerName)
        {
            GamerName = gamerName;
            GamerIndex = NumofGamer;
            NumofGamer++;
            totalmark = 0;
            gameProgress = new int[] { 0, 0, 0 };
            //if (Form1.gamer.GamerName!=null)
            //{
            //    string[] temp = User.ReadUserGameData(Form1.gamer.GamerName);
            //}
            lastTimeGameSpace = new int[9, 9];
            GamerName = gamerName;

            //FileStream readgamer = new FileStream($"..\\..\\Resources\\GamerList.txt", FileMode.Open, FileAccess.Read); //以下：读取当前存在的用户列表
            //StreamReader srLine = new StreamReader(readgamer);
            //nowGamer = srLine.ReadLine().Trim().Split(' ');
            //srLine.Close();//注意关闭流
        }


        public void SaveGameProgress(int[,] nowspace, GameMode gameMode)
        {


            lastTimeGameMode = gameMode;
            StringBuilder ltg_str = new StringBuilder();

            for (int i = 0; i < 9; i++)//遍历记录当前棋盘，即使游戏尚未完成
            {
                for (int j = 0; j < 9; j++)
                {
                    lastTimeGameSpace[i, j] = nowspace[i, j];
                    ltg_str.Append(nowspace[i, j]);
                }
            }

            FileStream fs;
            if (!File.Exists($"..\\..\\Resources\\GamerData\\{GamerName}.txt"))//若用户不存在则创建文件 并录入
            {
                fs = new FileStream($"..\\..\\Resources\\GamerData\\{GamerName}.txt", FileMode.Create, FileAccess.Write);
            }
            else
            {
                fs = new FileStream($"..\\..\\Resources\\GamerData\\{GamerName}.txt", FileMode.Open, FileAccess.Write);
            }
            StreamWriter sw = new StreamWriter(fs);
            sw.WriteLine($"{gameProgress[0]} {gameProgress[1]} {gameProgress[2]} {lastTimeGameMode} {ltg_str} {Form1.frm1.game.operatetime} {totalmark}\n",true);
            sw.Flush();
            sw.Close();
        }

        public void ReadGameProgress()
        {

        }

        public static bool IfGamerExist(string gamerNameJudge)//检测重名 *静态方法（类方法）注意/否则提示对象引用对于非静态的xx是必要的*
        {
            bool flag = false;
            if(nowGamer!=null)//前提用户不为空
            {
                for (int i = 0; i < nowGamer.Length; i++)
                {
                    if (nowGamer[i] == gamerNameJudge) { flag = true; break; }
                }
            }
            return flag;
        }
    }

}
