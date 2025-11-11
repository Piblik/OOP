using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LW1._03
{
    public partial class CPUForm : Form
    {

        public int Cores { get; private set; }
        public float FrequencyGHz { get; private set; }

        public CPUForm()
        {
            InitializeComponent();
        }

        private void btnOk_Click(object sender, EventArgs e)
        {
            if (!int.TryParse(txtCores.Text, out int cores) ||
            !float.TryParse(txtFreq.Text, out float freq))
            {
                MessageBox.Show("Wrong CPU input!");
                return;
            }

            Cores = cores;
            FrequencyGHz = freq;

            DialogResult = DialogResult.OK;
            Close();
        }
    }
}
