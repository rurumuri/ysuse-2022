using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Principal;
using System.Text;
using System.Threading.Tasks;

namespace Sudoku
{
    public class Game//游戏 类：每个游戏关卡的类，而非一个玩家的总游戏进度类
    {
        public enum GameMode { Easy,Medium,Hard};//枚举游戏模式
        //public GameMode gameMode;//游戏模式
        public int[,] gamespace,ans;//定义当前局游戏题干棋盘和当前局答案
        //public int gameProgress;//定义游戏状态 进度
        public int toDo;//空格数量
        public int operatetime;//一局中玩家操作次数
        public double operateweight;//难度对应的一次操作的权重
        public int mark;//本局分数

        public Game(GameMode gamemode ,string gamepath,string gamerName="")//构造函数，从指定地址的游戏txt文件加载
        {
            gamespace = new int[9, 9];
            ans = new int[9, 9];
            operatetime = 0;
            StreamReader sr = new StreamReader(gamepath);//读取
            for (int i = 0; i < 9; i++)//读取题目部分
            {
                int[] line = Array.ConvertAll(sr.ReadLine().Split(), int.Parse);
                for (int j = 0; j < 9; j++)
                {
                    gamespace[i, j] = line[j];
                    if (line[j] == 0) { toDo++; }
                }
            }
            for (int i = 0; i < 9; i++)//读取答案部分
            {
                int[] line = Array.ConvertAll(sr.ReadLine().Split(), int.Parse);
                for (int j = 0; j < 9; j++)
                {
                    ans[i, j] = line[j];
                }
            }
            sr.Close();

            //if (gamerName != "")
            //{
            //    string[] gamerDataTemp = User.ReadUserGameData(gamerName);
            //    operatetime = int.Parse(gamerDataTemp[5]);
            //    string temp = gamerDataTemp[4];
            //    gamemode = (Game.GameMode)Enum.Parse(typeof(Game.GameMode), gamerDataTemp[3]);
            //    for (int i = 0; i < 9; i++)//读取题目部分
            //    {
            //        for (int j = 0; j < 9; j++)
            //        {
            //            gamespace[i, j] = temp[9 * i + j];
            //            if (temp[9 * i + j] == 0) { toDo++; }
            //        }
            //    }
            //}

            if (gamemode == GameMode.Easy) { mark = 100; operateweight = 0.55; }
            if (gamemode == GameMode.Medium) { mark = 300; operateweight = 0.75; }
            if (gamemode == GameMode.Hard) { mark = 500; operateweight = 1; }
        }

        public bool Win(int operateTime,int timeUsage=0)//判断当前局是否完全正确 以及结算分数
        {
            int ceiling = mark;
            mark += toDo;
            mark -= (int)(operateTime * operateweight);
            if (mark > ceiling) { mark= ceiling; }

            bool res = true;
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    if (ans[i, j] != gamespace[i,j]) { res = false; break; }
                }
            }
            Form1.gamer.totalmark += mark;
            return res;
        }
    }
}
