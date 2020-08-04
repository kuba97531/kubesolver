using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Threading;
using KubeSolverGUI.Plugins;
using KubeSolverGUI.Utils.ExecutionUtil;

namespace KubeSolverGUI.Utils
{
    class SolverRunner
    {
        public static void RunInSolver(IProgressProvider progress, string commandLineArgs, string[] inputLines, SolverOutputProcessor outputProcessor)
        {
            var solverExecutablePath = FindSolver();
            if (solverExecutablePath == null)
            {
                outputProcessor.AddLine("Can't find a suitable kubesolver.exe in working directory.");
                return;
            }

            outputProcessor.AddLine("Starting solver " + solverExecutablePath);
            ProcessStartInfo startInfo = new ProcessStartInfo(solverExecutablePath, commandLineArgs)
            {
                WorkingDirectory = Directory.GetParent(solverExecutablePath).FullName,
                CreateNoWindow = true,
                UseShellExecute = false,
                ErrorDialog = false,
                RedirectStandardError = true,
                RedirectStandardInput = true,
                RedirectStandardOutput = true
            };

            var solverProcess = new Process();
            solverProcess.StartInfo = startInfo;
            solverProcess.Start();

            var thread = new Thread(() =>
            {
                while (true)
                {
                    if (solverProcess.HasExited)
                    {
                        return;
                    }
                    if (progress.CancelRequested)
                    {
                        solverProcess.Kill();
                        return;
                    }
                    Thread.Sleep(100);
                }
            })
            { IsBackground = true };
            thread.Start();

            ChildProcessTracker.AddProcess(solverProcess);

            foreach (var line in inputLines)
            {
                solverProcess.StandardInput.WriteLine(line);
            }
            solverProcess.StandardInput.Close();

            while (true)
            {
                var line = solverProcess.StandardOutput.ReadLine();
                if (line == null)
                {
                    return;
                }
                outputProcessor.AddLine(line);
            }
        }

        /// <summary>
        /// Tries to find a working solver in a working directory and returns null if can't.
        /// </summary>
        /// <returns></returns>
        public static string FindSolver()
        {
            var files = Directory.GetFiles(".", "*.exe");
            var versionNumbers = new List<Tuple<string, double>>();
            foreach (var file in files)
            {
                if (file.Contains("kube") && file.Contains("solver"))
                {
                    versionNumbers.Add(Tuple.Create(file, GetVersionNumber(file)));
                }
            }

            if (versionNumbers.Count == 0)
            {
                return null;
            }

            var best = versionNumbers[0];
            foreach (var x in versionNumbers)
            {
                if (x.Item2 > best.Item2)
                {
                    best = x;
                }
            }
            return best.Item1;
        }

        /// <summary>
        /// very primite way of selecting a most recent solver
        /// </summary>
        /// <param name="kubesolver"></param>
        /// <returns></returns>
        private static double GetVersionNumber(string kubesolver)
        {
            double result = 0;

            if (kubesolver.ToLower().Contains("dev"))
            {
                result = 1000;
            }

            var versionString = "";
            foreach (char c in kubesolver)
            {
                if (char.IsDigit(c) || c == '.')
                {
                    versionString += c.ToString();
                }
            }
            var numbers = versionString.Split('.').Select((s) =>
            {
                if (int.TryParse(s, out var i)) return i;
                return 0;
            });
            double multiplier = 1;
            foreach (var number in numbers)
            {
                result = result + number * multiplier;
                multiplier /= 1000;
            }
            return result;
        }
    }
}
