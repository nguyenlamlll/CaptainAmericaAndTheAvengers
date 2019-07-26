using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MapEditor
{
    class WorldRect
    {
        public int top;
        public int left;
        public int right;
        public int bottom;

        public WorldRect()
        {

        }

        public WorldRect(int x, int y, int width, int height)
        {
            this.left = x;
            this.top = y;
            this.right = this.left + width;
            this.bottom = this.top - height;
        }

        public WorldRect(System.Drawing.Point point, System.Drawing.Size size)
        {
            this.left = point.X;
            this.top = point.Y;
            this.right = this.left + size.Width;
            this.bottom = this.top - size.Height;
        }

        public void update(int x, int y, int width, int height)
        {
            this.left = x;
            this.top = y;
            this.right = this.left + width;
            this.bottom = this.top - height;
        }

        public bool Contains(WorldRect rect)
        {
            return (rect.left >= this.left
                && rect.right <= this.right
                && rect.top <= this.top
                && rect.bottom >= this.bottom);
        }

        public bool IntersectsWith(WorldRect rect)
        {
            return !(this.left > rect.right
        || this.right < rect.left
        || this.top < rect.bottom
        || this.bottom > rect.top);
        }
    }
}
