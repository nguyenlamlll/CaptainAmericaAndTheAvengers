using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MapEditor
{
    class QNode
    {
        #region Property
        private const int MAX_LEVEL = 6;
        private const int MAX_OBJECT = 1;
        private int _level;
        private int _id;
        private int _x;
        private int _y;
        private int _width;
        private int _height;
        private WorldRect _bound;
        private List<GameObject> _listObject;
        private QNode[] _childs;

        public int Level
        {
            get
            {
                return _level;
            }

            set
            {
                _level = value;
            }
        }

        public int Id
        {
            get
            {
                return _id;
            }

            set
            {
                _id = value;
            }
        }

        internal List<GameObject> ListObject
        {
            get
            {
                return _listObject;
            }

            set
            {
                _listObject = value;
            }
        }

        internal QNode[] Childs
        {
            get
            {
                return _childs;
            }

            set
            {
                _childs = value;
            }
        }

        public QNode NodeLT
        {
            get { return (Childs == null) ? null : Childs[0]; }
            set { Childs[0] = value; }
        }

        public QNode NodeRT
        {
            get { return (Childs == null) ? null : Childs[1]; }
            set { Childs[1] = value; }
        }

        public QNode NodeLB
        {
            get { return (Childs == null) ? null : Childs[2]; }
            set { Childs[2] = value; }
        }

        public QNode NodeRB
        {
            get { return (Childs == null) ? null : Childs[3]; }
            set { Childs[3] = value; }
        }

        public int X
        {
            get
            {
                return _x;
            }

            set
            {
                _x = value;
            }
        }

        public int Y
        {
            get
            {
                return _y;
            }

            set
            {
                _y = value;
            }
        }

        public int Width
        {
            get
            {
                return _width;
            }

            set
            {
                _width = value;
            }
        }

        public int Height
        {
            get
            {
                return _height;
            }

            set
            {
                _height = value;
            }
        }

        internal WorldRect Bound
        {
            get
            {
                return _bound;
            }

            set
            {
                _bound = value;
            }
        }
        #endregion

        #region Contructor
        public QNode(int level, int x, int y, int width, int height , int id)
        {
            this.Level = level;
            this.Id = id;
            this.X = x;
            this.Y = y;
            this.Width = width;
            this.Height = height;
            this.Bound = new WorldRect(x, y, width, height);
            this.Childs = new QNode[4];
            this.ListObject = new List<GameObject>();

            for (int i = 0; i < Childs.Count(); i++)
            {
                this.Childs[i] = null;
            }
        }
        public QNode(int level, WorldRect bound, int id)
        {
            this.Level = level;
            this.Id = id;
            this.X = bound.left;
            this.Y = bound.top;
            this.Width = bound.right - bound.left;
            this.Height = bound.top - bound.bottom;

            this.Bound = new WorldRect(this.X, this.Y, this.Width, this.Height);

            this.Childs = new QNode[4];
            this.ListObject = new List<GameObject>();
            for (int i = 0; i < Childs.Count(); i++)
            {
                this.Childs[i] = null;
            }
        }
        #endregion

        #region Core Method
        public void clear()
        {
            this.ListObject.Clear();

            for (int i = 0; i < Childs.Length; i++)
            {
                if (Childs[i] != null)
                {
                    Childs[i].clear();
                    Childs[i] = null;
                }
            }
        }

        /// <summary>
        /// Split parents node to 4 childs node
        /// </summary>
        private void split()
        {
            int subWidth = Width / 2;
            int subHeight = Height / 2;

            WorldRect rectLT = new WorldRect(X, Y, subWidth, subHeight);
            WorldRect rectRT = new WorldRect(X + subWidth, Y, Width - subWidth, subHeight);
            WorldRect rectLB = new WorldRect(X, Y - subHeight, subWidth, Height - subHeight);
            WorldRect rectRB = new WorldRect(X + subWidth, Y - subHeight, Width - subWidth, Height - subHeight);

            this.NodeLT = new QNode(this.Level + 1, rectLT, this.Id * 10);
            this.NodeRT = new QNode(this.Level + 1, rectRT, this.Id * 10 + 1);
            this.NodeLB = new QNode(this.Level + 1, rectLB, this.Id * 10 + 2);
            this.NodeRB = new QNode(this.Level + 1, rectRB, this.Id * 10 + 3);

        }

        /// <summary>
        /// get NodeID hold a object
        /// </summary>
        /// <param name="obj"></param>
        /// <returns></returns>
        private int getNodeId(GameObject obj)
        {
            //in viewport
            WorldRect rectObject = new WorldRect(obj.X, obj.Y, obj.Width, obj.Height);

            int subWidth = Width / 2;
            int subHeight = Height / 2;

            int x = X;
            int y = 9542 - Y;

            WorldRect rectLT = this.NodeLT.Bound;
            WorldRect rectRT = this.NodeRT.Bound;
            WorldRect rectLB = this.NodeLB.Bound;
            WorldRect rectRB = this.NodeRB.Bound;

            if (rectLT.Contains(rectObject))
                return 1;
            else if (rectRT.Contains(rectObject))
                return 2;
            else if (rectLB.Contains(rectObject))
                return 3;
            else if (rectRB.Contains(rectObject))
                return 4;
            else
            {
                int id = 0;
                if (rectObject.IntersectsWith(rectLT))
                    id = 1;

                if (rectObject.IntersectsWith(rectRT))
                    id = id * 10 + 2;

                if (rectObject.IntersectsWith(rectLB))
                    id = id * 10 + 3;

                if (rectObject.IntersectsWith(rectRB))
                    id = id * 10 + 4;

                return id;
            }
        }

        /// <summary>
        /// Build Tree
        /// </summary>
        /// <param name="obj"></param>
        public void buildTree()
        {
            //Node can't split => insert this object into this node
            if (this.Level >= MAX_LEVEL || this.ListObject.Count <= MAX_OBJECT)
                return;

            if (Childs[0] == null)
                this.split();

            for (int i = 0; i < this.ListObject.Count; i++)
            {
                GameObject obj = ListObject[i];
                //_object = new GameObject(obj.X, obj.Y, obj.Width, obj.Height, obj.Id);

                int index = this.getNodeId(obj);
                switch(index)
                {
                    case 1: case 2: case 3: case 4:
                        {
                            this.Childs[index - 1].ListObject.Add(obj);
                            break;
                        }
                    case 12:
                        {
                            Childs[0].ListObject.Add(obj); 
                            Childs[1].ListObject.Add(obj);
                            break;
                        }
                    case 13:
                        {
                            Childs[0].ListObject.Add(obj);
                            Childs[2].ListObject.Add(obj);
                            break;
                        }
                    case 24:
                        {
                            Childs[1].ListObject.Add(obj);
                            Childs[3].ListObject.Add(obj);
                            break;
                        }
                    case 34:
                        {
                            Childs[2].ListObject.Add(obj);
                            Childs[3].ListObject.Add(obj);
                            break;
                        }
                    case 1234:
                        {
                            Childs[0].ListObject.Add(obj);
                            Childs[1].ListObject.Add(obj);
                            Childs[2].ListObject.Add(obj);
                            Childs[3].ListObject.Add(obj);
                            break;
                        }
                }
            }
            this.ListObject.Clear();
            Childs[0].buildTree();
            Childs[1].buildTree();
            Childs[2].buildTree();
            Childs[3].buildTree();
        }

        /// <summary>
        /// Write quadtree to text
        /// </summary>
        /// <param name="writer"></param>
        public void writeText(TextWriter writer)
        {
            //This node is non-leaf node
            if(Childs[0] != null)
            {
                writer.WriteLine(this.Id + " " + X + " " + Y + " " + Width);
                this.Childs[0].writeText(writer);
                this.Childs[1].writeText(writer);
                this.Childs[2].writeText(writer);
                this.Childs[3].writeText(writer);
            }
            else
            {
                writer.Write(this.Id + " " + X + " " + Y + " " + Width);
                foreach (var item in this.ListObject)
                {
                    writer.Write(" " + item.Key);
                }
                writer.WriteLine();
            }
        }
        #endregion
    }
}
