using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MapEditor
{
    public class GameObject
    {
        public enum EObjectID
        {
            Ground,
            GROUND_DROP,
            ROPE,
            WALL,
            LEVERAGE,
            COLUMN,
            BAR,
     
            CAMEL,

            GUARDS1,
            GUARDS2,
            GUARDS3,

            CIVILIAN1,
            CIVILIAN2,
            CIVILIAN3,
            CIVILIAN4,

            PEDDLER,

            APPLEITEM,
            TEAPOTITEM,
            GENIEITEM,
            BALLITEM,
            ALADDINITEM,
            HEARTITEM,
            MONKEYITEM,
            JARITEM,
            STICKITEM,
            STAIR,
            TRAP,
            JAFAR,
            NONE
        }

        /// <summary>
        /// Object Id.
        /// </summary>
        public int Id { get; set; }

        private int _width;
        private int _height;
        private int _x;
        private int _y;
        private EObjectID objectTypeId;
        private int _direct;//0-> left to right; 1-> right to left
        private int _key;

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

        internal EObjectID ObjectTypeId
        {
            get
            {
                return objectTypeId;
            }

            set
            {
                objectTypeId = value;
            }
        }

        public int Key
        {
            get
            {
                return _key;
            }

            set
            {
                _key = value;
            }
        }

        public int Direct
        {
            get
            {
                return _direct;
            }

            set
            {
                _direct = value;
            }
        }

        public GameObject()
        {
        }

        public GameObject(int id, int x, int y, int width, int height, EObjectID objectTypeId)
        {
            this.Id = id;
            this.X = x;
            this.Y = y;
            this.Width = width;
            this.Height = height;
            this.ObjectTypeId = objectTypeId;
        }
    }
}
