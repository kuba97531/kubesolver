using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using KubeSolverGUI.Utils;
using KubeSolverGUI.Utils.ExecutionUtil;

namespace KubeSolverGUI.Plugins.TrainingScrambleGnerator
{
    public partial class TrainingScrambleControl : UserControl
    {
        private SolverOutputProcessor _processor;

        public TrainingScrambleControl()
        {
            InitializeComponent();
            _processor = new SolverOutputProcessor(solverOutputTextBox);
        }

        private void startButton_Click(object sender, EventArgs e)
        {
            var option = trainingScrambleTypeControl.GetSelectedItem();

            var groups = new List<List<string>>();

            var currentGroup = new List<string>();

            foreach (var l in inputTextBox.Lines)
            {
                var line = l.Trim();
                if (line.StartsWith("/"))
                {
                    continue;
                }
                else if (string.IsNullOrWhiteSpace(line))
                {
                    continue;
                }
                else if (line.StartsWith("-"))
                {
                    if (currentGroup.Count > 0)
                    {
                        groups.Add(currentGroup);
                        currentGroup = new List<string>();
                    }
                }
                else if (line.StartsWith("."))
                {
                    currentGroup.Add("");
                }
                else
                {
                    currentGroup.Add(line);
                }
            }

            if (currentGroup.Count > 0)
            {
                groups.Add(currentGroup);
            }

            var rand = new Random();

            idleWorkingControl1.Execute(progress =>
            {
                var tasks = new Task[4];
                for (int i = 0; i < 4; i++)
                {
                    tasks[i] = Task.Run(() =>
                    {
                        while (true)
                        {
                            if (progress.CancelRequested) return;
                            var inputLines = new List<string>()
                            {
                                "set n 1",
                                "set d 18",
                            };

                            foreach (var g in groups)
                            {
                                inputLines.Add(g[rand.Next(g.Count)]);
                            }

                            if (option == TrainingScrambleTypeEnum.OptimalRUFB)
                            {
                                inputLines.Insert(0, "set_gen RUFB");
                                inputLines.Add("solve"); 
                            }
                            else
                            {
                                inputLines.Add("solve_two_phase");
                            }

                            SolverRunner.RunInSolver(progress, "--silent", inputLines.ToArray(), _processor);
                            Console.WriteLine("DONE");
                        }
                    });
                }
                for (int i = 0; i < 4; i++)
                {
                    tasks[i].Wait();
                }
            });
        }
    }
}
