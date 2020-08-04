using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace KubeSolverGUI.Utils.Serialization
{
    public enum GetOrSet
    {
        Get,
        Set
    }

    public static class SerializationUtil
    {
        public static void GetOrSetTextInTextBox(PropertyDictionary.PrefixDictionary dict, string key, TextBox textBox, GetOrSet mode)
        {
            if (mode == GetOrSet.Get)
            {
                dict.Add(key, textBox.Text);
            }
            else
            {
                textBox.Text = dict.GetString(key);
            }
        }

        public static void GetOrSetControlValue(PropertyDictionary.PrefixDictionary dict, string key, ISerializableControl control, GetOrSet mode)
        {
            control.GetOrSetInDictionary(dict, key, mode);
        }
    }

    public interface ISerializableControl
    {
        void GetOrSetInDictionary(PropertyDictionary.PrefixDictionary dict, string key, GetOrSet mode);
    }
}

