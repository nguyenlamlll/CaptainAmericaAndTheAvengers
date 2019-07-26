using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MapEditor.Models
{
    public class Ground : GameObject
    {
        public Ground(GameObject gameObject)
            : base(gameObject.Id, gameObject.X, gameObject.Y, gameObject.Width, gameObject.Height, gameObject.ObjectTypeId)
        {

        }
    }
}
