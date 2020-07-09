using System;
using System.Collections.Generic;
using System.IO;
using System.Windows.Forms;
using KubeSolverGUI.Utils.Exceptions;

namespace KubeSolverGUI.Utils.ExecutionUtil
{
    /// <summary>
    /// a simple GUI wrapper to execute some action and catch exceptions and show error messages when they occur
    /// </summary>
    class ExecutionWrapper
    {
        public static void RunAction(Action action)
        {
            RunFunction(() =>
            {
                action();
                return 0;
            }, 0);
        }

        public static Z RunFunction<Z>(Func<Z> function, Z resultInCaseOfError)
        {
            try
            {
                return function();
            }
            catch (UserException ex)
            {
                MessageBox.Show(ex.Message, "Error");
                Console.WriteLine(ex);
            }
            catch (DebugException ex)
            {

                MessageBox.Show("You have encountered a Bug: " + ex.Message, "Error");
                Console.WriteLine(ex);

            }
#if DEBUG
#else
            catch (Exception x)
            {
                var code = ConvertExceptionToCode(x);
                Console.WriteLine(x);
                Program.errorLog.LogProgrammingError(x);
                MessageBox.Show("An error has occurred while processing your request.\n" +
                                "The program has failed to provide a helpful error message. (" + code + ")\n" +
                                "If you would like to report this bug, then please send " + Program.errorLog.Path + " to the support.", "Programming Error");
            }
#endif
            return resultInCaseOfError;
        }

        public static string ConvertExceptionToCode(Exception x)
        {
            var code = x.GetType().Name;
            if (x is ArgumentNullException) code = "ANE";
            if (x is KeyNotFoundException) code = "KNF";
            if (x is NullReferenceException) code = "NPE ";
            if (x is FileNotFoundException fnfe) code = "FNFE " + fnfe.FileName;
            return code;
        }
    }
}
