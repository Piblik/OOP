using System.IO;
using System.Text.Json;

namespace LW1._03
{
    public partial class LW1 : Form
    {
        private List<ComputerPart> parts = new List<ComputerPart>();
        private List<ComputerPart> compareList = new List<ComputerPart>();

        public LW1()
        {
            InitializeComponent();
            btnEnter.Enabled = false;
            cmbSelectType.Items.AddRange(new string[] {"Mother Board", "CPU",
            "GPU", "RAM", "HDD", "SSD", "PSU", "Tower", "CPU Air Cooler", "Liquid Cooler",
            "Case Fans", "Thermal Paste"});

            txtAddInfo.MaxLength = 50;
            txtBrand.MaxLength = 50;
            txtModel.MaxLength = 50;
            txtPrice.MaxLength = 50;
            txtRelYear.MaxLength = 4;
        }

        private void btnEnter_Click(object sender, EventArgs e)
        {
            if (cmbSelectType.Text == "CPU")
            {
                CPUForm cpuForm = new CPUForm();

                if (cpuForm.ShowDialog() == DialogResult.OK)
                {
                    var cpu = new CPU(
                        cmbSelectType.Text,
                        txtBrand.Text,
                        txtModel.Text,
                        txtRelYear.Text,
                        txtPrice.Text,
                        txtAddInfo.Text,
                        cpuForm.Cores,
                        cpuForm.FrequencyGHz
                    );

                    parts.Add(cpu);
                    dgv1.Rows.Add(cpu.Type, cpu.Brand, cpu.Model, cpu.ReleaseYear, cpu.Price, cpu.AdditionalInfo);
                }
            }
            else
            {
                var part = new ComputerPart(
                    cmbSelectType.Text,
                    txtBrand.Text,
                    txtModel.Text,
                    txtRelYear.Text,
                    txtPrice.Text,
                    txtAddInfo.Text
                );

                parts.Add(part);
                dgv1.Rows.Add(part.Type, part.Brand, part.Model, part.ReleaseYear, part.Price, part.AdditionalInfo);
            }

            // очищення UI
            cmbSelectType.SelectedIndex = -1;
            txtBrand.Clear();
            txtModel.Clear();
            txtRelYear.Clear();
            txtPrice.Clear();
            txtAddInfo.Clear();
            btnEnter.Enabled = false;
        }

        private void CheckFields()
        {
            btnEnter.Enabled =
                !string.IsNullOrWhiteSpace(cmbSelectType.Text) &&
                !string.IsNullOrWhiteSpace(txtBrand.Text) &&
                !string.IsNullOrWhiteSpace(txtModel.Text) &&
                !string.IsNullOrWhiteSpace(txtRelYear.Text) &&
                !string.IsNullOrWhiteSpace(txtPrice.Text) &&
                !string.IsNullOrWhiteSpace(txtAddInfo.Text);
        }

        private void cmbSelectType_SelectedIndexChanged(object sender, EventArgs e) => CheckFields();
        private void txtBrand_TextChanged(object sender, EventArgs e) => CheckFields();
        private void txtModel_TextChanged(object sender, EventArgs e) => CheckFields();
        private void txtRelYear_TextChanged(object sender, EventArgs e) => CheckFields();
        private void txtPrice_TextChanged(object sender, EventArgs e) => CheckFields();
        private void txtAddInfo_TextChanged(object sender, EventArgs e) => CheckFields();

        //==================+MenuStrip+==================\\
        //==================+Json+==================\\

        private void saveTSMI_Click(object sender, EventArgs e)
        {
            using (SaveFileDialog saveFileDialog = new SaveFileDialog())
            {
                saveFileDialog.Filter = "JSON files (*.json)|*.json|All files (*.*)|*.*";
                if (saveFileDialog.ShowDialog() == DialogResult.OK)
                {
                    string json = JsonSerializer.Serialize(parts, new JsonSerializerOptions { WriteIndented = true });
                    File.WriteAllText(saveFileDialog.FileName, json);
                    MessageBox.Show("File saved!", "Saving", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
            }
        }

        private void loadTSMI_Click(object sender, EventArgs e)
        {
            using (OpenFileDialog openFileDialog = new OpenFileDialog())
            {
                openFileDialog.Filter = "JSON files (*.json)|*.json|All files (*.*)|*.*";
                if (openFileDialog.ShowDialog() == DialogResult.OK)
                {
                    try
                    {
                        string json = File.ReadAllText(openFileDialog.FileName);
                        parts = JsonSerializer.Deserialize<List<ComputerPart>>(json) ?? new List<ComputerPart>();
                        dgv1.Rows.Clear();
                        foreach (var part in parts)
                        {
                            dgv1.Rows.Add(part);
                        }

                        MessageBox.Show("Data uploaded successfully!", "Uploading", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show("Error opening file: " + ex.Message);
                    }
                }
            }
        }

        //==================-Json-==================\\

        private void clearToolStripMenuItem_Click(object sender, EventArgs e)
        {
            dgv1.Rows.Clear();

            parts.Clear();
        }

        private void tSMIOpenComp_Click(object sender, EventArgs e)
        {
            if (compareList.Count < 2)
            {
                MessageBox.Show("You must select at least 2 items for comparison.");
                return;
            }

            ComparisonForm form = new ComparisonForm(compareList);
            form.Show();
        }

        private void tSMIClear_Click(object sender, EventArgs e)
        {
            compareList.Clear();
            MessageBox.Show("Comparison list cleared.");
        }

        private void sortByPriceToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            ComputerPart.SortByPrice(parts, ascending: true);
            dgv1.Rows.Clear();
            foreach (var part in parts)
            {
                dgv1.Rows.Add(part.Type, part.Brand, part.Model, part.ReleaseYear, part.Price, part.AdditionalInfo);
            }
        }
        private void sortByYearToolStripMenuItem_Click(object sender, EventArgs e)
        {
            parts.Sort((x, y) =>
            {
                if (x >= y) return -1;
                if (x <= y) return 1;
                return 0;
            });
            dgv1.Rows.Clear();
            foreach (var part in parts)
            {
                dgv1.Rows.Add(part.Type, part.Brand, part.Model, part.ReleaseYear, part.Price, part.AdditionalInfo);
            }
        }


        //==================-MenuStrip-==================\\

        //==================+ContextMenuStrip+==================\\

        private void deleteToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (dgv1.CurrentRow != null && dgv1.CurrentRow.Index >= 0)
            {
                int index = dgv1.CurrentRow.Index;

                if (index < parts.Count)
                    parts.RemoveAt(index);

                dgv1.Rows.RemoveAt(index);
            }
        }
        private void clearToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            dgv1.Rows.Clear();

            parts.Clear();
        }

        private void dgv1_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Right)
            {
                var hitTest = dgv1.HitTest(e.X, e.Y);
                if (hitTest.RowIndex >= 0)
                {
                    dgv1.ClearSelection();
                    dgv1.Rows[hitTest.RowIndex].Selected = true;
                    dgv1.CurrentCell = dgv1.Rows[hitTest.RowIndex].Cells[0];
                }
            }
        }

        private void addToComparisonToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (dgv1.CurrentRow != null && dgv1.CurrentRow.Index >= 0)
            {
                int index = dgv1.CurrentRow.Index;
                if (index < parts.Count)
                {
                    var partToCompare = parts[index];

                    if (!compareList.Contains(partToCompare))
                    {
                        compareList.Add(partToCompare);
                        MessageBox.Show($"{partToCompare.Model} added to comparison!", "Comparison");
                    }
                    else
                    {
                        MessageBox.Show("This item is already in the comparison list.");
                    }
                }
            }
        }

        private void sortByPriceToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ComputerPart.SortByPrice(parts, ascending: true);
            dgv1.Rows.Clear();
            foreach (var part in parts)
            {
                dgv1.Rows.Add(part.Type, part.Brand, part.Model, part.ReleaseYear, part.Price, part.AdditionalInfo);
            }
        }

        private void sortByYearToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            parts.Sort((x, y) =>
            {
                if (x >= y) return -1;
                if (x <= y) return 1;
                return 0;
            });
            dgv1.Rows.Clear();
            foreach (var part in parts)
            {
                dgv1.Rows.Add(part.Type, part.Brand, part.Model, part.ReleaseYear, part.Price, part.AdditionalInfo);
            }
        }

        private void editToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (dgv1.CurrentRow != null)
            {
                int index = dgv1.CurrentRow.Index;
                if (index < parts.Count)
                {
                    var part = parts[index];
                    txtBrand.Text = part.Brand;
                    txtModel.Text = part.Model;
                    txtRelYear.Text = part.ReleaseYear;
                    txtPrice.Text = part.Price;
                    txtAddInfo.Text = part.AdditionalInfo;
                    cmbSelectType.Text = part.Type;

                    parts.RemoveAt(index);
                    dgv1.Rows.RemoveAt(index);
                }
            }
        }

        //==================-ContextMenuStrip-==================\\
        //==================+Methods+==================\\
        //==================-Methods-==================\\

        private void btnSearch_Click(object sender, EventArgs e)
        {
            string searchText = txtSearchLine.Text.Trim();

            if (string.IsNullOrWhiteSpace(searchText))
            {
                MessageBox.Show("Please enter a brand to search.", "Search", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }

            var foundParts = parts
                .Where(p => p.Brand.Contains(searchText, StringComparison.OrdinalIgnoreCase))
                .ToList();

            dgv1.Rows.Clear();

            if (foundParts.Count == 0)
            {
                MessageBox.Show("No matches found.", "Search result", MessageBoxButtons.OK, MessageBoxIcon.Information);
                return;
            }

            foreach (var part in foundParts)
            {
                dgv1.Rows.Add(part.Type, part.Brand, part.Model, part.ReleaseYear, part.Price, part.AdditionalInfo);
            }
        }

        private void btnShowAll_Click(object sender, EventArgs e)
        {
            dgv1.Rows.Clear();
            foreach(var part in parts)
            {
                dgv1.Rows.Add(part.Type, part.Brand, part.Model, part.ReleaseYear, part.Price, part.AdditionalInfo);
            }
        }

        private void dgv1_SelectionChanged(object sender, EventArgs e)
        {
            if (dgv1.CurrentRow == null) return;

            int index = dgv1.CurrentRow.Index;
            if (index >= parts.Count) return;

            var part = parts[index];

            dgv2.Rows.Clear();
            dgv2.Columns.Clear();

            if (part is CPU cpu)
            {
                dgv2.Columns.Add("Prop", "Property");
                dgv2.Columns.Add("Val", "Value");

                dgv2.Rows.Add("CPU Cores", cpu.Cores);
                dgv2.Rows.Add("Frequency (GHz)", cpu.FrequencyGHz);
            }
        }

    }
}
