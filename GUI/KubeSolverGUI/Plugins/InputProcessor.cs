using System;
using System.Collections.Generic;
using System.Threading;
using System.Windows.Forms;
using KubeSolverGUI.Utils.ExecutionUtil;

namespace KubeSolverGUI.Plugins
{
    public class SolverOutputProcessor
    {
        private readonly TextBox _textbox;
        private readonly Queue<string> queue = new Queue<string>();

        private Func<string, string> _lineAdjuster;

        public SolverOutputProcessor(TextBox textbox)
        {
            _textbox = textbox;
            var thread = new Thread(ProcessInputQueue)
            {
                IsBackground = true,
                Name = "TextProcessingThread"
            };
            thread.Start();
        }

        private void ProcessInputQueue()
        {
            while (true)
            {
                if (_textbox.Disposing || _textbox.IsDisposed) return;
                lock (queue)
                {
                    if (queue.Count > 0)
                    {
                        var lines = new List<string>();
                        while (queue.Count > 0)
                        {
                            var line = queue.Dequeue();
                            if (_lineAdjuster != null)
                            {
                                line = _lineAdjuster(line);
                            }
                            lines.Add(line);
                            lines.Add(Environment.NewLine);
                        }
                        _textbox.InvokeIfRequired(() => _textbox.AppendText(string.Join("", lines)));
                    }
                    else
                    {
                        Monitor.Wait(queue);
                    }
                }
            }
        }

        public void Wait()
        {
            lock (queue)
            {
                if (queue.Count > 0)
                {
                    Monitor.Wait(queue,100);
                }
            }
        }

        public void SetAdjuster(Func<string, string> adjuster)
        {
            _lineAdjuster = adjuster;
        }

        public void AddLine(string text)
        {
            lock (queue)
            {
                queue.Enqueue(text);
                Monitor.Pulse(queue);
            }
        }
    }
}