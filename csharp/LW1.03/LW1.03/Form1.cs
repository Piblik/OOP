namespace LW1._03
{
    public partial class LW1 : Form
    {
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
            dgv1.Rows.Add(cmbSelectType.Text, txtBrand.Text, txtModel.Text, txtRelYear.Text, txtPrice.Text, txtAddInfo.Text);
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
    }
}
