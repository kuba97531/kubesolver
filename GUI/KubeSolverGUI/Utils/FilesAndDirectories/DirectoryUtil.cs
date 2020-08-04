using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace KubeSolverGUI.Utils.FilesAndDirectories
{
    public class DirectoryCreationException : Exception
    {
        public DirectoryCreationException()
        {
        }

        public DirectoryCreationException(string message) : base(message)
        {
        }
    }


    public class DirectoryUtil
    {
        public static void CreateDirectory(string path)
        {
            if (Directory.Exists(path))
            {
                return;
            }

            // ReSharper disable once dirCreate
            try
            {
                Directory.CreateDirectory(path);
            }
            catch (System.UnauthorizedAccessException)
            {
                throw new DirectoryCreationException(
                    $"The creation of a directory '{path}' has failed (UnauthorizedAccessException). The user does not have permissions to create this directory.\n");
            }
            catch (System.ArgumentNullException x)
            {
                throw new DirectoryCreationException(
                    $"The creation of a directory '{path}' has failed due to programming error ({x.GetType().Name}).");
            }
            catch (System.ArgumentException x)
            {
                throw new DirectoryCreationException(
                    $"The creation of a directory '{path}' has failed due to programming error ({x.GetType().Name}).");
            }
            catch (System.NotSupportedException x)
            {
                throw new DirectoryCreationException(
                    $"The creation of a directory '{path}' has failed due to programming error ({x.GetType().Name}).");
            }
            catch (System.IO.PathTooLongException)
            {
                throw new DirectoryCreationException(
                    $"The creation of a directory '{path}' has failed (PathTooLongException). The path is too long. Paths must be less than 248 characters and file names must be less than 260 characters.");
            }
            catch (System.IO.DirectoryNotFoundException)
            {
                throw new DirectoryCreationException(
                    $"The creation of a directory '{path}' has failed (DirectoryNotFoundException). The specified path is invalid.");
            }
            catch (System.IO.IOException)
            {
                throw new DirectoryCreationException(
                    $"The creation of a directory '{path}' has failed (IOException). It is a file or the network name is not known");
            }
            catch (Exception x)
            {
                throw new DirectoryCreationException(
                    $"The creation of a directory '{path}' has failed due to an unexpected error ({x.GetType().Name}).");
            }
        }
    }

}
