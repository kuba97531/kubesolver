using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.ComponentModel.Design;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace KubeSolverGUI.Utils.Controls
{
    [Designer("System.Windows.Forms.Design.ParentControlDesigner, System.Design", typeof(IDesigner))]
    [DefaultEvent("Paint")]
    public partial class KubeControl : UserControl
    {
        public KubeControl()
        {
            InitializeComponent();
            this.AutoScaleMode = AutoScaleMode.None;
        }

        protected override void OnLoad(EventArgs e)
        {
            base.OnLoad(e);
        }

        protected override bool DoubleBuffered => true;

        protected override CreateParams CreateParams
        {
            get
            {
                CreateParams cp = base.CreateParams;
                cp.ExStyle |= 0x02000000; // Turn on WS_EX_COMPOSITED
                return cp;
            }
        }

        protected override Point ScrollToControl(Control activeControl)
        {
            // Returning the current location prevents the panel from
            // scrolling to the active control when the panel loses and regains focus
            return this.DisplayRectangle.Location;
        }

        protected override void OnPaint(PaintEventArgs e)
        {
            if (DesignMode)
            {
                float[] dashValues = {5, 5};
                var blackPen = new Pen(Color.Gray, 2) {DashPattern = dashValues};
                e.Graphics.DrawRectangle(blackPen, this.ClientRectangle);
            }

            base.OnPaint(e);
        }

        protected override void OnSizeChanged(EventArgs e)
        {
            base.OnSizeChanged(e);
            this.Invalidate();
        }
    }
}
