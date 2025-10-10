using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LW1._03
{
    public class ComputerPart
    {
        public string Type { get; set; }
        public string Brand { get; set; }
        public string Model { get; set; }
        public string ReleaseYear { get; set; }
        public string Price { get; set; }
        public string AdditionalInfo { get; set; }

        public ComputerPart() { }

        public ComputerPart(string type, string brand, string model, string releaseYear, string price, string additionalIndo)
        {
            Type = type;
            Brand = brand;
            Model = model;
            ReleaseYear = releaseYear;
            Price = price;
            AdditionalInfo = additionalIndo;
        }

        public string[] ToRow()
        {
            return new string[] { Type, Brand, Model, ReleaseYear, Price, AdditionalInfo };
        }

        public static implicit operator string[](ComputerPart part)
        {
            return part.ToRow();
        }

        
    }
}
