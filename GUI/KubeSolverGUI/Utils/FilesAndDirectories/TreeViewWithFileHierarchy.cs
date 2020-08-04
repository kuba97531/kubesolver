using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Windows.Forms;
using KubeSolverGUI.Utils.Exceptions;

namespace KubeSolverGUI.Utils.FilesAndDirectories
{
    public class TreeViewWithFileHierarchy : TreeView
    {
        private SaveFileDialog saveFileDialog;
        private OpenFileDialog openFileDialog;

        public string _RootDirectory { get; set; }

        public delegate void ItemSelectedDelegate(string item);

        public event ItemSelectedDelegate _ItemSelected;

        public delegate void FileSelectedDelegate(string path);

        public event FileSelectedDelegate _FileSelected;

        public string _DefaultFileName { get; set; }

        public string _DefaultExtension
        {
            get => _defaultExtension ?? "txt";
            set => _defaultExtension = value;
        }

        public string _DefaultExtensionDescription
        {
            get => _defaultExtensionDescription ?? "Text files";
            set => _defaultExtensionDescription = value;
        }

        private TreeViewStore _store;
        private Comparison<FileInfo> _customSorting;
        private Func<FileInfo, string> _customFileNameRepresentation;

        public void SetCustomFileNameRepresentation(Func<FileInfo, string> customFileNameRepresentation)
        {
            _customFileNameRepresentation = customFileNameRepresentation;
            DebugException.Assert(_store == null, "_store == null");
        }

        public void SetCustomSorting(Comparison<FileInfo> customSorting)
        {
            _customSorting = customSorting;
            DebugException.Assert(_store == null, "_store == null");
        }


        public TreeViewWithFileHierarchy()
        {
            InitializeComponent();
        }

        private void InitializeComponent()
        {
            this.saveFileDialog = new SaveFileDialog();
            this.openFileDialog = new OpenFileDialog();
            this.SuspendLayout();
            // 
            // saveFileDialog
            // 
            this.saveFileDialog.SupportMultiDottedExtensions = true;
            this.saveFileDialog.OverwritePrompt = false;
            this.saveFileDialog.CreatePrompt = false;
            //
            // openFileDialog
            //
            this.saveFileDialog.SupportMultiDottedExtensions = true;
            this.saveFileDialog.OverwritePrompt = false;
            this.saveFileDialog.CreatePrompt = false;
            // 
            // TreeViewWithFileHierarchy
            // 
            this.LineColor = SystemColors.WindowText;
            this.ResumeLayout(false);
        }

        private void InitializePioViewerTreeView()
        {
            if (_store == null && _RootDirectory != null)
            {
                _store = new TreeViewStore(_RootDirectory, this, "*." + _defaultExtension, _customSorting, _customFileNameRepresentation);
                _store.FileSelected += _FileSelected;
                _store.ItemSelected += _ItemSelected;
            }
        }

        public void RebuildTree(string selectedPath)
        {
            _store.RebuildTree(selectedPath);
        }

        protected override void OnParentChanged(EventArgs e)
        {
            base.OnParentChanged(e);
            ReactOnParentChanged(this);
        }

        private void ReactOnParentChanged(Control control)
        {
            var parent = control.Parent;
            while (true)
            {
                if (parent is Form form)
                {
                    form.Load += (sender, args) => InitializePioViewerTreeView();
                    return;
                }
                if (parent == null)
                {
                    return;
                }
                if (parent.Parent == null)
                {
                    parent.ParentChanged += (sender, args) => ReactOnParentChanged(sender as Control);
                    return;
                }
                parent = parent.Parent;
            }

        }

        /// <summary>
        /// The class that helps populate tree view with directory contents 
        /// and sends events with the text content of a file when it is selected from the view
        /// </summary>
        private class TreeViewStore
        {
            private string RootDirectory { get; set; }

            private System.Windows.Forms.TreeView TreeView { get; set; }

            private string RecognizedFileExtensions { get; set; }

            public event ItemSelectedDelegate ItemSelected;

            public event FileSelectedDelegate FileSelected;

            private readonly Font _boldFont;

            private Comparison<FileInfo> CustomSorter { get; set; }

            private Func<FileInfo, string> CustomFileNameRepresentation { get; set; }

            private HashSet<string> ExpandedPaths
            {
                get
                {
                    if (this.RootDirectory != null)
                    {
                        if (!ExpandedPathsGlobalCache.ContainsKey(this.RootDirectory))
                        {
                            ExpandedPathsGlobalCache[this.RootDirectory] = new HashSet<string>();
                            //by default expand root
                            ExpandedPathsGlobalCache[this.RootDirectory].Add(Path.GetFullPath(RootDirectory));
                        }
                        return ExpandedPathsGlobalCache[this.RootDirectory];
                    }
                    else
                    {
                        return new HashSet<string>();
                    }
                }
            }

            private static Dictionary<string, HashSet<string>> ExpandedPathsGlobalCache =
                new Dictionary<string, HashSet<string>>();

            public TreeViewStore(string rootDictionary, TreeViewWithFileHierarchy view, string recognizedFileExtensions, Comparison<FileInfo> customSorting, Func<FileInfo, string> customFileNameRepresentation)
            {
                this.RootDirectory = rootDictionary;
                this.TreeView = view;
                this.RecognizedFileExtensions = recognizedFileExtensions;
                this.CustomSorter = customSorting;
                this.CustomFileNameRepresentation = customFileNameRepresentation;

                DirectoryUtil.CreateDirectory(rootDictionary);
                view.BeforeExpand += treeView1_BeforeExpand;
                view.AfterSelect += view_AfterSelect;
                view.AfterExpand += view_AfterExpand;
                view.AfterCollapse += view_AfterExpand;
                view.NodeMouseClick += view_NodeMouseClick;
                _boldFont = new Font(DefaultFont.FontFamily, DefaultFont.Size, FontStyle.Bold);
                RebuildTree(null);
            }

            private void view_AfterExpand(object sender, TreeViewEventArgs e)
            {
                Expand(e.Node.Nodes);
                UpdateExpansionOfSingleNode(e.Node);
            }

            private void UpdateExpansionOfSingleNode(TreeNode treeNode)
            {
                var tag = treeNode.Tag as string;
                if (treeNode.IsExpanded)
                {
                    ExpandedPaths.Add(tag);
                }
                else
                {
                    ExpandedPaths.Remove(tag);
                }
            }

            private void UpdateExpanded(TreeNodeCollection nodes)
            {
                foreach (var node in nodes)
                {
                    var treeNode = (TreeNode)node;
                    UpdateExpansionOfSingleNode(treeNode);
                    UpdateExpanded(treeNode.Nodes);
                }
            }

            private void Expand(TreeNodeCollection nodes)
            {
                foreach (var node in nodes)
                {
                    var treeNode = (TreeNode)node;
                    if (ExpandedPaths.Contains(treeNode.Tag as string))
                    {
                        treeNode.Expand();
                        Expand(treeNode.Nodes);
                    }
                }
            }

            public void RebuildTree(string selectedPath)
            {
                _lastSelectedPath = selectedPath;
                UpdateExpanded(TreeView.Nodes);
                TreeView.Nodes.Clear();
                TreeNode root = new TreeNode(Path.GetFileName(RootDirectory));
                root.Tag = Path.GetFullPath(RootDirectory); // for later reference
                root.Nodes.Clear();
                root.Nodes.Add(new TreeNode()); // add dummy node to allow expansion
                TreeView.Nodes.Add(root);
                Expand(TreeView.Nodes);
            }

            private TreeNode _lastSelectedNode;
            private string _lastSelectedPath;

            private void FileNodeSelected(TreeNode node)
            {
                if (_lastSelectedNode != null)
                {
                    _lastSelectedNode.NodeFont = null;
                    // this seemingly useless assignment has an effect of refreshing the size, which doesn't happen itself when we change nodeFont.
                    _lastSelectedNode.Text = _lastSelectedNode.Text;
                }
                _lastSelectedNode = node;
                node.NodeFont = _boldFont;
                // see comment above
                node.Text = node.Text;
                _lastSelectedPath = node.Tag as string;
            }

            private TreeNode _lastMouseClick;

            private void view_NodeMouseClick(object sender, TreeNodeMouseClickEventArgs e)
            {
                NodeSelect(e.Node);
                _lastMouseClick = e.Node;
            }

            private void view_AfterSelect(object sender, TreeViewEventArgs e)
            {
                if (_lastMouseClick != e.Node)
                {
                    NodeSelect(e.Node);
                }
                _lastMouseClick = null;
            }

            private void NodeSelect(TreeNode node)
            {
                try
                {
                    string path = (string)node.Tag;
                    if (File.Exists(path))
                    {
                        FileNodeSelected(node);
                        if (ItemSelected != null)
                        {
                            var item = File.ReadAllText(path);
                            ItemSelected(item);
                        }
                        FileSelected?.Invoke(path);
                    }
                }
                catch (Exception ex)
                {
                    Console.WriteLine(ex);
                    //what you can do mate?
                }
            }


            private void treeView1_BeforeExpand(object sender, TreeViewCancelEventArgs e)
            {
                if (e.Node.Tag != null)
                {
                    AddDirectoriesAndFiles(e.Node, (string)e.Node.Tag);
                }
            }

            private void AddDirectoriesAndFiles(TreeNode node, string path)
            {
                node.Nodes.Clear(); // clear dummy node if exists

                try
                {
                    DirectoryInfo currentDir = new DirectoryInfo(path);
                    DirectoryInfo[] subdirs = currentDir.GetDirectories();

                    foreach (DirectoryInfo subdir in subdirs)
                    {
                        TreeNode child = new TreeNode(subdir.Name);
                        child.Tag = subdir.FullName; // save full path in tag

                        child.Nodes.Add(new TreeNode()); // add dummy node to allow expansion
                        node.Nodes.Add(child);
                    }

                    List<FileInfo> files = new List<FileInfo>();
                    files.AddRange(currentDir.GetFiles(RecognizedFileExtensions));

                    if (CustomSorter != null)
                    {
                        files.Sort(CustomSorter);
                    }

                    foreach (FileInfo file in files)
                    {
                        string nodeText;
                        if (CustomFileNameRepresentation != null)
                        {
                            nodeText = CustomFileNameRepresentation(file);
                        }
                        else
                        {
                            var fileNameWithoutExtension = Path.GetFileNameWithoutExtension(file.Name);
                            nodeText = fileNameWithoutExtension;
                        }

                        TreeNode child = new TreeNode(nodeText);
                        child.Tag = file.FullName; // save full path for later use
                        if (file.FullName == _lastSelectedPath)
                        {
                            child.NodeFont = _boldFont;
                            _lastSelectedNode = child;
                        }
                        node.Nodes.Add(child);
                    }
                }
                catch
                {
                    // try to handle use each exception separately
                }
            }
        }

        private string _lastSavedDirectory;
        private string _defaultExtension;
        private string _defaultExtensionDescription;

        /// <summary>
        /// Prompts user to specify location to save file
        /// </summary>
        /// <returns></returns>
        public string ShowFileDialogAndGetSaveLocation()
        {
            return OpenDialogAndGetFileName(saveFileDialog);
        }


        private string OpenDialogAndGetFileName(FileDialog fileDialog)
        {
            fileDialog.InitialDirectory = _lastSavedDirectory ?? Path.GetFullPath(_RootDirectory);
            fileDialog.FileName = _DefaultFileName + "." + _DefaultExtension;
            fileDialog.Filter = _DefaultExtensionDescription + "|*." + _DefaultExtension;
            fileDialog.DefaultExt = _DefaultExtension;
            var result = fileDialog.ShowDialog();
            if (result == DialogResult.OK)
            {
                _lastSavedDirectory = Path.GetDirectoryName(fileDialog.FileName);
                return fileDialog.FileName;
            }
            return null;
        }

        public string ShowLoadFileDialogAndGetFileName()
        {
            return OpenDialogAndGetFileName(openFileDialog);
        }
    }
}
