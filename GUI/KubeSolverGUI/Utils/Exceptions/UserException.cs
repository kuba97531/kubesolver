using System;

namespace KubeSolverGUI.Utils.Exceptions
{
    /// <summary>
    /// This exception indicates that something has happened that is most likely the user's mistake or unexpected use of a program.
    /// This exception should be thrown when it's clear that it's not a program misbehavior.
    /// </summary>
    public class UserException : Exception
    {
        public UserException()
        {
        }

        public UserException(string message) : base(message)
        {
        }

        public UserException(string message, Exception innerException) : base(message, innerException)
        {
        }
    }
}