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
    public partial class Statics : Form
    {
        public Statics()
        {
            InitializeComponent();
        }

        private void Statics_Load(object sender, EventArgs e)
        {
            string[] temp = User.ReadUserGameData(Form1.gamer.GamerName);
            label1.Text = $"当前玩家：{Form1.gamer.GamerName}";
            label2.Text = $"进度：Easy {temp[0]}   Medium {temp[1]}   Hard {temp[2]}";
            label3.Text = $"分数：{temp[6]}";
        }
    }
}
