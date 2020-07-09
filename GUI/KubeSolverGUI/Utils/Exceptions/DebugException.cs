using System;

namespace KubeSolverGUI.Utils.Exceptions
{
    public class DebugException : Exception
    {
        public DebugException()
        {
        }

        public DebugException(string message) : base(message)
        {
        }

        public DebugException(string message, Exception innerException) : base(message, innerException)
        {
        }

        [System.Diagnostics.DebuggerHidden]
        public static void Fail(string message)
        {
            throw new DebugException("Unexpected error. " + message);
        }

        [System.Diagnostics.DebuggerHidden]
        public static void AssertNotNull( object obj, string message)
        {
            if (obj == null)
            {
                throw new DebugException("Unexpected error. The value of '" + message + "' should never be empty.");
            }
        }

        [System.Diagnostics.DebuggerHidden]
        public static void Assert( bool condition, string message)
        {
            if (!condition)
            {
                throw new DebugException("Unexpected error." + message);
            }
        }

        [System.Diagnostics.DebuggerHidden]
        public static void Assert(bool condition, Lazy<string> message)
        {
            if (!condition)
            {
                throw new DebugException("Unexpected error." + message.Value);
            }
        }

        [System.Diagnostics.DebuggerHidden]
        public static void Assert(bool condition)
        {
            if (!condition)
            {
                throw new DebugException("Unexpected internal error.");
            }
        }

        [System.Diagnostics.DebuggerHidden]
        public static void AssertEqual<T>(T t1, T t2, string msg)
        {
            if (!Equals(t1, t2))
            {
                throw new DebugException(msg + ". " + t1 + " != " + t2);
            }
        }
    }
}
