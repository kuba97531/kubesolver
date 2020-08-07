using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using KubeSolverGUI.Utils.Controls;
using KubeSolverGUI.Utils.Serialization;

namespace KubeSolverGUI.Plugins.TrainingScrambleGnerator
{
        public enum TrainingScrambleTypeEnum
        {
            OptimalRUFB,
            OptimalRUFL,
            OptimalRUFLB,
        Fast
        }

        public class TrainingScrambleTypeControl : MultiRadioButtonSelectionControl<TrainingScrambleTypeEnum>, ISerializableControl
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
                    Tuple.Create("RUFL move optimal (short scrambles)", TrainingScrambleTypeEnum.OptimalRUFL),
                    Tuple.Create("RUFLB move optimal (short scrambles)", TrainingScrambleTypeEnum.OptimalRUFL),
                };
            }


            public void GetOrSetInDictionary(PropertyDictionary.PrefixDictionary dict, string key, GetOrSet mode)
            {
                if (mode == GetOrSet.Get)
                {
                    dict.Add(key, (int)GetSelectedItem());
                }
                else
                {
                    SetSelectedItem((TrainingScrambleTypeEnum)dict.GetInt(key));
                }
            }
    }
 
}
