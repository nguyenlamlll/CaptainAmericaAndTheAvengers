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
        private Image _image;

        private int _widthCell;

        private int _heightCell;

        public Action callBack;

        #region Property

        public Image Image
        {
            get
            {
                return _image;
            }

            set
            {
                _image = value;
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

        public int WidthCell
        {
            get
            {
                return _widthCell;
            }

            set
            {
                _widthCell = value;
            }
        }

        public int HeightCell
        {
            get
            {
                return _heightCell;
            }

            set
            {
                _heightCell = value;
            }
        }

        #endregion

        #region Override Event
        protected override void OnPaint(PaintEventArgs e)
        {
            Graphics graphics = e.Graphics;

            graphics.TranslateTransform(this.AutoScrollPosition.X, this.AutoScrollPosition.Y);

            if (_image != null)
            {
                this.callBack();
                graphics.DrawImage(_image, 0, 0);

                int max = (this._image.Width >= this._image.Height) ? this._image.Width : this._image.Height;

                int rows = (max % _widthCell == 0) ? max / this._widthCell : max / this._widthCell + 1;//(this._image.Height % this._heightCell == 0) ? this._image.Height / this._heightCell : this._image.Height / this._heightCell + 1;
                int columns = (max % _heightCell == 0) ? max / this._heightCell : max / this._heightCell + 1;// (this._image.Width % this._widthCell == 0) ? this._image.Width / this._widthCell : this._image.Width / this._widthCell + 1;

                for (int r = 0; r < rows; r++)
                    graphics.DrawLine(Pens.Black, new Point(0, r * this._heightCell), new Point(max, r * this._heightCell));

                for (int c = 0; c < columns; c++)
                    graphics.DrawLine(Pens.Black, new Point(c * this._widthCell, 0), new Point(c * this._widthCell, max));
            }
            base.OnPaint(e);
        }

        protected override void OnLoad(EventArgs e)
        {
            this.DoubleBuffered = true;
            base.OnLoad(e);
        }
        #endregion
    }
}
