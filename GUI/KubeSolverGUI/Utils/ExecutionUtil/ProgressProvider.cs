using System;
using System.Windows.Forms;

namespace KubeSolverGUI.Utils.ExecutionUtil
{

    public enum ProgressCancelEnum
    {
        None,
        Cancel,
        StopAndSave
    }

    /// <summary>
    /// Control the progress of a plugin execution
    /// </summary>
    public interface IProgressProvider
    {
        /// <summary>
        /// Send back information to the caller about the progress.
        /// Update progress by reporting what plugin is currently working on.
        /// </summary>
        void UpdateProgress(string message, params object[] arguments);

        event Action<IProgressProvider> OnProgressUpdated;

        /// <summary>
        /// Check this property periodically. It's CancelReason > 0
        /// </summary>
        bool CancelRequested { get; }

        /// <summary>
        /// Check this property periodically. If it > 0  then the caller requested plugin operation to cancel.
        /// </summary>
        ProgressCancelEnum CancelReason { get; }

        object Status { get; set; }

        void InvokeInGUIThread(MethodInvoker action);
    }
}
