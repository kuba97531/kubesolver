using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Threading;
using System.Windows.Forms;
using System.Windows.Forms.VisualStyles;
using KubeSolverGUI.Utils.Drawing;
using KubeSolverGUI.Utils.Exceptions;

namespace KubeSolverGUI.Utils.ExecutionUtil
{

    public class IdleWorkingControl : UserControl
    {
        public IdleWorkingControl()
        {
            InitializeComponent();
        }

        /// <summary> 
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary> 
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.infoLabel = new IdleWorkingControl.LabelWithDelay();
            this.cancelButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // infoLabel
            // 
            this.infoLabel.AutoSize = true;
            this.infoLabel.Delay = 100;
            this.infoLabel.Dock = System.Windows.Forms.DockStyle.Right;
            this.infoLabel.Location = new System.Drawing.Point(157, 0);
            this.infoLabel.Name = "infoLabel";
            this.infoLabel.Size = new System.Drawing.Size(10, 13);
            this.infoLabel.TabIndex = 0;
            this.infoLabel.Text = "-";
            // 
            // cancelButton
            // 
            this.cancelButton.Dock = System.Windows.Forms.DockStyle.Right;
            this.cancelButton.Enabled = false;
            this.cancelButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.cancelButton.Location = new System.Drawing.Point(167, 0);
            this.cancelButton.Margin = new System.Windows.Forms.Padding(0);
            this.cancelButton.Name = "cancelButton";
            this.cancelButton.Size = new System.Drawing.Size(54, 19);
            this.cancelButton.TabIndex = 1;
            this.cancelButton.UseVisualStyleBackColor = true;
            this.cancelButton.Visible = false;
            this.cancelButton.Click += new System.EventHandler(this.cancelButton_Click);
            this.cancelButton.Paint += new System.Windows.Forms.PaintEventHandler(this.CancelButton_Paint);
            // 
            // IdleWorkingControl
            // 
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.None;
            this.Controls.Add(this.infoLabel);
            this.Controls.Add(this.cancelButton);
            this.MaximumSize = new System.Drawing.Size(3000, 19);
            this.Name = "IdleWorkingControl";
            this.Size = new System.Drawing.Size(221, 19);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion


        public static void InvokeIfRequired(Control control, MethodInvoker action, bool waitForJoin = false)
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

        private class LabelWithDelay : Label
        {
            public int Delay { get; set; }

            private DateTime _lastDisplay = DateTime.Now;
            private string _stringToUpdate;
            public LabelWithDelay()
            {
                _updateThread = new Thread(UpdateInALoop) { Name = "BGT: Update label of an idle control." };
                _updateThread.Start();
            }

            private void UpdateInALoop()
            {
                while (!this.IsDisposed)
                {
                    var now = DateTime.Now;
                    if (_stringToUpdate != null && (now - _lastDisplay).TotalMilliseconds > this.Delay)
                    {
                        string value;
                        lock (this)
                        {
                            value = _stringToUpdate;
                            _stringToUpdate = null;
                            _lastDisplay = now;
                        }
                        InvokeIfRequired(this, () =>
                         {
                             this.Text = value;
                         });
                    }
                    else
                    {
                        lock (this)
                        {
                            Monitor.Wait(this, Delay);
                        }
                    }
                }
            }

            public void SetDelayedText(string value)
            {
                lock (this)
                {
                    _stringToUpdate = value;
                    Monitor.Pulse(this);
                }
            }

            public void SetTextImmediately(string value)
            {
                lock (this)
                {
                    _stringToUpdate = value;
                    _lastDisplay = DateTime.MinValue;
                    Monitor.Pulse(this);
                }
            }

            private Thread _updateThread;

        }

        private LabelWithDelay infoLabel;
        private System.Windows.Forms.Button cancelButton;

        public override Size GetPreferredSize(Size proposedSize)
        {
            return new Size(infoLabel.Width + 60, 18);
        }

        public class IdleExecutionConfiguration
        {
            public Func<Control, bool> NonDisableControls { get; set; }

            public Action<IProgressProvider> ProgressUpdated { get; set; }
        }

        /// <summary>
        /// True if there is currently job executed by the control
        /// </summary>
        private bool _isWorking;
        public bool IsWorking => _isWorking;

        private object _locker = new object();
        private Thread _executionThread;
        public void Execute(Action<IProgressProvider> action, IdleExecutionConfiguration config = null, Action postProcessAction = null)
        {
            if (Thread.CurrentThread == _executionThread)
            {
                action(_currentProgressProvider);
                return;
            }

            void wrappedAction()
            {
                lock (_locker)
                {
                    ExecutionWrapper.RunAction(() => { ExecuteAction(action, config, postProcessAction); });
                }
            }

            _executionThread = new Thread(wrappedAction)
            {
                Name = "Idle Execution Thread",
                IsBackground = true
            };
            _executionThread.Start();
        }

        private class IdleWorkingControlPluginProgressProvider : IProgressProvider
        {
            private IdleWorkingControl _parent;

            public IdleWorkingControlPluginProgressProvider(IdleWorkingControl parent)
            {
                _parent = parent;
                CancelReason = 0;
            }

            public void UpdateProgress(string message, params object[] arguments)
            {
                _parent.infoLabel.SetDelayedText(string.Format(message, arguments));
                OnProgressUpdated?.Invoke(this);
            }

            public void CancelRequest(ProgressCancelEnum cancelReason)
            {
                CancelReason = cancelReason;
                OnProgressUpdated?.Invoke(this);
            }

            public event Action<IProgressProvider> OnProgressUpdated;

            public ProgressCancelEnum CancelReason { get; private set; }

            public bool CancelRequested => CancelReason > 0;

            /// <summary>
            /// Can be used both ways to communicate between a form and a working thread
            /// </summary>
            private object _status;
            public object Status
            {
                get => _status;
                set
                {
                    _status = value;
                    OnProgressUpdated?.Invoke(this);
                }
            }

            public void InvokeInGUIThread(MethodInvoker action)
            {
                _parent.InvokeIfRequired(action);
            }
        }
        private IdleWorkingControlPluginProgressProvider _currentProgressProvider;

        private bool ShouldDisableControl(Control control, IdleExecutionConfiguration config)
        {
            if (control.Enabled == false) return false;
            if (control == this) return false;
            if (control == cancelButton) return false;
            if (control == infoLabel) return false;
            if (config != null && config.NonDisableControls(control)) return false;
            return true;
        }

        private IEnumerable<Control> DisableControls(Control c, IdleExecutionConfiguration config)
        {
            if (ShouldDisableControl(c, config))
            {
                if (c is Button || c is TextBox || c is MenuStrip)
                {
                    c.Enabled = false;
                    yield return c;
                }
                else
                {
                    foreach (var child in c.Controls)
                    {
                        foreach (var disabledControl in DisableControls((Control)child, config))
                        {
                            yield return disabledControl;
                        }
                    }
                }
            }
        }

        private void ExecuteAction(Action<IProgressProvider> action, IdleExecutionConfiguration config, Action postProcessAction)
        {
            bool visibleOnStart = this.Visible;
            _isWorking = true;
            var disabledControls = new List<Control>();
            try
            {
                InvokeIfRequired(this, () =>
                 {
                     disabledControls = DisableControls(config);
                 }, true);
                _currentProgressProvider = new IdleWorkingControlPluginProgressProvider(this);
                if (config?.ProgressUpdated != null)
                {
                    _currentProgressProvider.OnProgressUpdated += config.ProgressUpdated;
                }

                action(_currentProgressProvider);
            }
            finally
            {
                this.InvokeIfRequired(() =>
                {
                    EnableControls(disabledControls, visibleOnStart);
                });
                _isWorking = false;
                Monitor.Pulse(_locker);
            }
            postProcessAction?.Invoke();
        }

        private void EnableControls(List<Control> disabledControls, bool visibleOnStart)
        {
            foreach (var control in disabledControls)
            {
                control.Enabled = true;
            }
            this.infoLabel.SetTextImmediately("Done");
            _currentProgressProvider = null;
            this.cancelButton.Visible = false;
            this.cancelButton.Enabled = false;
            this.Visible = visibleOnStart;
        }

        private List<Control> DisableControls(IdleExecutionConfiguration config)
        {
            this.cancelButton.Visible = true;
            this.cancelButton.Enabled = true;
            this.infoLabel.SetTextImmediately("Working...");
            this.Visible = true;
            DebugException.AssertNotNull(ParentForm, "ParentForm");
            return DisableControls(ParentForm, config).ToList();
        }

        public void CancelRequest(ProgressCancelEnum code)
        {
            if (_currentProgressProvider != null)
            {
                _currentProgressProvider.CancelRequest(code);
                cancelButton.Enabled = false;
            }
        }

        private void cancelButton_Click(object sender, EventArgs e)
        {
            DebugException.AssertNotNull(_currentProgressProvider, "_currentProgressProvider != null");
            _currentProgressProvider.CancelRequest(ProgressCancelEnum.Cancel);
            cancelButton.Enabled = false;
        }

        private void CancelButton_Paint(object sender, PaintEventArgs e)
        {
            var r = cancelButton.ClientRectangle;
            ButtonRenderer.DrawButton(e.Graphics, r, PushButtonState.Normal);

            if (cancelButton.Enabled)
            {
                DrawingUtils.DrawAlignedString(e.Graphics, "cancel", "cancel", cancelButton.ClientRectangle,
                    StringAlignment.Center, StringAlignment.Center);
            }
            else
            {
                DrawingUtils.DrawAlignedString(e.Graphics, "cancel", "cancel", cancelButton.ClientRectangle,
                    StringAlignment.Center, StringAlignment.Center, SystemBrushes.InactiveCaption);
            }
        }
    }
}
