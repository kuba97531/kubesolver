using KubeSolverGUI.Plugins;

namespace KubeSolverGUI
{
    partial class MainForm
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
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.simpleSolverControl1 = new KubeSolverGUI.Plugins.SimpleSolverControl();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.crossSolverControl1 = new KubeSolverGUI.Plugins.CrossSolver.CrossSolverControl();
            this.tabPage3 = new System.Windows.Forms.TabPage();
            this.trainingScrambleControl1 = new KubeSolverGUI.Plugins.TrainingScrambleGnerator.TrainingScrambleControl();
            this.tabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.tabPage2.SuspendLayout();
            this.tabPage3.SuspendLayout();
            this.SuspendLayout();
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Controls.Add(this.tabPage3);
            this.tabControl1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tabControl1.Location = new System.Drawing.Point(0, 0);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(915, 610);
            this.tabControl1.TabIndex = 0;
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.simpleSolverControl1);
            this.tabPage1.Location = new System.Drawing.Point(4, 22);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(907, 584);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "Raw KubeSolver";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // simpleSolverControl1
            // 
            this.simpleSolverControl1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.simpleSolverControl1.Location = new System.Drawing.Point(3, 3);
            this.simpleSolverControl1.Name = "simpleSolverControl1";
            this.simpleSolverControl1.Size = new System.Drawing.Size(901, 578);
            this.simpleSolverControl1.TabIndex = 0;
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.crossSolverControl1);
            this.tabPage2.Location = new System.Drawing.Point(4, 22);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(907, 584);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "Opening Finder (Cross / EOCross / Blocks  etc.)";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // crossSolverControl1
            // 
            this.crossSolverControl1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.crossSolverControl1.Location = new System.Drawing.Point(3, 3);
            this.crossSolverControl1.Name = "crossSolverControl1";
            this.crossSolverControl1.Size = new System.Drawing.Size(901, 578);
            this.crossSolverControl1.TabIndex = 0;
            // 
            // tabPage3
            // 
            this.tabPage3.Controls.Add(this.trainingScrambleControl1);
            this.tabPage3.Location = new System.Drawing.Point(4, 22);
            this.tabPage3.Name = "tabPage3";
            this.tabPage3.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage3.Size = new System.Drawing.Size(907, 584);
            this.tabPage3.TabIndex = 2;
            this.tabPage3.Text = "Training Scramble Generator";
            this.tabPage3.UseVisualStyleBackColor = true;
            // 
            // trainingScrambleControl1
            // 
            this.trainingScrambleControl1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.trainingScrambleControl1.Location = new System.Drawing.Point(3, 3);
            this.trainingScrambleControl1.Name = "trainingScrambleControl1";
            this.trainingScrambleControl1.Size = new System.Drawing.Size(901, 578);
            this.trainingScrambleControl1.TabIndex = 0;
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(915, 610);
            this.Controls.Add(this.tabControl1);
            this.Name = "MainForm";
            this.Text = "Form1";
            this.tabControl1.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.tabPage2.ResumeLayout(false);
            this.tabPage3.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.TabPage tabPage2;
        private Plugins.SimpleSolverControl simpleSolverControl1;
        private Plugins.CrossSolver.CrossSolverControl crossSolverControl1;
        private System.Windows.Forms.TabPage tabPage3;
        private Plugins.TrainingScrambleGnerator.TrainingScrambleControl trainingScrambleControl1;
    }
}

