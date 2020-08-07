namespace KubeSolverGUI.Plugins.CrossSolver
{
    partial class CrossSolverControl
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
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.scrambleTextBox = new System.Windows.Forms.TextBox();
            this.startButton = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.generatorsTextBox = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.crossOrientationControl = new KubeSolverGUI.Plugins.CrossSolver.CrossOrientationControl();
            this.solverOutputTextBox = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.idleWorkingControl1 = new KubeSolverGUI.Utils.ExecutionUtil.IdleWorkingControl();
            this.splitContainer2 = new System.Windows.Forms.SplitContainer();
            this.treeViewWithFileHierarchy1 = new KubeSolverGUI.Utils.FilesAndDirectories.TreeViewWithFileHierarchy();
            this.panel1 = new System.Windows.Forms.Panel();
            this.saveCurrentParametersButton = new System.Windows.Forms.Button();
            this.groupBox2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).BeginInit();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer2)).BeginInit();
            this.splitContainer2.Panel1.SuspendLayout();
            this.splitContainer2.Panel2.SuspendLayout();
            this.splitContainer2.SuspendLayout();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.scrambleTextBox);
            this.groupBox2.Controls.Add(this.startButton);
            this.groupBox2.Controls.Add(this.label2);
            this.groupBox2.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.groupBox2.Location = new System.Drawing.Point(0, 468);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(866, 56);
            this.groupBox2.TabIndex = 2;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Running";
            // 
            // scrambleTextBox
            // 
            this.scrambleTextBox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.scrambleTextBox.Location = new System.Drawing.Point(71, 16);
            this.scrambleTextBox.Name = "scrambleTextBox";
            this.scrambleTextBox.Size = new System.Drawing.Size(676, 20);
            this.scrambleTextBox.TabIndex = 1;
            // 
            // startButton
            // 
            this.startButton.Dock = System.Windows.Forms.DockStyle.Right;
            this.startButton.Location = new System.Drawing.Point(747, 16);
            this.startButton.Name = "startButton";
            this.startButton.Size = new System.Drawing.Size(116, 37);
            this.startButton.TabIndex = 3;
            this.startButton.Text = "START";
            this.startButton.UseVisualStyleBackColor = true;
            this.startButton.Click += new System.EventHandler(this.startButton_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Dock = System.Windows.Forms.DockStyle.Left;
            this.label2.Location = new System.Drawing.Point(3, 16);
            this.label2.Name = "label2";
            this.label2.Padding = new System.Windows.Forms.Padding(7);
            this.label2.Size = new System.Drawing.Size(68, 27);
            this.label2.TabIndex = 0;
            this.label2.Text = "Scramble:";
            // 
            // splitContainer1
            // 
            this.splitContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer1.Location = new System.Drawing.Point(0, 0);
            this.splitContainer1.Name = "splitContainer1";
            // 
            // splitContainer1.Panel1
            // 
            this.splitContainer1.Panel1.Controls.Add(this.groupBox1);
            this.splitContainer1.Panel1.Controls.Add(this.crossOrientationControl);
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.Controls.Add(this.solverOutputTextBox);
            this.splitContainer1.Panel2.Controls.Add(this.label3);
            this.splitContainer1.Size = new System.Drawing.Size(650, 468);
            this.splitContainer1.SplitterDistance = 287;
            this.splitContainer1.TabIndex = 3;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.generatorsTextBox);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Dock = System.Windows.Forms.DockStyle.Top;
            this.groupBox1.Location = new System.Drawing.Point(0, 109);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(287, 54);
            this.groupBox1.TabIndex = 3;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Settings";
            // 
            // generatorsTextBox
            // 
            this.generatorsTextBox.Dock = System.Windows.Forms.DockStyle.Left;
            this.generatorsTextBox.Location = new System.Drawing.Point(79, 16);
            this.generatorsTextBox.Name = "generatorsTextBox";
            this.generatorsTextBox.Size = new System.Drawing.Size(210, 20);
            this.generatorsTextBox.TabIndex = 1;
            this.generatorsTextBox.Text = "RLUFDB";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Dock = System.Windows.Forms.DockStyle.Left;
            this.label1.Location = new System.Drawing.Point(3, 16);
            this.label1.Name = "label1";
            this.label1.Padding = new System.Windows.Forms.Padding(7);
            this.label1.Size = new System.Drawing.Size(76, 27);
            this.label1.TabIndex = 0;
            this.label1.Text = "Generators:";
            // 
            // crossOrientationControl
            // 
            this.crossOrientationControl.Dock = System.Windows.Forms.DockStyle.Top;
            this.crossOrientationControl.Location = new System.Drawing.Point(0, 0);
            this.crossOrientationControl.Name = "crossOrientationControl";
            this.crossOrientationControl.Orientation = System.Windows.Forms.Orientation.Vertical;
            this.crossOrientationControl.Size = new System.Drawing.Size(287, 109);
            this.crossOrientationControl.TabIndex = 2;
            // 
            // solverOutputTextBox
            // 
            this.solverOutputTextBox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.solverOutputTextBox.Location = new System.Drawing.Point(0, 27);
            this.solverOutputTextBox.Multiline = true;
            this.solverOutputTextBox.Name = "solverOutputTextBox";
            this.solverOutputTextBox.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.solverOutputTextBox.Size = new System.Drawing.Size(359, 441);
            this.solverOutputTextBox.TabIndex = 0;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Dock = System.Windows.Forms.DockStyle.Top;
            this.label3.Location = new System.Drawing.Point(0, 0);
            this.label3.Name = "label3";
            this.label3.Padding = new System.Windows.Forms.Padding(7);
            this.label3.Size = new System.Drawing.Size(59, 27);
            this.label3.TabIndex = 1;
            this.label3.Text = "Results:";
            // 
            // idleWorkingControl1
            // 
            this.idleWorkingControl1.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.idleWorkingControl1.Location = new System.Drawing.Point(0, 524);
            this.idleWorkingControl1.MaximumSize = new System.Drawing.Size(3000, 19);
            this.idleWorkingControl1.Name = "idleWorkingControl1";
            this.idleWorkingControl1.Size = new System.Drawing.Size(866, 19);
            this.idleWorkingControl1.TabIndex = 5;
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
            this.splitContainer2.Panel2.Controls.Add(this.panel1);
            this.splitContainer2.Size = new System.Drawing.Size(866, 468);
            this.splitContainer2.SplitterDistance = 650;
            this.splitContainer2.TabIndex = 6;
            // 
            // treeViewWithFileHierarchy1
            // 
            this.treeViewWithFileHierarchy1._DefaultExtension = "txt";
            this.treeViewWithFileHierarchy1._DefaultExtensionDescription = "Text files";
            this.treeViewWithFileHierarchy1._DefaultFileName = null;
            this.treeViewWithFileHierarchy1._RootDirectory = "Configs\\CrossSolver";
            this.treeViewWithFileHierarchy1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.treeViewWithFileHierarchy1.Location = new System.Drawing.Point(0, 30);
            this.treeViewWithFileHierarchy1.Name = "treeViewWithFileHierarchy1";
            this.treeViewWithFileHierarchy1.Size = new System.Drawing.Size(212, 438);
            this.treeViewWithFileHierarchy1.TabIndex = 0;
            this.treeViewWithFileHierarchy1._FileSelected += new KubeSolverGUI.Utils.FilesAndDirectories.TreeViewWithFileHierarchy.FileSelectedDelegate(this.TreeViewWithFileHierarchy1__FileSelected);
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.saveCurrentParametersButton);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel1.Location = new System.Drawing.Point(0, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(212, 30);
            this.panel1.TabIndex = 1;
            // 
            // saveCurrentParametersButton
            // 
            this.saveCurrentParametersButton.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.saveCurrentParametersButton.Location = new System.Drawing.Point(3, 3);
            this.saveCurrentParametersButton.Name = "saveCurrentParametersButton";
            this.saveCurrentParametersButton.Size = new System.Drawing.Size(206, 23);
            this.saveCurrentParametersButton.TabIndex = 0;
            this.saveCurrentParametersButton.Text = "save current parameters";
            this.saveCurrentParametersButton.UseVisualStyleBackColor = true;
            this.saveCurrentParametersButton.Click += new System.EventHandler(this.saveCurrentParametersButton_Click);
            // 
            // CrossSolverControl
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.splitContainer2);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.idleWorkingControl1);
            this.Name = "CrossSolverControl";
            this.Size = new System.Drawing.Size(866, 543);
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.splitContainer1.Panel1.ResumeLayout(false);
            this.splitContainer1.Panel2.ResumeLayout(false);
            this.splitContainer1.Panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).EndInit();
            this.splitContainer1.ResumeLayout(false);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.splitContainer2.Panel1.ResumeLayout(false);
            this.splitContainer2.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer2)).EndInit();
            this.splitContainer2.ResumeLayout(false);
            this.panel1.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.TextBox scrambleTextBox;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button startButton;
        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TextBox generatorsTextBox;
        private System.Windows.Forms.Label label1;
        private CrossOrientationControl crossOrientationControl;
        private System.Windows.Forms.TextBox solverOutputTextBox;
        private System.Windows.Forms.Label label3;
        private Utils.ExecutionUtil.IdleWorkingControl idleWorkingControl1;
        private System.Windows.Forms.SplitContainer splitContainer2;
        private Utils.FilesAndDirectories.TreeViewWithFileHierarchy treeViewWithFileHierarchy1;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button saveCurrentParametersButton;
    }
}
