﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using KubeSolverGUI.Utils.Controls;

namespace KubeSolverGUI.Plugins.CrossSolver
{
    public enum CrossOrientationEnum
    {
        OnlyHomeOrientation,
        OneOrientationPerColor,
        AllOrientations
    }

    public class CrossOrientationControl : MultiRadioButtonSelectionControl<CrossOrientationEnum> {
        public override string GetTitle()
        {
            return "Which orientations should be considered?";
        }


        public override List<Tuple<string, CrossOrientationEnum>> GetItems()
        {
            return new List<Tuple<string, CrossOrientationEnum>> { 
                Tuple.Create("Only starting orientation", CrossOrientationEnum.OnlyHomeOrientation),
                Tuple.Create("All colors (6 orientations)", CrossOrientationEnum.OneOrientationPerColor),
                Tuple.Create("All colors from all angles (24 orientations)", CrossOrientationEnum.AllOrientations),
            };
        }
    }
}
