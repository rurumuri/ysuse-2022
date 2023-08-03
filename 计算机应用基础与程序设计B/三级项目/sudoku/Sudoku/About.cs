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
    public partial class About : Form
    {
        public About()
        {
            InitializeComponent();
            pictureBox1.Image = imageList1.Images[0];
        }
    }
}
