using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using KubeSolverGUI.Utils.Controls;

namespace KubeSolverGUI.Plugins.TrainingScrambleGnerator
{
        public enum TrainingScrambleTypeEnum
        {
            OptimalRUFB,
            Fast
        }

        public class TrainingScrambleTypeControl : MultiRadioButtonSelectionControl<TrainingScrambleTypeEnum>
        {
            public override string GetTitle()
            {
                return "How should the scrambles be generated?";
            }

            public override List<Tuple<string, TrainingScrambleTypeEnum>> GetItems()
            {
                return new List<Tuple<string, TrainingScrambleTypeEnum>> {
                    Tuple.Create("Fast (2phase)", TrainingScrambleTypeEnum.Fast),
                    Tuple.Create("RUFB move optimal (short scrambles)", TrainingScrambleTypeEnum.OptimalRUFB),
                };
            }
        }
 
}
