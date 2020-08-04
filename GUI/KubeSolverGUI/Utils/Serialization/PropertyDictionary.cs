using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using KubeSolverGUI.Utils.Exceptions;
using KubeSolverGUI.Utils.Strings;

namespace KubeSolverGUI.Utils.Serialization
{

    public class PropertyDictionary
    {
        private readonly Dictionary<string, string> _dict = new Dictionary<string, string>();

        private void Add(string key, string value)
        {
            DebugException.Assert(!key.Contains('#'));
            _dict.Add(key, value);
        }

        private string Get(string key)
        {
            if (_dict.ContainsKey(key)) return _dict[key];
            return null;
        }

        public static string EncodePropertyValue(string value)
        {
            if (value == null) return null;
            var lines = value.SplitIntoLines();
            return string.Join(@"\n", lines.Select(x => x.Replace(@"\", @"\\")));
        }

        /// <summary>
        /// Decodes escape sequences of a string like \n, \\ etc.
        /// </summary>
        /// <param name="value"></param>
        /// <returns></returns>
        public static string DecodePropertyValue(string value)
        {
            if (value == null) return null;

            var sb = new StringBuilder();
            for (int i = 0; i < value.Length; i++)
            {
                var ch = value[i];
                if (ch == '\\')
                {
                    if (value.Length == i + 1)
                    {
                        break;
                    }
                    if (value[i + 1] == 'n')
                    {
                        sb.AppendLine();
                    }
                    else if (value[i + 1] == '\\')
                    {
                        sb.Append(value[i + 1]);
                    }
                    else
                    {
                        DebugException.Fail("Ignored escaped character \\" + value[i + 1] + "  in  " + value);
                    }
                    i++;
                }
                else
                {
                    sb.Append(ch);
                }
            }
            return sb.ToString();
        }

        public List<string> ToLines()
        {
            var result = new List<string>();
            foreach (var kvp in _dict)
            {
                result.Add(kvp.Key + "#" + EncodePropertyValue(kvp.Value));
            }
            return result;
        }

        public static PropertyDictionary FromLines(IEnumerable<string> lines)
        {
            var result = new PropertyDictionary();
            foreach (var line in lines)
            {
                var splitPoint = line.IndexOf('#');
                if (splitPoint == -1) continue;
                var key = line.Substring(0, splitPoint);
                var value = line.Substring(splitPoint + 1);
                result.Add(key, DecodePropertyValue(value));
            }
            return result;
        }

        public class PrefixDictionary
        {
            private PropertyDictionary _parent;
            private string _prefix;

            public PrefixDictionary(PropertyDictionary parent, string prefix)
            {
                _parent = parent;
                _prefix = prefix;
            }

            public void Add(string key, string value)
            {
                _parent.Add(_prefix + key, value);
            }
            public void Add(string key, int value)
            {
                _parent.Add(_prefix + key, value.ToString());
            }


            public string GetString(string key)
            {
                return _parent.Get(_prefix + key);
            }

            public int GetInt(string key)
            {
                int.TryParse(_parent.Get(_prefix + key), out int result);
                return result;
            }

            public void DoWithPrefix(string prefix, Action<PrefixDictionary> action)
            {
                var prefixDict = new PrefixDictionary(this._parent, prefix + ".");
                action(prefixDict);
            }
        }

        public void Do(Action<PrefixDictionary> action)
        {
            var prefixDict = new PrefixDictionary(this, "");
            action(prefixDict);
        }
    }

}
