using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Text;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LW1._03
{
    public partial class ComparisonForm : Form
    {
        public ComparisonForm(List<ComputerPart> partsToCompare)
        {
            InitializeComponent();

            dgvCompare.Columns.Add("Property", "Property");

            for (int i = 0; i < partsToCompare.Count; i++)
            {
                dgvCompare.Columns.Add($"Part{i}", partsToCompare[i].Model);
            }

            AddRow("Type", partsToCompare.Select(p => p.Type).ToArray());
            AddRow("Brand", partsToCompare.Select(p => p.Brand).ToArray());
            AddRow("Model", partsToCompare.Select(p => p.Model).ToArray());
            AddRow("Release Year", partsToCompare.Select(p => p.ReleaseYear).ToArray());
            AddRow("Price", partsToCompare.Select(p => p.Price).ToArray());
            AddRow("Additional Info", partsToCompare.Select(p => p.AdditionalInfo).ToArray());
        }

        private void AddRow(string property, string[] values)
        {
            var row = new List<string> { property };
            row.AddRange(values);
            dgvCompare.Rows.Add(row.ToArray());
        }
    }
}
