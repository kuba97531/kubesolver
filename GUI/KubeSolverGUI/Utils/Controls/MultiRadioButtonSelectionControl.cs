using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace KubeSolverGUI.Utils.Controls
{
    [DefaultEvent("SelectedChanged")]
    public abstract class MultiRadioButtonSelectionControl<T> : KubeControl
    {
        protected MultiRadioButtonSelectionControl()
        {
            InitializeControls();
        }

        public abstract string GetTitle();

        public abstract List<Tuple<string, T>> GetItems();

        public event EventHandler SelectedChanged;

        private GroupBox groupBox;

        private List<RadioButtonWithValue> _radios;

        private Orientation _orientation;
        public Orientation Orientation
        {
            set
            {
                _orientation = value;
                foreach (var box in _radios)
                {
                    box.Dock = value == Orientation.Horizontal ? DockStyle.Left : DockStyle.Top;
                }
            }
            get => _orientation;
        }

        protected class RadioButtonWithValue : RadioButton
        {
            public RadioButtonWithValue(T t)
            {
                this.Value = t;
            }
            public T Value { get; }
        }

        private void InitializeControls()
        {
            groupBox = new GroupBox();

            _radios = new List<RadioButtonWithValue>();

            int index = 0;
            var itemCount = GetItems().Count;
            foreach (var item in Enumerable.Reverse(GetItems()))
            {
                // 
                // radio
                // 
                var radio = new RadioButtonWithValue(item.Item2)
                {
                    AutoSize = true,
                    Dock = DockStyle.Left,
                    Location = new Point(86, 16),
                    Name = "radio" + index++,
                    Size = new Size(46, 16),
                    TabIndex = itemCount - index,
                    Text = item.Item1,
                    UseVisualStyleBackColor = true,
                    Padding = new Padding(3)
                };
                radio.CheckedChanged += this.selectedPlayerRadio_CheckedChanged;
                _radios.Add(radio);
                this.groupBox.Controls.Add(radio);
            }

            this.Controls.Add(groupBox);

            // 
            // groupBox2
            // 
            this.groupBox.Dock = DockStyle.Fill;
            this.groupBox.Location = new Point(0, 0);
            this.groupBox.Name = "groupBox";
            this.groupBox.Size = new Size(143, 35);
            this.groupBox.TabIndex = 0;
            this.groupBox.TabStop = false;
            this.groupBox.Text = GetTitle();

        }

        public T GetSelectedItem()
        {
            foreach (var radio in _radios)
            {
                if (radio.Checked)
                {
                    return radio.Value;
                }
            }
            return default(T);
        }

        public void SetSelectedItem(T item)
        {
            foreach (var radio in _radios)
            {
                if (Equals(radio.Value, item))
                {
                    radio.Checked = true;
                }
            }
        }

        protected override void OnLoad(EventArgs e)
        {
            base.OnLoad(e);
            if (!_radios.Any(b => b.Checked))
            {
                _radios[0].Checked = true;
            }
        }

        private void selectedPlayerRadio_CheckedChanged(object sender, EventArgs e)
        {
            SelectedChanged?.Invoke(this, null);
        }

        public RadioButton GetRadioButtonForValue(T t)
        {
            foreach (var radio in _radios)
            {
                if (t.Equals(radio.Value)) return radio;
            }
            return null;
        }
    }
}
