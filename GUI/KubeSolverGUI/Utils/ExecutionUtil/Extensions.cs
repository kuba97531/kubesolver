using System;
using System.Threading;
using System.Windows.Forms;

namespace KubeSolverGUI.Utils.ExecutionUtil
{
    static class Extensions
    {
        public static void InvokeIfRequired(this Control control, MethodInvoker action, bool waitForJoin = false)
        {
            if (control.Disposing)
            {
                Console.WriteLine("Ignore as control is disposing");
                return;
            }

            if (control.IsDisposed)
            {
                Console.WriteLine("Ignore as control is disposed.");
                return;
            }

            if (control.InvokeRequired)
            {
                var thread = new Thread(() =>
                {
                    try
                    {
                        control.Invoke(action);
                    }
                    catch (ObjectDisposedException)
                    {
                        //ignore...
                    }
                    catch (System.ComponentModel.InvalidAsynchronousStateException)
                    {
                        //yeah.. the thread is already destroyed. Probably happens at shutdown
                    }
#if DEBUG
#else
                    catch (Exception x)
                    {
                        Program.errorLog.LogProgrammingError(x);
                    }
#endif
                });

                thread.Start();
                if (waitForJoin)
                {
                    thread.Join();
                }
            }
            else
            {
                action();
            }
        }
    }
}
