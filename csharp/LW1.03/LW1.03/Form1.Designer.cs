namespace LW1._03
{
    partial class LW1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            cmbSelectType = new ComboBox();
            txtBrand = new TextBox();
            txtModel = new TextBox();
            txtRelYear = new TextBox();
            txtPrice = new TextBox();
            txtAddInfo = new TextBox();
            lblType = new Label();
            lblBrand = new Label();
            lblModel = new Label();
            lblReleaseYear = new Label();
            lblPrice = new Label();
            lblAddInfo = new Label();
            dgv1 = new DataGridView();
            clnType = new DataGridViewTextBoxColumn();
            clnBrand = new DataGridViewTextBoxColumn();
            clnModel = new DataGridViewTextBoxColumn();
            clnReleaseYear = new DataGridViewTextBoxColumn();
            clnPrice = new DataGridViewTextBoxColumn();
            clnAdditionalInfo = new DataGridViewTextBoxColumn();
            btnEnter = new Button();
            ((System.ComponentModel.ISupportInitialize)dgv1).BeginInit();
            SuspendLayout();
            // 
            // cmbSelectType
            // 
            cmbSelectType.AutoCompleteMode = AutoCompleteMode.SuggestAppend;
            cmbSelectType.AutoCompleteSource = AutoCompleteSource.ListItems;
            cmbSelectType.FormattingEnabled = true;
            cmbSelectType.Location = new Point(12, 12);
            cmbSelectType.Name = "cmbSelectType";
            cmbSelectType.Size = new Size(121, 23);
            cmbSelectType.TabIndex = 0;
            cmbSelectType.SelectedIndexChanged += cmbSelectType_SelectedIndexChanged;
            // 
            // txtBrand
            // 
            txtBrand.Location = new Point(12, 41);
            txtBrand.Name = "txtBrand";
            txtBrand.Size = new Size(100, 23);
            txtBrand.TabIndex = 1;
            txtBrand.TextChanged += txtBrand_TextChanged;
            // 
            // txtModel
            // 
            txtModel.Location = new Point(12, 70);
            txtModel.Name = "txtModel";
            txtModel.Size = new Size(100, 23);
            txtModel.TabIndex = 2;
            txtModel.TextChanged += txtModel_TextChanged;
            // 
            // txtRelYear
            // 
            txtRelYear.Location = new Point(12, 99);
            txtRelYear.Name = "txtRelYear";
            txtRelYear.Size = new Size(100, 23);
            txtRelYear.TabIndex = 3;
            txtRelYear.TextChanged += txtRelYear_TextChanged;
            // 
            // txtPrice
            // 
            txtPrice.Location = new Point(12, 128);
            txtPrice.Name = "txtPrice";
            txtPrice.Size = new Size(100, 23);
            txtPrice.TabIndex = 4;
            txtPrice.TextChanged += txtPrice_TextChanged;
            // 
            // txtAddInfo
            // 
            txtAddInfo.Location = new Point(12, 157);
            txtAddInfo.Name = "txtAddInfo";
            txtAddInfo.Size = new Size(100, 23);
            txtAddInfo.TabIndex = 5;
            txtAddInfo.TextChanged += txtAddInfo_TextChanged;
            // 
            // lblType
            // 
            lblType.AutoSize = true;
            lblType.Location = new Point(139, 15);
            lblType.Name = "lblType";
            lblType.Size = new Size(32, 15);
            lblType.TabIndex = 6;
            lblType.Text = "Type";
            // 
            // lblBrand
            // 
            lblBrand.AutoSize = true;
            lblBrand.Location = new Point(118, 44);
            lblBrand.Name = "lblBrand";
            lblBrand.Size = new Size(38, 15);
            lblBrand.TabIndex = 7;
            lblBrand.Text = "Brand";
            // 
            // lblModel
            // 
            lblModel.AutoSize = true;
            lblModel.Location = new Point(118, 73);
            lblModel.Name = "lblModel";
            lblModel.Size = new Size(41, 15);
            lblModel.TabIndex = 8;
            lblModel.Text = "Model";
            // 
            // lblReleaseYear
            // 
            lblReleaseYear.AutoSize = true;
            lblReleaseYear.Location = new Point(118, 102);
            lblReleaseYear.Name = "lblReleaseYear";
            lblReleaseYear.Size = new Size(71, 15);
            lblReleaseYear.TabIndex = 9;
            lblReleaseYear.Text = "Release Year";
            // 
            // lblPrice
            // 
            lblPrice.AutoSize = true;
            lblPrice.Location = new Point(118, 131);
            lblPrice.Name = "lblPrice";
            lblPrice.Size = new Size(33, 15);
            lblPrice.TabIndex = 10;
            lblPrice.Text = "Price";
            // 
            // lblAddInfo
            // 
            lblAddInfo.AutoSize = true;
            lblAddInfo.Location = new Point(118, 160);
            lblAddInfo.Name = "lblAddInfo";
            lblAddInfo.Size = new Size(86, 15);
            lblAddInfo.TabIndex = 11;
            lblAddInfo.Text = "Additional Info";
            // 
            // dgv1
            // 
            dgv1.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            dgv1.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.AllCells;
            dgv1.AutoSizeRowsMode = DataGridViewAutoSizeRowsMode.AllCells;
            dgv1.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dgv1.Columns.AddRange(new DataGridViewColumn[] { clnType, clnBrand, clnModel, clnReleaseYear, clnPrice, clnAdditionalInfo });
            dgv1.Location = new Point(325, 12);
            dgv1.Name = "dgv1";
            dgv1.Size = new Size(649, 150);
            dgv1.TabIndex = 12;
            // 
            // clnType
            // 
            clnType.HeaderText = "Type";
            clnType.Name = "clnType";
            clnType.ReadOnly = true;
            clnType.Width = 57;
            // 
            // clnBrand
            // 
            clnBrand.HeaderText = "Brand";
            clnBrand.Name = "clnBrand";
            clnBrand.ReadOnly = true;
            clnBrand.Width = 63;
            // 
            // clnModel
            // 
            clnModel.HeaderText = "Model";
            clnModel.Name = "clnModel";
            clnModel.ReadOnly = true;
            clnModel.Width = 66;
            // 
            // clnReleaseYear
            // 
            clnReleaseYear.HeaderText = "Release Year";
            clnReleaseYear.Name = "clnReleaseYear";
            clnReleaseYear.ReadOnly = true;
            clnReleaseYear.Width = 96;
            // 
            // clnPrice
            // 
            clnPrice.HeaderText = "Price";
            clnPrice.Name = "clnPrice";
            clnPrice.ReadOnly = true;
            clnPrice.Width = 58;
            // 
            // clnAdditionalInfo
            // 
            clnAdditionalInfo.HeaderText = "Additional Info";
            clnAdditionalInfo.Name = "clnAdditionalInfo";
            clnAdditionalInfo.ReadOnly = true;
            clnAdditionalInfo.Width = 111;
            // 
            // btnEnter
            // 
            btnEnter.Anchor = AnchorStyles.Bottom | AnchorStyles.Left;
            btnEnter.Location = new Point(23, 186);
            btnEnter.Name = "btnEnter";
            btnEnter.Size = new Size(75, 23);
            btnEnter.TabIndex = 13;
            btnEnter.Text = "Enter";
            btnEnter.UseVisualStyleBackColor = true;
            btnEnter.Click += btnEnter_Click;
            // 
            // LW1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(986, 216);
            Controls.Add(btnEnter);
            Controls.Add(dgv1);
            Controls.Add(lblAddInfo);
            Controls.Add(lblPrice);
            Controls.Add(lblReleaseYear);
            Controls.Add(lblModel);
            Controls.Add(lblBrand);
            Controls.Add(lblType);
            Controls.Add(txtAddInfo);
            Controls.Add(txtPrice);
            Controls.Add(txtRelYear);
            Controls.Add(txtModel);
            Controls.Add(txtBrand);
            Controls.Add(cmbSelectType);
            FormBorderStyle = FormBorderStyle.FixedSingle;
            MaximizeBox = false;
            Name = "LW1";
            Text = "LW1";
            ((System.ComponentModel.ISupportInitialize)dgv1).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private ComboBox cmbSelectType;
        private TextBox txtBrand;
        private TextBox txtModel;
        private TextBox txtRelYear;
        private TextBox txtPrice;
        private TextBox txtAddInfo;
        private Label lblType;
        private Label lblBrand;
        private Label lblModel;
        private Label lblReleaseYear;
        private Label lblPrice;
        private Label lblAddInfo;
        private DataGridView dgv1;
        private DataGridViewTextBoxColumn clnType;
        private DataGridViewTextBoxColumn clnBrand;
        private DataGridViewTextBoxColumn clnModel;
        private DataGridViewTextBoxColumn clnReleaseYear;
        private DataGridViewTextBoxColumn clnPrice;
        private DataGridViewTextBoxColumn clnAdditionalInfo;
        private Button btnEnter;
    }
}
