using System;
using KubeSolverGUI.Utils;
using KubeSolverGUI.Utils.Controls;

namespace KubeSolverGUI.Plugins
{
    public partial class SimpleSolverControl : KubeControl
    {
        public SimpleSolverControl()
        {
            InitializeComponent();
            _processor = new SolverOutputProcessor(solverOutputTextBox);
        }

        private SolverOutputProcessor _processor;
        
       

        private void runButton_Click(object sender, EventArgs e)
        {
            var inputLines = inputTextBox.Lines;
            idleWorkingControl1.Execute((progress) =>
            {
                SolverRunner.RunInSolver(progress, "", inputLines, _processor);
            });
        }
    }
}
