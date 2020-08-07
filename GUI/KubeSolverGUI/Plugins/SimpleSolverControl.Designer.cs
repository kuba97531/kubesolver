using KubeSolverGUI.Utils.ExecutionUtil;

namespace KubeSolverGUI.Plugins
{
    partial class SimpleSolverControl
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
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.inputTextBox = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.splitContainer2 = new System.Windows.Forms.SplitContainer();
            this.solverOutputTextBox = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.runButton = new System.Windows.Forms.Button();
            this.idleWorkingControl1 = new KubeSolverGUI.Utils.ExecutionUtil.IdleWorkingControl();
            this.splitContainer3 = new System.Windows.Forms.SplitContainer();
            this.panel1 = new System.Windows.Forms.Panel();
            this.saveCurrentParametersButton = new System.Windows.Forms.Button();
            this.treeViewWithFileHierarchy1 = new KubeSolverGUI.Utils.FilesAndDirectories.TreeViewWithFileHierarchy();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).BeginInit();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer2)).BeginInit();
            this.splitContainer2.Panel1.SuspendLayout();
            this.splitContainer2.Panel2.SuspendLayout();
            this.splitContainer2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer3)).BeginInit();
            this.splitContainer3.Panel1.SuspendLayout();
            this.splitContainer3.Panel2.SuspendLayout();
            this.splitContainer3.SuspendLayout();
            this.panel1.SuspendLayout();
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
            this.splitContainer1.Panel2.Controls.Add(this.splitContainer2);
            this.splitContainer1.Size = new System.Drawing.Size(622, 546);
            this.splitContainer1.SplitterDistance = 206;
            this.splitContainer1.TabIndex = 3;
            // 
            // inputTextBox
            // 
            this.inputTextBox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.inputTextBox.Location = new System.Drawing.Point(0, 27);
            this.inputTextBox.Multiline = true;
            this.inputTextBox.Name = "inputTextBox";
            this.inputTextBox.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.inputTextBox.Size = new System.Drawing.Size(206, 519);
            this.inputTextBox.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Dock = System.Windows.Forms.DockStyle.Top;
            this.label1.Location = new System.Drawing.Point(0, 0);
            this.label1.Name = "label1";
            this.label1.Padding = new System.Windows.Forms.Padding(7);
            this.label1.Size = new System.Drawing.Size(163, 27);
            this.label1.TabIndex = 0;
            this.label1.Text = "Input commands for the solver";
            // 
            // splitContainer2
            // 
            this.splitContainer2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer2.FixedPanel = System.Windows.Forms.FixedPanel.Panel2;
            this.splitContainer2.IsSplitterFixed = true;
            this.splitContainer2.Location = new System.Drawing.Point(0, 0);
            this.splitContainer2.Name = "splitContainer2";
            this.splitContainer2.Orientation = System.Windows.Forms.Orientation.Horizontal;
            // 
            // splitContainer2.Panel1
            // 
            this.splitContainer2.Panel1.Controls.Add(this.solverOutputTextBox);
            this.splitContainer2.Panel1.Controls.Add(this.label2);
            // 
            // splitContainer2.Panel2
            // 
            this.splitContainer2.Panel2.Controls.Add(this.runButton);
            this.splitContainer2.Size = new System.Drawing.Size(412, 546);
            this.splitContainer2.SplitterDistance = 492;
            this.splitContainer2.TabIndex = 3;
            // 
            // solverOutputTextBox
            // 
            this.solverOutputTextBox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.solverOutputTextBox.Location = new System.Drawing.Point(0, 27);
            this.solverOutputTextBox.Multiline = true;
            this.solverOutputTextBox.Name = "solverOutputTextBox";
            this.solverOutputTextBox.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.solverOutputTextBox.Size = new System.Drawing.Size(412, 465);
            this.solverOutputTextBox.TabIndex = 2;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Dock = System.Windows.Forms.DockStyle.Top;
            this.label2.Location = new System.Drawing.Point(0, 0);
            this.label2.Name = "label2";
            this.label2.Padding = new System.Windows.Forms.Padding(7);
            this.label2.Size = new System.Drawing.Size(87, 27);
            this.label2.TabIndex = 1;
            this.label2.Text = "Solver output:";
            // 
            // runButton
            // 
            this.runButton.Location = new System.Drawing.Point(12, 15);
            this.runButton.Name = "runButton";
            this.runButton.Size = new System.Drawing.Size(131, 23);
            this.runButton.TabIndex = 0;
            this.runButton.Text = "Run";
            this.runButton.UseVisualStyleBackColor = true;
            this.runButton.Click += new System.EventHandler(this.runButton_Click);
            // 
            // idleWorkingControl1
            // 
            this.idleWorkingControl1.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.idleWorkingControl1.Location = new System.Drawing.Point(0, 546);
            this.idleWorkingControl1.MaximumSize = new System.Drawing.Size(3000, 19);
            this.idleWorkingControl1.Name = "idleWorkingControl1";
            this.idleWorkingControl1.Size = new System.Drawing.Size(878, 19);
            this.idleWorkingControl1.TabIndex = 4;
            // 
            // splitContainer3
            // 
            this.splitContainer3.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer3.Location = new System.Drawing.Point(0, 0);
            this.splitContainer3.Name = "splitContainer3";
            // 
            // splitContainer3.Panel1
            // 
            this.splitContainer3.Panel1.Controls.Add(this.splitContainer1);
            // 
            // splitContainer3.Panel2
            // 
            this.splitContainer3.Panel2.Controls.Add(this.treeViewWithFileHierarchy1);
            this.splitContainer3.Panel2.Controls.Add(this.panel1);
            this.splitContainer3.Size = new System.Drawing.Size(878, 546);
            this.splitContainer3.SplitterDistance = 622;
            this.splitContainer3.TabIndex = 5;
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.saveCurrentParametersButton);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel1.Location = new System.Drawing.Point(0, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(252, 30);
            this.panel1.TabIndex = 2;
            // 
            // saveCurrentParametersButton
            // 
            this.saveCurrentParametersButton.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.saveCurrentParametersButton.Location = new System.Drawing.Point(3, 3);
            this.saveCurrentParametersButton.Name = "saveCurrentParametersButton";
            this.saveCurrentParametersButton.Size = new System.Drawing.Size(246, 23);
            this.saveCurrentParametersButton.TabIndex = 0;
            this.saveCurrentParametersButton.Text = "save current parameters";
            this.saveCurrentParametersButton.UseVisualStyleBackColor = true;
            this.saveCurrentParametersButton.Click += new System.EventHandler(this.saveCurrentParametersButton_Click);
            // 
            // treeViewWithFileHierarchy1
            // 
            this.treeViewWithFileHierarchy1._DefaultExtension = "txt";
            this.treeViewWithFileHierarchy1._DefaultExtensionDescription = "Text files";
            this.treeViewWithFileHierarchy1._DefaultFileName = null;
            this.treeViewWithFileHierarchy1._RootDirectory = "Configs\\Basic";
            this.treeViewWithFileHierarchy1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.treeViewWithFileHierarchy1.Location = new System.Drawing.Point(0, 30);
            this.treeViewWithFileHierarchy1.Name = "treeViewWithFileHierarchy1";
            this.treeViewWithFileHierarchy1.Size = new System.Drawing.Size(252, 516);
            this.treeViewWithFileHierarchy1.TabIndex = 3;
            this.treeViewWithFileHierarchy1._FileSelected += new KubeSolverGUI.Utils.FilesAndDirectories.TreeViewWithFileHierarchy.FileSelectedDelegate(this.TreeViewWithFileHierarchy1__FileSelected);
            // 
            // SimpleSolverControl
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.splitContainer3);
            this.Controls.Add(this.idleWorkingControl1);
            this.Name = "SimpleSolverControl";
            this.Size = new System.Drawing.Size(878, 565);
            this.splitContainer1.Panel1.ResumeLayout(false);
            this.splitContainer1.Panel1.PerformLayout();
            this.splitContainer1.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).EndInit();
            this.splitContainer1.ResumeLayout(false);
            this.splitContainer2.Panel1.ResumeLayout(false);
            this.splitContainer2.Panel1.PerformLayout();
            this.splitContainer2.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer2)).EndInit();
            this.splitContainer2.ResumeLayout(false);
            this.splitContainer3.Panel1.ResumeLayout(false);
            this.splitContainer3.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer3)).EndInit();
            this.splitContainer3.ResumeLayout(false);
            this.panel1.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.TextBox inputTextBox;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.SplitContainer splitContainer2;
        private System.Windows.Forms.TextBox solverOutputTextBox;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button runButton;
        private IdleWorkingControl idleWorkingControl1;
        private System.Windows.Forms.SplitContainer splitContainer3;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button saveCurrentParametersButton;
        private Utils.FilesAndDirectories.TreeViewWithFileHierarchy treeViewWithFileHierarchy1;
    }
}
