using System;
using System.IO;
using KubeSolverGUI.Utils;
using KubeSolverGUI.Utils.Controls;
using KubeSolverGUI.Utils.Serialization;

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
                SerializationUtil.GetOrSetTextInTextBox(x, "input", inputTextBox, mode);
                SerializationUtil.GetOrSetTextInTextBox(x, "output", solverOutputTextBox, mode);
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
