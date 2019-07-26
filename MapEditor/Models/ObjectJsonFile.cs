using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MapEditor.Models
{
    public class ObjectJsonFile
    {
        public ObjectJsonFile()
        {
            Ground = new List<Ground>();
        }
        public List<Ground> Ground { get; set; }
    }
}
