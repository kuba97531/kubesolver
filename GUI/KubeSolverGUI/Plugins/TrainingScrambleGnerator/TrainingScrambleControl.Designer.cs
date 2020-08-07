﻿namespace KubeSolverGUI.Plugins.TrainingScrambleGnerator
{
    partial class TrainingScrambleControl
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

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(TrainingScrambleControl));
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.inputTextBox = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.solverOutputTextBox = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.startButton = new System.Windows.Forms.Button();
            this.splitContainer2 = new System.Windows.Forms.SplitContainer();
            this.saveCurrentParametersButton = new System.Windows.Forms.Button();
            this.treeViewWithFileHierarchy1 = new KubeSolverGUI.Utils.FilesAndDirectories.TreeViewWithFileHierarchy();
            this.trainingScrambleTypeControl = new KubeSolverGUI.Plugins.TrainingScrambleGnerator.TrainingScrambleTypeControl();
            this.idleWorkingControl1 = new KubeSolverGUI.Utils.ExecutionUtil.IdleWorkingControl();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).BeginInit();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer2)).BeginInit();
            this.splitContainer2.Panel1.SuspendLayout();
            this.splitContainer2.Panel2.SuspendLayout();
            this.splitContainer2.SuspendLayout();
            this.SuspendLayout();
            // 
            // splitContainer1
            // 
            this.splitContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer1.Location = new System.Drawing.Point(0, 0);
            this.splitContainer1.Name = "splitContainer1";
            // 
            // splitContainer1.Panel1
            // 
            this.splitContainer1.Panel1.Controls.Add(this.inputTextBox);
            this.splitContainer1.Panel1.Controls.Add(this.label1);
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.Controls.Add(this.solverOutputTextBox);
            this.splitContainer1.Panel2.Controls.Add(this.label2);
            this.splitContainer1.Size = new System.Drawing.Size(900, 602);
            this.splitContainer1.SplitterDistance = 299;
            this.splitContainer1.TabIndex = 0;
            // 
            // inputTextBox
            // 
            this.inputTextBox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.inputTextBox.Location = new System.Drawing.Point(0, 27);
            this.inputTextBox.Multiline = true;
            this.inputTextBox.Name = "inputTextBox";
            this.inputTextBox.Size = new System.Drawing.Size(299, 575);
            this.inputTextBox.TabIndex = 1;
            this.inputTextBox.Text = resources.GetString("inputTextBox.Text");
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Dock = System.Windows.Forms.DockStyle.Top;
            this.label1.Location = new System.Drawing.Point(0, 0);
            this.label1.Name = "label1";
            this.label1.Padding = new System.Windows.Forms.Padding(7);
            this.label1.Size = new System.Drawing.Size(71, 27);
            this.label1.TabIndex = 0;
            this.label1.Text = "Input Data";
            // 
            // solverOutputTextBox
            // 
            this.solverOutputTextBox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.solverOutputTextBox.Location = new System.Drawing.Point(0, 27);
            this.solverOutputTextBox.Multiline = true;
            this.solverOutputTextBox.Name = "solverOutputTextBox";
            this.solverOutputTextBox.Size = new System.Drawing.Size(597, 575);
            this.solverOutputTextBox.TabIndex = 2;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Dock = System.Windows.Forms.DockStyle.Top;
            this.label2.Location = new System.Drawing.Point(0, 0);
            this.label2.Name = "label2";
            this.label2.Padding = new System.Windows.Forms.Padding(7);
            this.label2.Size = new System.Drawing.Size(56, 27);
            this.label2.TabIndex = 0;
            this.label2.Text = "Results";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.trainingScrambleTypeControl);
            this.groupBox2.Controls.Add(this.startButton);
            this.groupBox2.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.groupBox2.Location = new System.Drawing.Point(0, 602);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(1181, 78);
            this.groupBox2.TabIndex = 7;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Running";
            // 
            // startButton
            // 
            this.startButton.Dock = System.Windows.Forms.DockStyle.Right;
            this.startButton.Location = new System.Drawing.Point(906, 16);
            this.startButton.Name = "startButton";
            this.startButton.Size = new System.Drawing.Size(272, 59);
            this.startButton.TabIndex = 3;
            this.startButton.Text = "START";
            this.startButton.UseVisualStyleBackColor = true;
            this.startButton.Click += new System.EventHandler(this.startButton_Click);
            // 
            // splitContainer2
            // 
            this.splitContainer2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer2.Location = new System.Drawing.Point(0, 0);
            this.splitContainer2.Name = "splitContainer2";
            // 
            // splitContainer2.Panel1
            // 
            this.splitContainer2.Panel1.Controls.Add(this.splitContainer1);
            // 
            // splitContainer2.Panel2
            // 
            this.splitContainer2.Panel2.Controls.Add(this.treeViewWithFileHierarchy1);
            this.splitContainer2.Panel2.Controls.Add(this.saveCurrentParametersButton);
            this.splitContainer2.Size = new System.Drawing.Size(1181, 602);
            this.splitContainer2.SplitterDistance = 900;
            this.splitContainer2.TabIndex = 8;
            // 
            // saveCurrentParametersButton
            // 
            this.saveCurrentParametersButton.Dock = System.Windows.Forms.DockStyle.Top;
            this.saveCurrentParametersButton.Location = new System.Drawing.Point(0, 0);
            this.saveCurrentParametersButton.Name = "saveCurrentParametersButton";
            this.saveCurrentParametersButton.Size = new System.Drawing.Size(277, 23);
            this.saveCurrentParametersButton.TabIndex = 1;
            this.saveCurrentParametersButton.Text = "save current parameters";
            this.saveCurrentParametersButton.UseVisualStyleBackColor = true;
            this.saveCurrentParametersButton.Click += new System.EventHandler(this.saveCurrentParametersButton_Click);
            // 
            // treeViewWithFileHierarchy1
            // 
            this.treeViewWithFileHierarchy1._DefaultExtension = "txt";
            this.treeViewWithFileHierarchy1._DefaultExtensionDescription = "Text files";
            this.treeViewWithFileHierarchy1._DefaultFileName = null;
            this.treeViewWithFileHierarchy1._RootDirectory = "Configs\\TrainingScrambles";
            this.treeViewWithFileHierarchy1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.treeViewWithFileHierarchy1.Location = new System.Drawing.Point(0, 23);
            this.treeViewWithFileHierarchy1.Name = "treeViewWithFileHierarchy1";
            this.treeViewWithFileHierarchy1.Size = new System.Drawing.Size(277, 579);
            this.treeViewWithFileHierarchy1.TabIndex = 0;
            this.treeViewWithFileHierarchy1._FileSelected += new KubeSolverGUI.Utils.FilesAndDirectories.TreeViewWithFileHierarchy.FileSelectedDelegate(this.TreeViewWithFileHierarchy1__FileSelected);
            // 
            // trainingScrambleTypeControl
            // 
            this.trainingScrambleTypeControl.Dock = System.Windows.Forms.DockStyle.Left;
            this.trainingScrambleTypeControl.Location = new System.Drawing.Point(3, 16);
            this.trainingScrambleTypeControl.Name = "trainingScrambleTypeControl";
            this.trainingScrambleTypeControl.Orientation = System.Windows.Forms.Orientation.Horizontal;
            this.trainingScrambleTypeControl.Size = new System.Drawing.Size(600, 59);
            this.trainingScrambleTypeControl.TabIndex = 4;
            // 
            // idleWorkingControl1
            // 
            this.idleWorkingControl1.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.idleWorkingControl1.Location = new System.Drawing.Point(0, 680);
            this.idleWorkingControl1.MaximumSize = new System.Drawing.Size(3000, 19);
            this.idleWorkingControl1.Name = "idleWorkingControl1";
            this.idleWorkingControl1.Size = new System.Drawing.Size(1181, 19);
            this.idleWorkingControl1.TabIndex = 6;
            // 
            // TrainingScrambleControl
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.splitContainer2);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.idleWorkingControl1);
            this.Name = "TrainingScrambleControl";
            this.Size = new System.Drawing.Size(1181, 699);
            this.splitContainer1.Panel1.ResumeLayout(false);
            this.splitContainer1.Panel1.PerformLayout();
            this.splitContainer1.Panel2.ResumeLayout(false);
            this.splitContainer1.Panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).EndInit();
            this.splitContainer1.ResumeLayout(false);
            this.groupBox2.ResumeLayout(false);
            this.splitContainer2.Panel1.ResumeLayout(false);
            this.splitContainer2.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer2)).EndInit();
            this.splitContainer2.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.TextBox inputTextBox;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox solverOutputTextBox;
        private System.Windows.Forms.Label label2;
        private Utils.ExecutionUtil.IdleWorkingControl idleWorkingControl1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Button startButton;
        private TrainingScrambleTypeControl trainingScrambleTypeControl;
        private System.Windows.Forms.SplitContainer splitContainer2;
        private Utils.FilesAndDirectories.TreeViewWithFileHierarchy treeViewWithFileHierarchy1;
        private System.Windows.Forms.Button saveCurrentParametersButton;
    }
}