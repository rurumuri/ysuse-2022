using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Sudoku
{
    public partial class Rules : Form
    {
        public Rules()
        {
            InitializeComponent();
        }

        private void Rules_Load(object sender, EventArgs e)
        {
            menuStrip1.BackColor = Form1.frm1.menuStrip1.BackColor;
            this.BackColor = Form1.frm1.BackColor;
            label1.Text = "游戏规则";
            label2.Text = "1.每一轮游戏会生成包含1到9的数字的棋盘以及空格，在空格内填写数字，使每一行每一列都不重复即可通关。\n\n2.每局游戏的分数取决于难度和总共的填改次数。游戏有简单难度10关，中等难度6关以及高难度3关，总分4300分。\n\n3.空格数量位置与游戏的难度相关，同时不同的难度下，填写次数记录的权重有所不同。";
            button1.Text = "下一页";
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            if (button1.Text == "OK")
            {
                this.Close();
            }
            操作方式ToolStripMenuItem.PerformClick();
        }


        private void 游戏规则ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            label1.Text = "游戏规则";
            label2.Text = "1.每一轮游戏会生成包含1到9的数字的棋盘以及空格，在空格内填写数字，使每一行每一列都不重复即可通关。\n\n2.每局游戏的分数取决于难度和总共的填改次数。游戏有简单难度10关，中等难度6关以及高难度3关，总分4300分。\n\n3.空格数量位置与游戏的难度相关，同时不同的难度下，填写次数记录的权重有所不同。";
            button1.Text = "下一页";
        }

        private void 操作方式ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            label1.Text = "操作方式";
            label2.Text = "1.每轮游戏加载后先点击开始，而后可以使用WSAD键控制光标移动，在空格处输入数字且允许多次修改。\n\n2.点击“帮助-提示”按钮，可以提示当前待填写的正确数字的数量，玩家可以依此判断填写数字正确与否等。\n\n3.填写完毕后点击提交，若完全正确会告知并允许进入下一关，同时记录分数。\n\n4.Have Fun！！！";
            button1.Text = "OK";
        }
    }
}
