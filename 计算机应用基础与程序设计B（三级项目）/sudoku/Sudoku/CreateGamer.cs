using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Sudoku
{
    public partial class CreateGamer : Form
    {
        static bool repeat=false;//标记非空用户名是否重复，防止后续代码错误执行
        public CreateGamer()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e) 
        {

            if (textBox1.Text.Trim()!="")
            {
                if(!Gamer.IfGamerExist(textBox1.Text))
                {
                    repeat= false;
                    User user= new User();
                    Form1.gamer = new Gamer(textBox1.Text);//承接gamer到Form1中便于操作
                    MessageBox.Show($"欢迎，{Form1.gamer.GamerName}");
                    FileStream writegamer = new FileStream($"..\\..\\Resources\\GamerList.txt", FileMode.Append, FileAccess.Write);
                    StreamWriter sw = new StreamWriter(writegamer);
                    sw.Write($"{Form1.gamer.GamerName} ", true);
                    sw.Flush();
                    sw.Close();
                    Form1.gamer.SaveGameProgress(Form1.frm1.game.gamespace, Game.GameMode.Easy);//创建用户就立即新建用户文件，而不是主动保存时才第一次创建

                    //User.usr.flowLayoutPanel1.Refresh();//新建用户后刷新
                    this.Close();
                }
                else
                {
                    repeat = true;
                    MessageBox.Show("用户名已存在", "错误", MessageBoxButtons.OK, MessageBoxIcon.Stop);
                }
            }
            else
            {
                MessageBox.Show("用户名非法", "错误", MessageBoxButtons.OK, MessageBoxIcon.Stop);
            }
        }

        private void CreateGamer_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (Gamer.NumofGamer==0)
            {
                MessageBox.Show("没有玩家的情况下无法开始游戏！", "错误", MessageBoxButtons.OK, MessageBoxIcon.Error);
                e.Cancel = true;
            }
            else
            {
                e.Cancel = false;
            }
        }

        private void textBox1_KeyPress(object sender, KeyPressEventArgs e)
        {
            if(e.KeyChar==13)
            {
                button1_Click(sender, e);
            }
        }

        private void CreateGamer_FormClosed(object sender, FormClosedEventArgs e)
        {
            if(textBox1.Text!="" && !repeat)
            {
                Rules rules = new Rules();
                rules.Show();
                Form1.frm1.Text = $"Sudoku - {Form1.gamer.GamerName}";
                User.gamerchoosed = true;
                if(Gamer.NumofGamer!=1)//防止初始状态不显示User窗体导致无法关闭的报错
                {
                    closefather();
                }
            }
        }
        public delegate void childclose();
        public event childclose closefather;

    }
}
