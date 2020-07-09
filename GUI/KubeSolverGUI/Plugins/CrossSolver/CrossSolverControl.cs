using System;
using System.Collections.Generic;
using KubeSolverGUI.Utils;
using KubeSolverGUI.Utils.Controls;
using KubeSolverGUI.Utils.Cube;
using KubeSolverGUI.Utils.ExecutionUtil;

namespace KubeSolverGUI.Plugins.CrossSolver
{
    public partial class CrossSolverControl : KubeControl
    {
        public CrossSolverControl()
        {
            InitializeComponent();
            _processor = new SolverOutputProcessor(solverOutputTextBox);
        }

        private SolverOutputProcessor _processor;

        private static string[] _crossOrientations = new[]
        {
            "", // white on top
            "x", // green on top
            "x2", // yellow on top
            "x'", // blue on top
            "z", // orange on top
            "z'", // red on top
        };

        private static string[] _sideOrientations = new[]
        {
            "", // white on top
            "y", // green on top
            "y2", // yellow on top
            "y'", // blue on top
        };

        private string[] Mult(string[] a1, string[] a2)
        {
            var result = new List<string>();
            foreach (var s1 in a1)
            {
                foreach (var s2 in a2)
                {
                    result.Add(s1 + " " + s2);
                }
            }
            return result.ToArray();
        }

        private void startButton_Click(object sender, System.EventArgs e)
        {
            var option = crossOrientationControl.GetSelectedItem();
            var allOrientations = new string[] { "" };
            if (option == CrossOrientationEnum.OneOrientationPerColor ||
                option == CrossOrientationEnum.AllOrientations)
            {
                allOrientations = Mult(allOrientations, _crossOrientations);
            }

            if (option == CrossOrientationEnum.AllOrientations)
            {
                allOrientations = Mult(allOrientations, _sideOrientations);
            }

            var gen = generatorsTextBox.Text;
            var scramble = scrambleTextBox.Text;

            idleWorkingControl1.Execute(progress =>
            {
                foreach (var orientation in allOrientations)
                {
                    if (progress.CancelRequested) return;
                    var inputLines = new[]
                    {
                        "set da 0",
                        "init_empty_cube",
                        "set_gen " + gen,
                        "set d 12",
                        "add_edge DF",
                        "add_edge DB",
                        "add_edge DR",
                        "add_edge DL",
                        ScrambleUtil.ReverseSequence(orientation),
                        scramble,
                        orientation,
                        "solve"
                    };
                    solverOutputTextBox.InvokeIfRequired(() =>
                        solverOutputTextBox.AppendText("Optimal crosses for orientation " + orientation +
                                                       Environment.NewLine));
                    _processor.SetAdjuster((cross) => orientation + " " + cross.Trim() + "// (" + cross.Trim().Split().Length + " moves)");
                    SolverRunner.RunInSolver(progress, "--silent", inputLines, _processor);
                    _processor.Wait();
                    _processor.SetAdjuster(null);
                }
            });
        }
    }
}
