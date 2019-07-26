namespace MapEditor
{
    partial class Form1
    {
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

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.subMenu_New = new System.Windows.Forms.ToolStripMenuItem();
            this.subMenu_OpenImage = new System.Windows.Forms.ToolStripMenuItem();
            this.subMenu_OpenFile = new System.Windows.Forms.ToolStripMenuItem();
            this.editToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.subMenu_DeleteObject = new System.Windows.Forms.ToolStripMenuItem();
            this.panel1 = new System.Windows.Forms.Panel();
            this.gr_object = new System.Windows.Forms.GroupBox();
            this.cb_directStair = new System.Windows.Forms.ComboBox();
            this.btnSaveQuadTree = new System.Windows.Forms.Button();
            this.check_deleteObject = new System.Windows.Forms.CheckBox();
            this.cb_typeObject = new System.Windows.Forms.ComboBox();
            this.txt_H = new System.Windows.Forms.TextBox();
            this.label13 = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.txt_W = new System.Windows.Forms.TextBox();
            this.txt_Y = new System.Windows.Forms.TextBox();
            this.label9 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.txt_X = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.gr_map = new System.Windows.Forms.GroupBox();
            this.btnDeleteAllObjects = new System.Windows.Forms.Button();
            this.txt_Size = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.btn_Excute = new System.Windows.Forms.Button();
            this.txt_height = new System.Windows.Forms.TextBox();
            this.txt_width = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label = new System.Windows.Forms.Label();
            this.btnHide = new System.Windows.Forms.Button();
            this.imageListObjects = new System.Windows.Forms.ImageList(this.components);
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.location = new System.Windows.Forms.ToolStripStatusLabel();
            this.worldSpace = new MapEditor.ImageBox();
            this.viewToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exportObjectsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.menuStrip1.SuspendLayout();
            this.panel1.SuspendLayout();
            this.gr_object.SuspendLayout();
            this.gr_map.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).BeginInit();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            this.statusStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.viewToolStripMenuItem,
            this.editToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Padding = new System.Windows.Forms.Padding(4, 2, 0, 2);
            this.menuStrip1.Size = new System.Drawing.Size(1168, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            this.menuStrip1.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.menuStrip1_KeyPress);
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.subMenu_New,
            this.subMenu_OpenImage,
            this.subMenu_OpenFile,
            this.toolStripSeparator1,
            this.exportObjectsToolStripMenuItem,
            this.toolStripSeparator2});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.fileToolStripMenuItem.Text = "&File";
            // 
            // subMenu_New
            // 
            this.subMenu_New.Image = global::MapEditor.Properties.Resources.ico_new;
            this.subMenu_New.Name = "subMenu_New";
            this.subMenu_New.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.N)));
            this.subMenu_New.Size = new System.Drawing.Size(203, 26);
            this.subMenu_New.Text = "New";
            // 
            // subMenu_OpenImage
            // 
            this.subMenu_OpenImage.Image = global::MapEditor.Properties.Resources.ico_open;
            this.subMenu_OpenImage.Name = "subMenu_OpenImage";
            this.subMenu_OpenImage.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.O)));
            this.subMenu_OpenImage.Size = new System.Drawing.Size(203, 26);
            this.subMenu_OpenImage.Text = "Open Image";
            this.subMenu_OpenImage.Click += new System.EventHandler(this.subMenu_Open_Click);
            // 
            // subMenu_OpenFile
            // 
            this.subMenu_OpenFile.Image = global::MapEditor.Properties.Resources.icon_OpenFile;
            this.subMenu_OpenFile.Name = "subMenu_OpenFile";
            this.subMenu_OpenFile.ShortcutKeys = ((System.Windows.Forms.Keys)(((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Shift) 
            | System.Windows.Forms.Keys.O)));
            this.subMenu_OpenFile.Size = new System.Drawing.Size(203, 26);
            this.subMenu_OpenFile.Text = "Open File";
            this.subMenu_OpenFile.Click += new System.EventHandler(this.subMenu_OpenFile_Click);
            // 
            // editToolStripMenuItem
            // 
            this.editToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.subMenu_DeleteObject});
            this.editToolStripMenuItem.Name = "editToolStripMenuItem";
            this.editToolStripMenuItem.Size = new System.Drawing.Size(39, 20);
            this.editToolStripMenuItem.Text = "&Edit";
            // 
            // subMenu_DeleteObject
            // 
            this.subMenu_DeleteObject.Name = "subMenu_DeleteObject";
            this.subMenu_DeleteObject.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.D)));
            this.subMenu_DeleteObject.Size = new System.Drawing.Size(187, 22);
            this.subMenu_DeleteObject.Text = "Delete Object";
            this.subMenu_DeleteObject.Click += new System.EventHandler(this.subMenu_DeleteObject_Click);
            // 
            // panel1
            // 
            this.panel1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel1.Controls.Add(this.gr_object);
            this.panel1.Controls.Add(this.gr_map);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panel1.Location = new System.Drawing.Point(0, 0);
            this.panel1.Margin = new System.Windows.Forms.Padding(2);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(265, 537);
            this.panel1.TabIndex = 1;
            // 
            // gr_object
            // 
            this.gr_object.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.gr_object.Controls.Add(this.cb_directStair);
            this.gr_object.Controls.Add(this.btnSaveQuadTree);
            this.gr_object.Controls.Add(this.check_deleteObject);
            this.gr_object.Controls.Add(this.cb_typeObject);
            this.gr_object.Controls.Add(this.txt_H);
            this.gr_object.Controls.Add(this.label13);
            this.gr_object.Controls.Add(this.label12);
            this.gr_object.Controls.Add(this.label11);
            this.gr_object.Controls.Add(this.label10);
            this.gr_object.Controls.Add(this.txt_W);
            this.gr_object.Controls.Add(this.txt_Y);
            this.gr_object.Controls.Add(this.label9);
            this.gr_object.Controls.Add(this.label8);
            this.gr_object.Controls.Add(this.label7);
            this.gr_object.Controls.Add(this.txt_X);
            this.gr_object.Controls.Add(this.label6);
            this.gr_object.Location = new System.Drawing.Point(11, 220);
            this.gr_object.Margin = new System.Windows.Forms.Padding(2);
            this.gr_object.Name = "gr_object";
            this.gr_object.Padding = new System.Windows.Forms.Padding(2);
            this.gr_object.Size = new System.Drawing.Size(244, 306);
            this.gr_object.TabIndex = 2;
            this.gr_object.TabStop = false;
            this.gr_object.Text = "Object";
            // 
            // cb_directStair
            // 
            this.cb_directStair.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cb_directStair.FormattingEnabled = true;
            this.cb_directStair.Items.AddRange(new object[] {
            "Left to Right ->",
            "Right to Left <-"});
            this.cb_directStair.Location = new System.Drawing.Point(32, 158);
            this.cb_directStair.Margin = new System.Windows.Forms.Padding(2);
            this.cb_directStair.Name = "cb_directStair";
            this.cb_directStair.Size = new System.Drawing.Size(165, 21);
            this.cb_directStair.TabIndex = 8;
            this.cb_directStair.Visible = false;
            // 
            // btnSaveQuadTree
            // 
            this.btnSaveQuadTree.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.btnSaveQuadTree.Location = new System.Drawing.Point(69, 204);
            this.btnSaveQuadTree.Margin = new System.Windows.Forms.Padding(2);
            this.btnSaveQuadTree.Name = "btnSaveQuadTree";
            this.btnSaveQuadTree.Size = new System.Drawing.Size(108, 28);
            this.btnSaveQuadTree.TabIndex = 7;
            this.btnSaveQuadTree.Text = "Save QuadTree";
            this.btnSaveQuadTree.UseVisualStyleBackColor = true;
            this.btnSaveQuadTree.Visible = false;
            this.btnSaveQuadTree.Click += new System.EventHandler(this.btnSaveQuadTree_Click);
            // 
            // check_deleteObject
            // 
            this.check_deleteObject.AutoSize = true;
            this.check_deleteObject.Location = new System.Drawing.Point(32, 182);
            this.check_deleteObject.Margin = new System.Windows.Forms.Padding(2);
            this.check_deleteObject.Name = "check_deleteObject";
            this.check_deleteObject.Size = new System.Drawing.Size(91, 17);
            this.check_deleteObject.TabIndex = 6;
            this.check_deleteObject.Text = "Delete Object";
            this.check_deleteObject.UseVisualStyleBackColor = true;
            // 
            // cb_typeObject
            // 
            this.cb_typeObject.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.cb_typeObject.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cb_typeObject.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cb_typeObject.FormattingEnabled = true;
            this.cb_typeObject.Items.AddRange(new object[] {
            "GROUND",
            "ROPE",
            "WALL",
            "LEVERAGE",
            "COLUMN",
            "BAR",
            "CAMEL",
            "GUARDS1",
            "GUARDS2",
            "GUARDS3",
            "CIVILIAN1",
            "CIVILIAN2",
            "CIVILIAN3",
            "CIVILIAN4",
            "PEDDLER",
            "APPLEITEM",
            "TEAPOTITEM",
            "GENIEITEM",
            "BALLITEM",
            "ALADDINITEM",
            "HEARTITEM",
            "MONKEYITEM",
            "JARITEM",
            "STAIR",
            "GROUND_DROP",
            "STICKITEM",
            "TRAP",
            "JAFAR"});
            this.cb_typeObject.Location = new System.Drawing.Point(32, 130);
            this.cb_typeObject.Margin = new System.Windows.Forms.Padding(2);
            this.cb_typeObject.Name = "cb_typeObject";
            this.cb_typeObject.Size = new System.Drawing.Size(166, 24);
            this.cb_typeObject.TabIndex = 5;
            this.cb_typeObject.SelectedIndexChanged += new System.EventHandler(this.cb_typeObject_SelectedIndexChanged);
            // 
            // txt_H
            // 
            this.txt_H.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.txt_H.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txt_H.Location = new System.Drawing.Point(32, 104);
            this.txt_H.Margin = new System.Windows.Forms.Padding(2);
            this.txt_H.Name = "txt_H";
            this.txt_H.Size = new System.Drawing.Size(166, 23);
            this.txt_H.TabIndex = 4;
            // 
            // label13
            // 
            this.label13.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.label13.AutoSize = true;
            this.label13.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label13.Location = new System.Drawing.Point(199, 109);
            this.label13.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(31, 17);
            this.label13.TabIndex = 4;
            this.label13.Text = "Cell";
            // 
            // label12
            // 
            this.label12.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.label12.AutoSize = true;
            this.label12.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label12.Location = new System.Drawing.Point(199, 83);
            this.label12.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(31, 17);
            this.label12.TabIndex = 4;
            this.label12.Text = "Cell";
            // 
            // label11
            // 
            this.label11.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.label11.AutoSize = true;
            this.label11.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label11.Location = new System.Drawing.Point(199, 54);
            this.label11.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(31, 17);
            this.label11.TabIndex = 4;
            this.label11.Text = "Cell";
            // 
            // label10
            // 
            this.label10.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.label10.AutoSize = true;
            this.label10.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label10.Location = new System.Drawing.Point(199, 28);
            this.label10.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(31, 17);
            this.label10.TabIndex = 4;
            this.label10.Text = "Cell";
            // 
            // txt_W
            // 
            this.txt_W.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.txt_W.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txt_W.Location = new System.Drawing.Point(32, 78);
            this.txt_W.Margin = new System.Windows.Forms.Padding(2);
            this.txt_W.Name = "txt_W";
            this.txt_W.Size = new System.Drawing.Size(166, 23);
            this.txt_W.TabIndex = 4;
            // 
            // txt_Y
            // 
            this.txt_Y.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.txt_Y.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txt_Y.Location = new System.Drawing.Point(32, 52);
            this.txt_Y.Margin = new System.Windows.Forms.Padding(2);
            this.txt_Y.Name = "txt_Y";
            this.txt_Y.Size = new System.Drawing.Size(166, 23);
            this.txt_Y.TabIndex = 4;
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label9.Location = new System.Drawing.Point(14, 106);
            this.label9.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(18, 17);
            this.label9.TabIndex = 3;
            this.label9.Text = "H";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label8.Location = new System.Drawing.Point(14, 80);
            this.label8.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(21, 17);
            this.label8.TabIndex = 3;
            this.label8.Text = "W";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label7.Location = new System.Drawing.Point(14, 54);
            this.label7.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(17, 17);
            this.label7.TabIndex = 3;
            this.label7.Text = "Y";
            // 
            // txt_X
            // 
            this.txt_X.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.txt_X.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txt_X.Location = new System.Drawing.Point(32, 26);
            this.txt_X.Margin = new System.Windows.Forms.Padding(2);
            this.txt_X.Name = "txt_X";
            this.txt_X.Size = new System.Drawing.Size(166, 23);
            this.txt_X.TabIndex = 4;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.Location = new System.Drawing.Point(14, 28);
            this.label6.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(17, 17);
            this.label6.TabIndex = 3;
            this.label6.Text = "X";
            // 
            // gr_map
            // 
            this.gr_map.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.gr_map.Controls.Add(this.btnDeleteAllObjects);
            this.gr_map.Controls.Add(this.txt_Size);
            this.gr_map.Controls.Add(this.label2);
            this.gr_map.Controls.Add(this.label5);
            this.gr_map.Controls.Add(this.label1);
            this.gr_map.Controls.Add(this.btn_Excute);
            this.gr_map.Controls.Add(this.txt_height);
            this.gr_map.Controls.Add(this.txt_width);
            this.gr_map.Controls.Add(this.label3);
            this.gr_map.Controls.Add(this.label4);
            this.gr_map.Controls.Add(this.label);
            this.gr_map.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.gr_map.Location = new System.Drawing.Point(11, 23);
            this.gr_map.Margin = new System.Windows.Forms.Padding(2);
            this.gr_map.Name = "gr_map";
            this.gr_map.Padding = new System.Windows.Forms.Padding(2);
            this.gr_map.Size = new System.Drawing.Size(244, 193);
            this.gr_map.TabIndex = 0;
            this.gr_map.TabStop = false;
            this.gr_map.Text = "Map";
            // 
            // btnDeleteAllObjects
            // 
            this.btnDeleteAllObjects.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.btnDeleteAllObjects.Location = new System.Drawing.Point(141, 160);
            this.btnDeleteAllObjects.Margin = new System.Windows.Forms.Padding(2);
            this.btnDeleteAllObjects.Name = "btnDeleteAllObjects";
            this.btnDeleteAllObjects.Size = new System.Drawing.Size(56, 28);
            this.btnDeleteAllObjects.TabIndex = 6;
            this.btnDeleteAllObjects.Text = "Refresh";
            this.btnDeleteAllObjects.UseVisualStyleBackColor = true;
            this.btnDeleteAllObjects.Click += new System.EventHandler(this.btnDeleteAllObjects_Click);
            // 
            // txt_Size
            // 
            this.txt_Size.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.txt_Size.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txt_Size.Location = new System.Drawing.Point(62, 30);
            this.txt_Size.Margin = new System.Windows.Forms.Padding(2);
            this.txt_Size.Name = "txt_Size";
            this.txt_Size.Size = new System.Drawing.Size(121, 23);
            this.txt_Size.TabIndex = 0;
            this.txt_Size.Text = "32";
            this.txt_Size.TextChanged += new System.EventHandler(this.txt_Size_TextChanged);
            this.txt_Size.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txt_Size_KeyPress);
            // 
            // label2
            // 
            this.label2.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(185, 113);
            this.label2.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(36, 17);
            this.label2.TabIndex = 4;
            this.label2.Text = "pixel";
            // 
            // label5
            // 
            this.label5.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.Location = new System.Drawing.Point(185, 32);
            this.label5.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(36, 17);
            this.label5.TabIndex = 4;
            this.label5.Text = "pixel";
            // 
            // label1
            // 
            this.label1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(185, 72);
            this.label1.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(36, 17);
            this.label1.TabIndex = 4;
            this.label1.Text = "pixel";
            // 
            // btn_Excute
            // 
            this.btn_Excute.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.btn_Excute.Location = new System.Drawing.Point(49, 160);
            this.btn_Excute.Margin = new System.Windows.Forms.Padding(2);
            this.btn_Excute.Name = "btn_Excute";
            this.btn_Excute.Size = new System.Drawing.Size(56, 28);
            this.btn_Excute.TabIndex = 3;
            this.btn_Excute.Text = "Excute";
            this.btn_Excute.UseVisualStyleBackColor = true;
            this.btn_Excute.Click += new System.EventHandler(this.btn_Excute_Click);
            // 
            // txt_height
            // 
            this.txt_height.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.txt_height.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txt_height.Location = new System.Drawing.Point(62, 113);
            this.txt_height.Margin = new System.Windows.Forms.Padding(2);
            this.txt_height.Name = "txt_height";
            this.txt_height.Size = new System.Drawing.Size(121, 23);
            this.txt_height.TabIndex = 2;
            this.txt_height.Text = "32";
            this.txt_height.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txt_height_KeyPress);
            // 
            // txt_width
            // 
            this.txt_width.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.txt_width.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txt_width.Location = new System.Drawing.Point(62, 72);
            this.txt_width.Margin = new System.Windows.Forms.Padding(2);
            this.txt_width.Name = "txt_width";
            this.txt_width.Size = new System.Drawing.Size(121, 23);
            this.txt_width.TabIndex = 1;
            this.txt_width.Text = "32";
            this.txt_width.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txt_width_KeyPress);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(11, 113);
            this.label3.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(47, 17);
            this.label3.TabIndex = 0;
            this.label3.Text = "height";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(11, 32);
            this.label4.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(35, 17);
            this.label4.TabIndex = 0;
            this.label4.Text = "Size";
            // 
            // label
            // 
            this.label.AutoSize = true;
            this.label.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label.Location = new System.Drawing.Point(11, 72);
            this.label.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label.Name = "label";
            this.label.Size = new System.Drawing.Size(40, 17);
            this.label.TabIndex = 0;
            this.label.Text = "width";
            // 
            // btnHide
            // 
            this.btnHide.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnHide.Location = new System.Drawing.Point(1104, 0);
            this.btnHide.Margin = new System.Windows.Forms.Padding(2);
            this.btnHide.Name = "btnHide";
            this.btnHide.Size = new System.Drawing.Size(43, 23);
            this.btnHide.TabIndex = 3;
            this.btnHide.Text = ">>";
            this.btnHide.UseVisualStyleBackColor = true;
            this.btnHide.Click += new System.EventHandler(this.btnHide_Click);
            // 
            // imageListObjects
            // 
            this.imageListObjects.ColorDepth = System.Windows.Forms.ColorDepth.Depth8Bit;
            this.imageListObjects.ImageSize = new System.Drawing.Size(64, 64);
            this.imageListObjects.TransparentColor = System.Drawing.Color.Transparent;
            // 
            // splitContainer1
            // 
            this.splitContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer1.Location = new System.Drawing.Point(0, 24);
            this.splitContainer1.Margin = new System.Windows.Forms.Padding(2);
            this.splitContainer1.Name = "splitContainer1";
            // 
            // splitContainer1.Panel1
            // 
            this.splitContainer1.Panel1.Controls.Add(this.statusStrip1);
            this.splitContainer1.Panel1.Controls.Add(this.worldSpace);
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.Controls.Add(this.panel1);
            this.splitContainer1.Panel2MinSize = 0;
            this.splitContainer1.Size = new System.Drawing.Size(1168, 537);
            this.splitContainer1.SplitterDistance = 900;
            this.splitContainer1.SplitterWidth = 3;
            this.splitContainer1.TabIndex = 4;
            // 
            // statusStrip1
            // 
            this.statusStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.location});
            this.statusStrip1.Location = new System.Drawing.Point(0, 515);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Padding = new System.Windows.Forms.Padding(1, 0, 10, 0);
            this.statusStrip1.Size = new System.Drawing.Size(900, 22);
            this.statusStrip1.TabIndex = 4;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // location
            // 
            this.location.Name = "location";
            this.location.Size = new System.Drawing.Size(0, 17);
            // 
            // worldSpace
            // 
            this.worldSpace.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.worldSpace.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.worldSpace.HeightCell = 0;
            this.worldSpace.Image = null;
            this.worldSpace.Location = new System.Drawing.Point(0, 0);
            this.worldSpace.Margin = new System.Windows.Forms.Padding(2);
            this.worldSpace.Name = "worldSpace";
            this.worldSpace.Size = new System.Drawing.Size(900, 517);
            this.worldSpace.TabIndex = 2;
            this.worldSpace.Tag = "";
            this.worldSpace.WidthCell = 0;
            this.worldSpace.MouseDown += new System.Windows.Forms.MouseEventHandler(this.worldSpace_MouseDown);
            this.worldSpace.MouseMove += new System.Windows.Forms.MouseEventHandler(this.worldSpace_MouseMove);
            // 
            // viewToolStripMenuItem
            // 
            this.viewToolStripMenuItem.Name = "viewToolStripMenuItem";
            this.viewToolStripMenuItem.Size = new System.Drawing.Size(44, 20);
            this.viewToolStripMenuItem.Text = "&View";
            // 
            // exportObjectsToolStripMenuItem
            // 
            this.exportObjectsToolStripMenuItem.Name = "exportObjectsToolStripMenuItem";
            this.exportObjectsToolStripMenuItem.Size = new System.Drawing.Size(203, 26);
            this.exportObjectsToolStripMenuItem.Text = "Export Objects As...";
            this.exportObjectsToolStripMenuItem.Click += new System.EventHandler(this.exportObjectsToolStripMenuItem_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(200, 6);
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(200, 6);
            // 
            // Form1
            // 
            this.AcceptButton = this.btn_Excute;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1168, 561);
            this.Controls.Add(this.btnHide);
            this.Controls.Add(this.splitContainer1);
            this.Controls.Add(this.menuStrip1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MainMenuStrip = this.menuStrip1;
            this.Margin = new System.Windows.Forms.Padding(2);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.panel1.ResumeLayout(false);
            this.gr_object.ResumeLayout(false);
            this.gr_object.PerformLayout();
            this.gr_map.ResumeLayout(false);
            this.gr_map.PerformLayout();
            this.splitContainer1.Panel1.ResumeLayout(false);
            this.splitContainer1.Panel1.PerformLayout();
            this.splitContainer1.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).EndInit();
            this.splitContainer1.ResumeLayout(false);
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem subMenu_New;
        private System.Windows.Forms.ToolStripMenuItem subMenu_OpenImage;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.GroupBox gr_map;
        private System.Windows.Forms.Label label;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox txt_height;
        private System.Windows.Forms.TextBox txt_width;
        private System.Windows.Forms.Button btn_Excute;
        private ImageBox worldSpace;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox txt_Size;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.GroupBox gr_object;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.ToolStripStatusLabel location;
        private System.Windows.Forms.ImageList imageListObjects;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox txt_H;
        private System.Windows.Forms.TextBox txt_W;
        private System.Windows.Forms.TextBox txt_Y;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox txt_X;
        private System.Windows.Forms.ComboBox cb_typeObject;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.CheckBox check_deleteObject;
        private System.Windows.Forms.Button btnDeleteAllObjects;
        private System.Windows.Forms.ToolStripMenuItem subMenu_OpenFile;
        private System.Windows.Forms.Button btnHide;
        private System.Windows.Forms.ComboBox cb_directStair;
        private System.Windows.Forms.ToolStripMenuItem editToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem subMenu_DeleteObject;
        private System.Windows.Forms.Button btnSaveQuadTree;
        private System.Windows.Forms.ToolStripMenuItem viewToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exportObjectsToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
    }
}

