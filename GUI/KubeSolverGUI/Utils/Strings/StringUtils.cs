using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace KubeSolverGUI.Utils.Strings
{
    public static class StringUtils
    {
        public static string[] SplitIntoLines(this string text)
        {
            return Regex.Split(text, "\r\n|\r|\n");
        }
    }
}
