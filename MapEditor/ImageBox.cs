using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MapEditor
{
    public partial class ImageBox : UserControl
    {
        private Image image;

        public int WidthCell { get; set; }
        public int HeightCell { get; set; }

        public Action callBack;



        public Image Image
        {
            get
            {
                return image;
            }

            set
            {
                image = value;
                if (value == null) this.AutoScrollMinSize = new Size(0, 0);
                else
                {
                    var size = value.Size;
                    using (var gr = this.CreateGraphics())
                    {
                        size.Width = (int)(size.Width * gr.DpiX / value.HorizontalResolution);
                        size.Height = (int)(size.Height * gr.DpiY / value.VerticalResolution);
                    }
                    this.AutoScrollMinSize = size;
                }
                this.Invalidate();
            }
        }






        protected override void OnPaint(PaintEventArgs e)
        {
            Graphics graphics = e.Graphics;

            graphics.TranslateTransform(this.AutoScrollPosition.X, this.AutoScrollPosition.Y);

            if (image != null)
            {
                //this.callBack();
                graphics.DrawImage(image, 0, 0);

                int max = (this.image.Width >= this.image.Height) ? this.image.Width : this.image.Height;

                int rows = (max % WidthCell == 0) ? max / this.WidthCell : max / this.WidthCell + 1;//(this._image.Height % this._heightCell == 0) ? this._image.Height / this._heightCell : this._image.Height / this._heightCell + 1;
                int columns = (max % HeightCell == 0) ? max / this.HeightCell : max / this.HeightCell + 1;// (this._image.Width % this._widthCell == 0) ? this._image.Width / this._widthCell : this._image.Width / this._widthCell + 1;

                for (int r = 0; r < rows; r++)
                    graphics.DrawLine(Pens.Black, new Point(0, r * this.HeightCell), new Point(max, r * this.HeightCell));

                for (int c = 0; c < columns; c++)
                    graphics.DrawLine(Pens.Black, new Point(c * this.WidthCell, 0), new Point(c * this.WidthCell, max));
            }
            base.OnPaint(e);
        }

        protected override void OnLoad(EventArgs e)
        {
            this.DoubleBuffered = true;
            base.OnLoad(e);
        }

    }
}
