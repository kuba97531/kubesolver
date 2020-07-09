using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Remoting.Messaging;
using System.Text;
using System.Threading.Tasks;

namespace KubeSolverGUI.Utils.Cube
{
    public static class ScrambleUtil
    {
        public static string ReverseMove(string move)
        {
            if (string.IsNullOrWhiteSpace(move)) return "";
            if (move.EndsWith("2")) return move;
            if (move.EndsWith("'")) return move.Substring(0, move.Length - 1);
            return move + "'";
        }

        public static string ReverseSequence(string sequence)
        {
            var result = new List<string>();
            foreach (var s in sequence.Split())
            {
                result.Add(ReverseMove(s));
            }
            result.Reverse();
            return string.Join(" ", result);
        }

        // fix sequence so that it can be understood by kubesolver
        public static string FixSequence(string sequence)
        {
            return sequence.Replace("(", " ").Replace(")", " ").Replace("2'", "2");
        }
    }
}
