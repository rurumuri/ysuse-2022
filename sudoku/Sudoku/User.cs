using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Reflection.Emit;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static Sudoku.Game;

namespace Sudoku
{
    public partial class User : Form
    {
        static CreateGamer crt;
        static string gamerNameTemp;
        static string[] gamerDataTemp;
        public static bool gamerchoosed = false;

        public static User usr;
        public User()
        {
            InitializeComponent();
            usr = this;
        }


        private void User_Load(object sender, EventArgs e)
        {
            if (Gamer.NumofGamer == 0)//无玩家时新建
            {
                Form1.createGamer.Show();
            }

            继续ToolStripMenuItem.Enabled = false;

            menuStrip1.BackColor = Form1.frm1.menuStrip1.BackColor;
            this.BackColor = Form1.frm1.BackColor;
            FileStream readgamer = new FileStream($"..\\..\\Resources\\GamerList.txt", FileMode.Open, FileAccess.Read); //以下：读取当前存在的用户列表
            StreamReader srLine = new StreamReader(readgamer);
            string tempo = srLine.ReadLine();
            if (tempo != null)//若空用户列表，不处理
            {
                string[] temp = tempo.Trim().Split(' ');
                for (int i = 0; i < temp.Length; i++)
                {
                    System.Windows.Forms.Label label = new System.Windows.Forms.Label();
                    label.Width = flowLayoutPanel1.Width - 25;
                    label.Height = 75;
                    label.BackColor = Form1.frm1.menuStrip1.BackColor;
                    label.Font = new Font("微软雅黑", 16);
                    label.TextAlign = ContentAlignment.MiddleLeft;
                    gamerNameTemp = label.Text = temp[i];
                    flowLayoutPanel1.Controls.Add(label);
                    label.Click += Label_Click;//临时对象可以从外部引用事件！？
                }
            }
            srLine.Close();//注意关闭流

        }

        private void Label_Click(object sender, EventArgs e)
        {
            System.Windows.Forms.Label thisLabel = (System.Windows.Forms.Label)sender;
            gamerNameTemp = thisLabel.Text;
            继续ToolStripMenuItem.Text = $"继续（{gamerNameTemp}）";
            继续ToolStripMenuItem.Enabled = true;

        }

        public static string[] ReadUserGameData(string gamerName)
        {
            FileStream fr = new FileStream($"..\\..\\Resources\\GamerData\\{gamerNameTemp}.txt", FileMode.Open, FileAccess.Read);
            StreamReader sr = new StreamReader(fr);
            gamerDataTemp = sr.ReadLine().Trim().Split();
            sr.Close();
            return gamerDataTemp;
        }

        private void User_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (!gamerchoosed)
            {
                MessageBox.Show("没有玩家的情况下无法开始游戏！", "错误", MessageBoxButtons.OK, MessageBoxIcon.Error);
                e.Cancel = true;
            }
            else
            {
                e.Cancel = false;
            }
        }

        private void 新玩家ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            crt = new CreateGamer();
            crt.closefather += new CreateGamer.childclose(this.closethis);
            crt.Show();
        }
        public void closethis()//实现 在新建用户界面关闭时也一同关闭此窗体
        {
            this.Close();
        }

        private void 继续ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            gamerchoosed = true;
            FileStream fr = new FileStream($"..\\..\\Resources\\GamerData\\{gamerNameTemp}.txt", FileMode.Open, FileAccess.Read);
            StreamReader srGamer = new StreamReader(fr);
            gamerDataTemp = srGamer.ReadLine().Trim().Split();
            Form1.gamer = new Gamer(gamerNameTemp);
            Form1.gamer.GamerName = gamerNameTemp;
            Game.GameMode gm_restore = (Game.GameMode)Enum.Parse(typeof(Game.GameMode), gamerDataTemp[3]);//有亿点混乱，但是这样的，确定以及肯定
            Form1.frm1.IniGame(gm_restore, gamerDataTemp[(int)gm_restore], gamerNameTemp);//有亿点混乱，但是这样的，确定以及肯定
            Form1.frm1.Text = $"Sudoku - {Form1.gamer.GamerName}";
            srGamer.Close();
            this.Close();
        }
    }
}
