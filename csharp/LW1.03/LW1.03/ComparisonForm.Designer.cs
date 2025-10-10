namespace LW1._03
{
    partial class ComparisonForm
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
            fileSystemWatcher1 = new FileSystemWatcher();
            dgvCompare = new DataGridView();
            ((System.ComponentModel.ISupportInitialize)fileSystemWatcher1).BeginInit();
            ((System.ComponentModel.ISupportInitialize)dgvCompare).BeginInit();
            SuspendLayout();
            // 
            // fileSystemWatcher1
            // 
            fileSystemWatcher1.EnableRaisingEvents = true;
            fileSystemWatcher1.SynchronizingObject = this;
            // 
            // dgvCompare
            // 
            dgvCompare.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dgvCompare.Location = new Point(12, 12);
            dgvCompare.Name = "dgvCompare";
            dgvCompare.Size = new Size(776, 248);
            dgvCompare.TabIndex = 0;
            // 
            // ComparisonForm
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 272);
            Controls.Add(dgvCompare);
            Name = "ComparisonForm";
            Text = "ComparisonForm";
            ((System.ComponentModel.ISupportInitialize)fileSystemWatcher1).EndInit();
            ((System.ComponentModel.ISupportInitialize)dgvCompare).EndInit();
            ResumeLayout(false);
        }

        #endregion

        private FileSystemWatcher fileSystemWatcher1;
        private DataGridView dgvCompare;
    }
}