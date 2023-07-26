using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Security.Principal;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;
using System.IO;

namespace Sudoku
{
    public partial class Form1 : Form
    {
        public bool saved=false;
        public static CreateGamer createGamer = new CreateGamer();//新用户窗口 实例化
        User user;
        public static Gamer gamer;//定义Gamer 来承接实例化的gamer
        public Game game;//定义Game 来承接实例化的game
        static int sx;//定义光标坐标
        static int sy;
        public static int gameIndex;//定义游戏文件索引
        public Game.GameMode gameMode;//定义游戏模式

        public static Form1 frm1;//****非常重要：跨窗体调用函数
        public Form1()
        {
            InitializeComponent();
            frm1 = this;//****非常重要：跨窗体调用函数//没用明白this 和parent传递
        }


        private void Form1_Load(object sender, EventArgs e)//初始化
        {
            gameMode = Game.GameMode.Easy;
            gameIndex = 1;

            FileStream readgamer = new FileStream($"..\\..\\Resources\\GamerList.txt", FileMode.Open, FileAccess.Read); //以下：读取当前存在的用户列表
            StreamReader srLine = new StreamReader(readgamer);
            string temp = srLine.ReadLine();
            if (temp != null)//若空用户列表，不处理
            {
                Gamer.nowGamer = temp.Trim().Split(' ');
                Gamer.NumofGamer = Gamer.nowGamer.Length;
            }
            srLine.Close();//注意关闭流

            if (Gamer.NumofGamer == 0)//无玩家时新建
            {
                createGamer.Show();
            }
            else
            {
                user = new User();
                user.Show();
            }

            IniGame(gameMode, gameIndex.ToString());
        }


        #region//游戏
        private void 统计ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Statics statics = new Statics();
            statics.Show();
        }//统计

        private void toolStripMenuItem2_Click(object sender, EventArgs e)
        {
            User user = new User();
            user.Show();
        }//切换用户

        private void toolStripMenuItem_Click(object sender, EventArgs e)
        {
            tableLayoutPanel1.BackgroundImage = imageList1.Images[0];
            this.BackColor = Color.FromArgb(248, 248, 255);
            menuStrip1.BackColor = Color.FromArgb(230, 230, 250);
        }//主题切换1

        private void toolStripMenuItem3_Click(object sender, EventArgs e)
        {
            tableLayoutPanel1.BackgroundImage = imageList1.Images[3];
            this.BackColor = Color.FromArgb(236, 255, 236);
            menuStrip1.BackColor = Color.FromArgb(187, 217, 186);
        }//主题切换2

        private void 默认ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            tableLayoutPanel1.BackgroundImage = imageList1.Images[1];
            this.BackColor = Color.FromArgb(255, 236, 219);
            menuStrip1.BackColor = Color.FromArgb(255, 212, 167);
        }//主题切换3

        private void nahidaToolStripMenuItem_Click(object sender, EventArgs e)
        {
            tableLayoutPanel1.BackgroundImage = imageList1.Images[2];
            this.BackColor = Color.FromArgb(255, 242, 255);
            menuStrip1.BackColor = Color.FromArgb(255, 223, 251);
        }//主题切换4

        private void 退出ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }//退出

        private void 放弃ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            DialogResult res = MessageBox.Show("当前关卡的游戏进度将会丢失，\n你确定要放弃吗？", "放弃游戏", MessageBoxButtons.OKCancel, MessageBoxIcon.Question);
            if (res == DialogResult.OK)
            {
                IniGame(gameMode, gameIndex.ToString());
            }
        }//放弃

     #endregion

     #region//帮助
        private void toolStripMenuItem1_Click(object sender, EventArgs e)//帮助>提示
        {
            SaveSpace();
            int count = 0;
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    if (game.ans[i, j] != game.gamespace[i, j]) count++;
                }
            }
            MessageBox.Show($"还有{count}个正确数字待填写");
        }

        private void toolStripMenuItem5_Click(object sender, EventArgs e)
        {
            Rules rules = new Rules();
            rules.Show();
        }//帮助>规则

        private void 查看帮助ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start("explorer.exe", "https://baike.baidu.com/item/%E6%95%B0%E7%8B%AC/74847#4");
        }//跳转网页获取帮助

        private void 关于ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            About about = new About();
            about.Show();
        }//关于
        #endregion


        #region//流程控制
        public void SaveSpace()//保存当前格子状态到棋盘
        {
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    if (((Label)tableLayoutPanel1.Controls[9 * i + j]).Text != " ")
                    {
                        game.gamespace[i, j] = int.Parse(((Label)tableLayoutPanel1.Controls[9 * i + j]).Text);
                    }
                }
            }
        }

        public void IniGame(Game.GameMode gameMode, string gameIndex,string gamerName="")//初始化游戏
        {
            sx = 0;//重置光标
            sy = 0;
            tableLayoutPanel1.Controls.Clear();//清空棋盘所有元素

            button11.Enabled = true;
            button2.Enabled = false;
            button3.Enabled = false;
            if(gameIndex=="0")
            {
                gameIndex = "1";
            }
            game = new Game(gameMode, $"..\\..\\Resources\\{gameMode}\\({gameIndex}).txt");

            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    Label label = new Label();
                    label.Dock = DockStyle.Fill;
                    label.BackColor = Color.Transparent;
                    label.Font = new Font("微软雅黑", 14);
                    label.TextAlign = ContentAlignment.MiddleCenter;
                    if (game.gamespace[i, j] != 0)
                    {
                        label.Text = game.gamespace[i, j].ToString();
                        tableLayoutPanel1.Controls.Add(label);
                    }
                    else
                    {
                        label.Text = " ";
                        tableLayoutPanel1.Controls.Add(label);
                    }
                }
                ((Label)tableLayoutPanel1.Controls[9 * sy + sx]).BackColor = Color.FromArgb(128, 255, 255, 255);//初始化光标
            }

            game.operatetime = 0;
            if (gamerName != "")
            {
                string[] gamerDataTemp = User.ReadUserGameData(gamerName);
                game.operatetime = int.Parse(gamerDataTemp[5]);
                string temp = gamerDataTemp[4];
                this.gameMode = (Game.GameMode)Enum.Parse(typeof(Game.GameMode), gamerDataTemp[3]);
                for (int i = 0; i < 9; i++)//读取题目部分
                {
                    for (int j = 0; j < 9; j++)
                    {
                        if (game.gamespace[i, j] == 0)
                        {
                            game.gamespace[i, j] = temp[9 * i + j]-48;
                            tableLayoutPanel1.Controls[9 * i + j].Text = game.gamespace[i, j].ToString();
                            if (temp[9 * i + j] == 48) 
                            { 
                                game.toDo++;
                                tableLayoutPanel1.Controls[9 * i + j].Text = " ";
                            }
                            tableLayoutPanel1.Controls[9 * i + j].ForeColor = Color.Gray;
                        }
                    }
                }

            }
            label1.Text = $"操作次数：{game.operatetime}";//初始化操作次数显示
            label1.Enabled = false;//在游戏开始前不显示
            label2.Text = $"当前题目：{gameMode}-{gameIndex}";//指示当前题目


        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if(!saved)
            {
                DialogResult res = MessageBox.Show("所有未保存的游戏进度将会丢失，\n确定要结束吗？", "结束游戏", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning);
                if (res == DialogResult.Cancel)
                {
                    e.Cancel = true;
                }
            }
        }//关闭游戏前提醒保存

        private void Form1_KeyDown(object sender, KeyEventArgs e)//wsad控制光标 数字输入 菜单快捷键支持
        {
            if(!e.Alt)
            {
                saved=false;
                if (button11.Enabled == false)
                {
                    if (e.KeyCode == Keys.W)
                    {
                        if (sy != 0)
                        {
                            ((Label)tableLayoutPanel1.Controls[9 * sy + sx]).BackColor = Color.FromArgb(0, 0, 0, 0);
                            sy--;
                            ((Label)tableLayoutPanel1.Controls[9 * sy + sx]).BackColor = Color.FromArgb(128, 255, 255, 255);
                        }
                    }
                    if (e.KeyCode == Keys.S)
                    {
                        if (sy != 8)
                        {
                            ((Label)tableLayoutPanel1.Controls[9 * sy + sx]).BackColor = Color.FromArgb(0, 0, 0, 0);
                            sy++;
                            ((Label)tableLayoutPanel1.Controls[9 * sy + sx]).BackColor = Color.FromArgb(128, 255, 255, 255);
                        }
                    }
                    if (e.KeyCode == Keys.A)
                    {
                        if (sx != 0)
                        {
                            ((Label)tableLayoutPanel1.Controls[9 * sy + sx]).BackColor = Color.FromArgb(0, 0, 0, 0);
                            sx--;
                            ((Label)tableLayoutPanel1.Controls[9 * sy + sx]).BackColor = Color.FromArgb(128, 255, 255, 255);
                        }
                    }
                    if (e.KeyCode == Keys.D)
                    {
                        if (sx != 8)
                        {
                            ((Label)tableLayoutPanel1.Controls[9 * sy + sx]).BackColor = Color.FromArgb(0, 0, 0, 0);
                            sx++;
                            ((Label)tableLayoutPanel1.Controls[9 * sy + sx]).BackColor = Color.FromArgb(128, 255, 255, 255);
                        }
                    }
                    if (e.KeyCode >= Keys.NumPad1 && e.KeyCode <= Keys.NumPad9 && (((Label)tableLayoutPanel1.Controls[9 * sy + sx]).Text == " " || ((Label)tableLayoutPanel1.Controls[9 * sy + sx]).ForeColor == Color.Gray))
                    {
                        ((Label)tableLayoutPanel1.Controls[9 * sy + sx]).ForeColor = Color.Gray;
                        ((Label)tableLayoutPanel1.Controls[9 * sy + sx]).Text = (e.KeyValue - 96).ToString();
                        game.operatetime++;
                        label1.Text = $"操作次数：{game.operatetime}";
                    }
                }
                else
                {
                    MessageBox.Show("请先开始游戏");
                }

            }
        }

        private void button2_Click(object sender, EventArgs e)//按钮 提交
        {
            SaveSpace();
            if (game.Win(game.operatetime))
            {
                label2.Text += " ✓";
                MessageBox.Show($"正确的！                            \n\n操作数：{game.operatetime}\n得分：{game.mark}","恭喜");
                if (gameMode == Game.GameMode.Easy && gameIndex == 10)
                {
                    MessageBox.Show("恭喜你完成了初级难度的全部试炼！", "恭喜");
                }
                if (gameMode == Game.GameMode.Medium && gameIndex == 6)
                {
                    MessageBox.Show("恭喜你完成了中级难度的全部试炼！", "恭喜");
                }
                if (gameMode == Game.GameMode.Hard && gameIndex == 3)
                {
                    MessageBox.Show("祝贺！你完成了全部试炼！！！", "恭喜");
                    button3.Enabled = false;
                }

                button3.Enabled = true;//按钮 启用下一题
                button2.Enabled = false;//防止重复提交
                toolStripMenuItem1.Enabled = false;
            }
            else
            {
                MessageBox.Show("数独没有被正确解出");
            }
            //button3.Enabled = true;//test
        }

        private void button11_Click(object sender, EventArgs e)
        {
            gamer.gameProgress[(int)gameMode] = gameIndex;//更新玩家游戏进度
            gamer.lastTimeGameMode = gameMode;//实时记录玩家最后一次的游戏模式
            //label3.Text = $"{gamer.gameProgress[0]} {gamer.gameProgress[1]} {gamer.gameProgress[2]}";//测试
            button11.Enabled = false;
            button2.Enabled = true;
            toolStripMenuItem1.Enabled = true;
            label1.Enabled = true;
        }//按钮 开始 同时记录玩家模式关卡进度

        private void button3_Click(object sender, EventArgs e)
        {
            switch (gameMode)
            {
                case Game.GameMode.Easy:
                    {
                        if (gameIndex < 10)
                        {
                            button3.Enabled = false;
                            button11.Enabled = true;
                            gameIndex++;
                            IniGame(gameMode, gameIndex.ToString());
                        }
                        else if (gameIndex == 10)
                        {
                            DialogResult res = MessageBox.Show("现在是否想要开始中级难度的题目？", "继续", MessageBoxButtons.YesNo);
                            if (res == DialogResult.Yes)
                            {
                                button3.Enabled = false;
                                button11.Enabled = true;
                                gameMode = Game.GameMode.Medium;
                                gameIndex = 1;
                                IniGame(gameMode, gameIndex.ToString());
                            }
                        }
                        break;
                    }
                case Game.GameMode.Medium:
                    {
                        if (gameIndex < 6)
                        {
                            button3.Enabled = false;
                            button11.Enabled = true;
                            gameIndex++;
                            IniGame(gameMode, gameIndex.ToString());
                        }
                        else if (gameIndex == 6)
                        {
                            DialogResult res = MessageBox.Show("现在是否想要开始高级难度的题目？", "继续", MessageBoxButtons.YesNo);
                            if (res == DialogResult.Yes)
                            {
                                button3.Enabled = false;
                                button11.Enabled = true;
                                gameMode = Game.GameMode.Hard;
                                gameIndex = 1;
                                IniGame(gameMode, gameIndex.ToString());
                            }
                        }
                        break;
                    }
                case Game.GameMode.Hard:
                    {
                        button3.Enabled = false;
                        button11.Enabled = true;
                        gameIndex++;
                        IniGame(gameMode, gameIndex.ToString());
                        break;
                    }
            }
        }//按钮 下一题

        #endregion

        private void easyToolStripMenuItem_Click(object sender, EventArgs e)
        {
            gameMode = Game.GameMode.Easy;
            DialogResult res = MessageBox.Show("当前关卡的游戏进度将会丢失，\n你确定要放弃吗？", "新游戏", MessageBoxButtons.OKCancel, MessageBoxIcon.Question);
            if (res == DialogResult.OK)
            {
                IniGame(Game.GameMode.Easy, User.ReadUserGameData(gamer.GamerName)[0]);
            }
        }

        private void mediumToolStripMenuItem_Click(object sender, EventArgs e)
        {
            gameMode = Game.GameMode.Medium;
            DialogResult res = MessageBox.Show("当前关卡的游戏进度将会丢失，\n你确定要放弃吗？", "新游戏", MessageBoxButtons.OKCancel, MessageBoxIcon.Question);
            if (res == DialogResult.OK)
            {
                IniGame(Game.GameMode.Medium, User.ReadUserGameData(gamer.GamerName)[1]);
            }
        }

        private void hardToolStripMenuItem_Click(object sender, EventArgs e)
        {
            gameMode = Game.GameMode.Hard;
            DialogResult res = MessageBox.Show("当前关卡的游戏进度将会丢失，\n你确定要放弃吗？", "新游戏", MessageBoxButtons.OKCancel, MessageBoxIcon.Question);
            if (res == DialogResult.OK)
            {
                IniGame(Game.GameMode.Hard, User.ReadUserGameData(gamer.GamerName)[2]);
            }
        }

        private void toolStripMenuItem4_Click(object sender, EventArgs e)
        {
            saved = true;
            SaveSpace();
            gamer.SaveGameProgress(game.gamespace,gameMode);
            MessageBox.Show("保存成功", "保存",MessageBoxButtons.OK,MessageBoxIcon.Information);
        }//保存
    }
}