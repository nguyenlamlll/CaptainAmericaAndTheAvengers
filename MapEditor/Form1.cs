using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MapEditor
{
    public partial class Form1 : Form
    {
        private int WORLD_X;
        private int WORLD_Y;

        private GameObject _object;
        private List<GameObject> _listObject;
        private int _countClick;
        private QNode quadtree;

        private Point _locationMouse;
        private int _widthCell;
        private int _heightCell;
        private Image _imageBuffer;

        public Form1()
        {
            InitializeComponent();
            this._widthCell = int.Parse(this.txt_width.Text);
            this._heightCell = int.Parse(this.txt_height.Text);
            this.cb_typeObject.SelectedIndex = 0;
            this.cb_directStair.SelectedIndex = 0;
            this._listObject = new List<GameObject>();

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.StartPosition = FormStartPosition.CenterScreen;
            this.worldSpace.callBack = new Action(Invisible_OpenButton);
            this.worldSpace.WidthCell = int.Parse(txt_width.Text);
            this.worldSpace.HeightCell = int.Parse(txt_height.Text);
        }

        private void Invisible_OpenButton()
        {
            this.btn_OpenImage.Hide();
        }

        private void btn_Excute_Click(object sender, EventArgs e)
        {
            this._widthCell = int.Parse(this.txt_width.Text.ToString());
            this._heightCell = int.Parse(this.txt_height.Text.ToString());
            this.worldSpace.WidthCell = int.Parse(this.txt_width.Text);
            this.worldSpace.HeightCell = int.Parse(this.txt_height.Text);
            this.worldSpace.Refresh();
        }

        private void btn_OpenImage_Click(object sender, EventArgs e)
        {
            subMenu_Open_Click(sender, e);
        }

        private void btnSaveQuadTree_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < this._listObject.Count; i++)
                this._listObject[i].Key = i;

            this.quadtree.clear();
            //Đổ tất cả object vào node đầu tiên của quadtree
            foreach (var item in this._listObject)
                this.quadtree.ListObject.Add(item);

            this.quadtree.buildTree();//Xây dụng quadtree

            try
            {
                string path = SaveQuadtree();
                if (path == null)
                    return;
                var result = MessageBox.Show("QuadTree is saved successfully!\nDo you want to open this file?", "Notify", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
                if (result == DialogResult.Yes)
                    System.Diagnostics.Process.Start(path);

            }
            catch (Exception ex)
            {
                MessageBox.Show("QuadTree is saved failure!", "Notify", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }

        private void subMenu_Open_Click(object sender, EventArgs e)
        {
            using (OpenFileDialog dlg = new OpenFileDialog())
            {
                dlg.Filter = "All Image Files|*.bmp;*.ico;*.gif;*.jpeg;*.jpg;" +
                    "*.jfif;*.png;*.tif;*.tiff;*.wmf;*.emf|" +
                    "Windows Bitmap (*.bmp)|*.bmp|" +
                    "All Files (*.*)|*.*";
                if (dlg.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                {
                    this.worldSpace.Image = new Bitmap(dlg.FileName);
                    this._imageBuffer = new Bitmap(dlg.FileName);
                    this.WORLD_X = this.WORLD_Y = Math.Max(this._imageBuffer.Width, this._imageBuffer.Height);
                    this.quadtree = new QNode(1, 0, WORLD_Y, WORLD_X, WORLD_Y, 1);
                }
            }
        }

        private void txt_Size_TextChanged(object sender, EventArgs e)
        {
            this.txt_height.Text = this.txt_width.Text = this.txt_Size.Text;
        }

        private void txt_Size_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar != 8 && !Char.IsDigit(e.KeyChar))
                e.Handled = true;
        }

        private void txt_width_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar != 8 && !Char.IsDigit(e.KeyChar))
                e.Handled = true;
        }

        private void txt_height_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar != 8 && !Char.IsDigit(e.KeyChar))
                e.Handled = true;
        }

        private void worldSpace_MouseMove(object sender, MouseEventArgs e)
        {
            Point currentMouse = new Point(e.X - this.worldSpace.AutoScrollPosition.X, e.Y - this.worldSpace.AutoScrollPosition.Y);

            this._locationMouse.X = currentMouse.X / this._widthCell;
            this._locationMouse.Y = currentMouse.Y / this._heightCell;

            this.location.Text = "[" + this._locationMouse.X + ", " + this._locationMouse.Y + "]";
        }

        /// <summary>
        /// Process when user want to add object into map
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void worldSpace_MouseDown(object sender, MouseEventArgs e)
        {
            //Delete Object
            if (check_deleteObject.Checked)
            {
                if (this._listObject.Count == 0)
                {
                    MessageBox.Show("No object can delete! Please check again", "Notify", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    return;
                }

                //Current location in world
                Point currentMouse = new Point(e.X - this.worldSpace.AutoScrollPosition.X, WORLD_Y - (e.Y - this.worldSpace.AutoScrollPosition.Y));
                WorldRect currentObject = new WorldRect(currentMouse, new Size(1, 1));
                for (int i = _listObject.Count - 1; i >= 0; i--)
                {
                    var obj = this._listObject[i];
                    WorldRect rectObject = new WorldRect(obj.X, obj.Y, obj.Width, obj.Height);
                    if (rectObject.Contains(currentObject))
                    {
                        string direct = (obj.Direct == 0) ? "Left to Right" : "Right to Left";
                        var result = MessageBox.Show("Do you want to delete this Object?"
                            + "\nType:\t" + obj.Id
                            + "\nX:\t" + obj.X + "\t->\t" + obj.X / this._widthCell
                            + "\nY:\t" + obj.Y + "\t->\t" + (WORLD_Y - obj.Y) / this._heightCell
                            + "\nWidth:\t" + obj.Width + "\t->\t" + obj.Width / this._widthCell
                            + "\nHeight\t" + obj.Height + "\t->\t" + obj.Height / this._heightCell
                            + "\nDirect:\t" + direct,
                            "Notify", MessageBoxButtons.YesNo, MessageBoxIcon.Question);

                        if (result == DialogResult.Yes)
                            this._listObject.Remove(obj);
                    }
                }

                //Draw all object in listObject

                if (this._listObject.Count > 0)
                {
                    Image image = new Bitmap(this._imageBuffer);
                    using (Graphics graphics = Graphics.FromImage(image))
                    {
                        List<Rectangle> listRect = new List<Rectangle>();
                        foreach (var obj in this._listObject)
                        {
                            listRect.Add(new Rectangle(obj.X, WORLD_Y - obj.Y, obj.Width, obj.Height));
                        }
                        Pen pen = new Pen(Color.White);
                        pen.Width = 3;
                        graphics.DrawRectangles(pen, listRect.ToArray());
                    }
                    this.worldSpace.Image = image;// new Bitmap(image);
                }
                else
                    this.worldSpace.Image = new Bitmap(this._imageBuffer);
                return;
            }

            #region Add Object
            try
            {
                this._countClick++;

                if (this._countClick == 1)
                {
                    //Xác định position
                    _object = new GameObject();
                    //Lấy toạ độ theo toạ độ world 
                    this._object.X = this._locationMouse.X * this._widthCell;
                    this._object.Y = WORLD_Y - this._locationMouse.Y * this._heightCell;

                    Rectangle rect = new Rectangle(new Point(this._object.X - 2, WORLD_Y - this._object.Y - 2), new Size(3, 3));
                    this.DrawDemo(rect, _object.Id);

                }
                else
                {
                    Point currentWorld = new Point(this._locationMouse.X * this._widthCell, WORLD_Y - this._locationMouse.Y * this._heightCell);

                    this._object.Width = currentWorld.X - this._object.X;
                    this._object.Height = this._object.Y - currentWorld.Y;

                    if (this._object.Width < 0)
                    {
                        this._object.Width *= -1;
                        this._object.X -= this._object.Width;
                    }
                    else
                        this._object.Width += this._widthCell;


                    if (this._object.Height < 0)
                    {
                        this._object.Height *= -1;
                        this._object.Y += this._object.Height;
                    }
                    else
                        this._object.Height += this._heightCell;

                    this.txt_W.Text = this._object.Width.ToString();
                    this.txt_H.Text = this._object.Height.ToString();

                  
                    this._countClick = 0; ;

                    switch (cb_typeObject.SelectedIndex)
                    {
                        case 0: _object.Id = GameObject.EObjectID.GROUND; break;
                        case 1: _object.Id = GameObject.EObjectID.ROPE; break;
                        case 2: _object.Id = GameObject.EObjectID.WALL; break;
                        case 3: _object.Id = GameObject.EObjectID.LEVERAGE; break;
                        case 4: _object.Id = GameObject.EObjectID.COLUMN; break;
                        case 5: _object.Id = GameObject.EObjectID.BAR; break;
                        case 6: _object.Id = GameObject.EObjectID.CAMEL; break;
                        case 7: _object.Id = GameObject.EObjectID.GUARDS1; break;
                        case 8: _object.Id = GameObject.EObjectID.GUARDS2; break;
                        case 9: _object.Id = GameObject.EObjectID.GUARDS3; break;
                        case 10: _object.Id = GameObject.EObjectID.CIVILIAN1; break;
                        case 11: _object.Id = GameObject.EObjectID.CIVILIAN2; break;
                        case 12: _object.Id = GameObject.EObjectID.CIVILIAN3; break;
                        case 13: _object.Id = GameObject.EObjectID.CIVILIAN4; break;
                        case 14: _object.Id = GameObject.EObjectID.PEDDLER; break;
                        case 15: _object.Id = GameObject.EObjectID.APPLEITEM; break;
                        case 16: _object.Id = GameObject.EObjectID.TEAPOTITEM; break;
                        case 17: _object.Id = GameObject.EObjectID.GENIEITEM; break;
                        case 18: _object.Id = GameObject.EObjectID.BALLITEM; break;
                        case 19: _object.Id = GameObject.EObjectID.ALADDINITEM; break;
                        case 20: _object.Id = GameObject.EObjectID.HEARTITEM; break;
                        case 21: _object.Id = GameObject.EObjectID.MONKEYITEM; break;
                        case 22: _object.Id = GameObject.EObjectID.JARITEM; break;
                        case 23: _object.Id = GameObject.EObjectID.STAIR; break;
                        case 24: _object.Id = GameObject.EObjectID.GROUND_DROP; break;
                        case 25: _object.Id = GameObject.EObjectID.STICKITEM; break;
                        case 26: _object.Id = GameObject.EObjectID.TRAP; break;
                        case 27: _object.Id = GameObject.EObjectID.JAFAR; break;
                    }
                    _object.Direct = cb_directStair.SelectedIndex;
                    this._listObject.Add(_object);

                    Rectangle rect = new Rectangle(new Point(this._object.X, WORLD_Y - this._object.Y), new Size(this._object.Width, this._object.Height));
                    this.DrawDemo(rect, _object.Id);
                }

                this.txt_X.Text = (this._object.X / this._widthCell).ToString();
                this.txt_Y.Text = ((WORLD_Y - this._object.Y) / this._heightCell).ToString();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Notify", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            #endregion
        }

        /// <summary>
        /// Draw a rectangle demo for objects on map
        /// </summary>
        /// <param name="rect"></param>
        private void DrawDemo(Rectangle rect, GameObject.EObjectID id)
        {
            Image tempBitmap = this.worldSpace.Image;

            using (Graphics graphics = Graphics.FromImage(tempBitmap))
            {
                Color color;
                switch (id)
                {
                    case GameObject.EObjectID.GUARDS1: color = Color.Yellow; break;
                    case GameObject.EObjectID.GUARDS2: color = Color.Red; break;
                    case GameObject.EObjectID.GUARDS3: color = Color.Blue; break;
                    case GameObject.EObjectID.CIVILIAN1: color = Color.Green; break;
                    case GameObject.EObjectID.CIVILIAN2: color = Color.Gold; break;
                    case GameObject.EObjectID.CIVILIAN3: color = Color.Gray; break;
                    case GameObject.EObjectID.CIVILIAN4: color = Color.FloralWhite ; break;
                    default: color = Color.White; break;
                }
                Pen pen = new Pen(color);
                pen.Width = 3;
                graphics.DrawRectangle(pen, rect);
            }

            this.worldSpace.Image = tempBitmap;
        }

        public string SaveQuadtree()
        {
            SaveFileDialog saveFileDialog = new SaveFileDialog();
            saveFileDialog.Filter = "Text|*.txt";
            saveFileDialog.Title = "Save Quadtree";

            if (saveFileDialog.ShowDialog() != DialogResult.OK)
                return null;
            string path = saveFileDialog.FileName;

            if (File.Exists(path))
                File.WriteAllText(path, string.Empty);
            else
                File.Create(path).Dispose();

            TextWriter writer = new StreamWriter(path, true);

            //First Line: Number of object, Map width, Map height
            writer.WriteLine(this._listObject.Count + " " + WORLD_X + " " + WORLD_Y);

            //Write object
            int index = 0;

            foreach (var item in this._listObject)
            {
                writer.WriteLine(
                    index++ + " " 
                    + this.ParseID(item.Id) + " " 
                    + item.X + " " 
                    + item.Y + " " 
                    + item.Width + " " 
                    + item.Height+ " " 
                    + item.Direct);
            }

            //Write quadtree
            quadtree.writeText(writer);
            writer.Close();

            return path;
        }

        /// <summary>
        /// Convert from ID to integer
        /// </summary>
        /// <param name="id"></param>
        /// <returns></returns>
        int ParseID(GameObject.EObjectID id)
        {
            switch (id)
            {
                case GameObject.EObjectID.GROUND: return 1;
                case GameObject.EObjectID.ROPE: return 2;
                case GameObject.EObjectID.WALL: return 3;
                case GameObject.EObjectID.LEVERAGE: return 4;
                case GameObject.EObjectID.COLUMN: return 5;
                case GameObject.EObjectID.BAR: return 6;
                case GameObject.EObjectID.CAMEL: return 7;
                case GameObject.EObjectID.GUARDS1: return 8;
                case GameObject.EObjectID.GUARDS2: return 9;
                case GameObject.EObjectID.GUARDS3: return 10;
                case GameObject.EObjectID.CIVILIAN1: return 11;
                case GameObject.EObjectID.CIVILIAN2: return 12;
                case GameObject.EObjectID.CIVILIAN3: return 13;
                case GameObject.EObjectID.CIVILIAN4: return 14;
                case GameObject.EObjectID.PEDDLER: return 15;
                case GameObject.EObjectID.APPLEITEM: return 16;
                case GameObject.EObjectID.TEAPOTITEM: return 17;
                case GameObject.EObjectID.GENIEITEM: return 18;
                case GameObject.EObjectID.BALLITEM: return 19;
                case GameObject.EObjectID.ALADDINITEM: return 20;
                case GameObject.EObjectID.HEARTITEM: return 21;
                case GameObject.EObjectID.MONKEYITEM: return 22;
                case GameObject.EObjectID.JARITEM: return 23;
                case GameObject.EObjectID.STAIR: return 24;
                case GameObject.EObjectID.GROUND_DROP: return 25;
                case GameObject.EObjectID.STICKITEM: return 26;
                case GameObject.EObjectID.TRAP: return 27;
                case GameObject.EObjectID.JAFAR: return 28;
                default: return 0;
            }
        }

        private GameObject.EObjectID ParseID(int id)
        {
            switch (id)
            {
                case 1: return GameObject.EObjectID.GROUND;
                case 2: return GameObject.EObjectID.ROPE;
                case 3: return GameObject.EObjectID.WALL;
                case 4: return GameObject.EObjectID.LEVERAGE;
                case 5: return GameObject.EObjectID.COLUMN;
                case 6: return GameObject.EObjectID.BAR;
                case 7: return GameObject.EObjectID.CAMEL;
                case 8: return GameObject.EObjectID.GUARDS1;
                case 9: return GameObject.EObjectID.GUARDS2;
                case 10: return GameObject.EObjectID.GUARDS3;
                case 11: return GameObject.EObjectID.CIVILIAN1;
                case 12: return GameObject.EObjectID.CIVILIAN2;
                case 13: return GameObject.EObjectID.CIVILIAN3;
                case 14: return GameObject.EObjectID.CIVILIAN4;
                case 15: return GameObject.EObjectID.PEDDLER;
                case 16: return GameObject.EObjectID.APPLEITEM;
                case 17: return GameObject.EObjectID.TEAPOTITEM;
                case 18: return GameObject.EObjectID.GENIEITEM;
                case 19: return GameObject.EObjectID.BALLITEM;
                case 20: return GameObject.EObjectID.ALADDINITEM;
                case 21: return GameObject.EObjectID.HEARTITEM;
                case 22: return GameObject.EObjectID.MONKEYITEM;
                case 23: return GameObject.EObjectID.JARITEM;
                case 24: return GameObject.EObjectID.STAIR;
                case 25: return GameObject.EObjectID.GROUND_DROP;
                case 26: return GameObject.EObjectID.STICKITEM;
                case 27: return GameObject.EObjectID.TRAP;
                case 28: return GameObject.EObjectID.JAFAR;
                default: return GameObject.EObjectID.NONE;
            }
        }

        private void btn_Refresh_Click(object sender, EventArgs e)
        {
            this.quadtree.clear();
            this._listObject.Clear();
            this.worldSpace.Image = new Bitmap(this._imageBuffer);
        }

        private void subMenu_OpenFile_Click(object sender, EventArgs e)
        {
            using (OpenFileDialog openDialog = new OpenFileDialog())
            {
                openDialog.Filter = "Text|*.txt";
                openDialog.Title = "Open source file";
                if (openDialog.ShowDialog() == DialogResult.OK)
                {
                    this._listObject.Clear();
                    string fileName = openDialog.FileName;
                    using (StreamReader reader = new StreamReader(fileName))
                    {
                        string firstLine = reader.ReadLine();
                        int numberOfObject = ParseLine(firstLine)[0];

                        for (int i = 0; i < numberOfObject; i++)
                        {
                            string currentLine = reader.ReadLine();
                            List<int> listNumber = ParseLine(currentLine);
                            GameObject obj = new GameObject();
                            obj.Id = ParseID(listNumber[1]);
                            obj.X = listNumber[2];
                            obj.Y = listNumber[3];
                            obj.Width = listNumber[4];
                            obj.Height = listNumber[5];
                            if (listNumber.Count == 7)
                                obj.Direct = listNumber[6];

                            this._listObject.Add(obj);
                        }
                    }

                    //Draw all object in listObject

                    if (this._listObject.Count > 0)
                    {
                        Image image = new Bitmap(this._imageBuffer);
                        using (Graphics graphics = Graphics.FromImage(image))
                        {
                            List<Rectangle> listRect = new List<Rectangle>();
                            foreach (var obj in this._listObject)
                            {
                                listRect.Add(new Rectangle(obj.X, WORLD_Y - obj.Y, obj.Width, obj.Height));
                            }
                            Pen pen = new Pen(Color.White);
                            pen.Width = 3;
                            graphics.DrawRectangles(pen, listRect.ToArray());
                        }
                        this.worldSpace.Image = image;// new Bitmap(image);
                    }
                    else
                        this.worldSpace.Image = new Bitmap(this._imageBuffer);
                }
            }
        }

        private List<int> ParseLine(string line)
        {
            List<int> list = new List<int>();

            int index;
            index = line.IndexOf(' ');

            while (index >= 0)
            {
                list.Add(int.Parse(line.Remove(index + 1)));
                line = line.Substring(index + 1);
                index = line.IndexOf(' ');
            }

            list.Add(int.Parse(line));

            return list;
        }

        private void btnHide_Click(object sender, EventArgs e)
        {
            if (!this.splitContainer1.Panel2Collapsed)
            {
                this.splitContainer1.Panel2Collapsed = true;
                this.btnHide.Text = "<<";
            }
            else
            {
                this.splitContainer1.Panel2Collapsed = false;
                this.btnHide.Text = ">>";
            }
        }

        private void cb_typeObject_SelectedIndexChanged(object sender, EventArgs e)
        {
            cb_directStair.Visible = true;
        }

        private void worldSpace_KeyPress(object sender, KeyPressEventArgs e)
        {
        }

        private void menuStrip1_KeyPress(object sender, KeyPressEventArgs e)
        {
        }

        private void subMenu_DeleteObject_Click(object sender, EventArgs e)
        {
            this.check_deleteObject.Checked = (this.check_deleteObject.Checked) ? false : true;
        }
    }
}
