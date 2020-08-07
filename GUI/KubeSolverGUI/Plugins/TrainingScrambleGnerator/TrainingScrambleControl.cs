using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using KubeSolverGUI.Utils;
using KubeSolverGUI.Utils.ExecutionUtil;
using KubeSolverGUI.Utils.Serialization;

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

                            switch (option)
                            {
                                case TrainingScrambleTypeEnum.OptimalRUFB:
                                inputLines.Insert(0, "set_gen RUFB");
                                inputLines.Add("solve"); 
                                    break;
                                case TrainingScrambleTypeEnum.OptimalRUFL:
                                    inputLines.Insert(0, "set_gen RUFL");
                                    inputLines.Add("solve");
                                    break;
                                case TrainingScrambleTypeEnum.OptimalRUFLB:
                                    inputLines.Insert(0, "set_gen RUFLB");
                                    inputLines.Add("solve");
                                    break;
                                case TrainingScrambleTypeEnum.Fast:
                                    inputLines.Add("solve_two_phase");
                                    break;
                                default:
                                    throw new ArgumentOutOfRangeException();
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

        private PropertyDictionary GetValues()
        {
            PropertyDictionary dict = new PropertyDictionary();
            GetOrSetValues(dict, GetOrSet.Get);
            return dict;
        }

        private void SetValues(PropertyDictionary dict)
        {
            GetOrSetValues(dict, GetOrSet.Set);
        }

        private void GetOrSetValues(PropertyDictionary dict, GetOrSet mode)
        {
            dict.Do((x) =>
            {
                SerializationUtil.GetOrSetControlValue(x, "scrambleType", trainingScrambleTypeControl, mode);
                SerializationUtil.GetOrSetTextInTextBox(x, "inputText", inputTextBox, mode);
                SerializationUtil.GetOrSetTextInTextBox(x, "outputText", solverOutputTextBox, mode);
            });
        }

        private void saveCurrentParametersButton_Click(object sender, EventArgs e)
        {
            var saveLocation = treeViewWithFileHierarchy1.ShowFileDialogAndGetSaveLocation();
            if (saveLocation != null)
            {
                var dict = GetValues();
                File.WriteAllLines(saveLocation, dict.ToLines());
                treeViewWithFileHierarchy1.RebuildTree(saveLocation);
            }
        }

        private void TreeViewWithFileHierarchy1__FileSelected(string path)
        {
            var lines = File.ReadAllLines(path);
            var dict = PropertyDictionary.FromLines(lines);
            SetValues(dict);
        }

    }
}
