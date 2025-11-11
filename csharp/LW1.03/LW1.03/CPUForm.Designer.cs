namespace LW1._03
{
    partial class CPUForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            txtCores = new TextBox();
            txtFreq = new TextBox();
            lblCores = new Label();
            lblFreeq = new Label();
            btnOk = new Button();
            SuspendLayout();
            // 
            // txtCores
            // 
            txtCores.Location = new Point(12, 12);
            txtCores.Name = "txtCores";
            txtCores.Size = new Size(100, 23);
            txtCores.TabIndex = 0;
            // 
            // txtFreq
            // 
            txtFreq.Location = new Point(12, 41);
            txtFreq.Name = "txtFreq";
            txtFreq.Size = new Size(100, 23);
            txtFreq.TabIndex = 1;
            // 
            // lblCores
            // 
            lblCores.AutoSize = true;
            lblCores.Location = new Point(118, 15);
            lblCores.Name = "lblCores";
            lblCores.Size = new Size(37, 15);
            lblCores.TabIndex = 2;
            lblCores.Text = "Cores";
            // 
            // lblFreeq
            // 
            lblFreeq.AutoSize = true;
            lblFreeq.Location = new Point(118, 49);
            lblFreeq.Name = "lblFreeq";
            lblFreeq.Size = new Size(84, 15);
            lblFreeq.TabIndex = 3;
            lblFreeq.Text = "FrequencyGHz";
            // 
            // btnOk
            // 
            btnOk.Location = new Point(12, 70);
            btnOk.Name = "btnOk";
            btnOk.Size = new Size(183, 23);
            btnOk.TabIndex = 4;
            btnOk.Text = "OK";
            btnOk.UseVisualStyleBackColor = true;
            btnOk.Click += btnOk_Click;
            // 
            // CPUForm
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(207, 107);
            Controls.Add(btnOk);
            Controls.Add(lblFreeq);
            Controls.Add(lblCores);
            Controls.Add(txtFreq);
            Controls.Add(txtCores);
            Name = "CPUForm";
            Text = "CPUForm";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private TextBox txtCores;
        private TextBox txtFreq;
        private Label lblCores;
        private Label lblFreeq;
        private Button btnOk;
    }
}