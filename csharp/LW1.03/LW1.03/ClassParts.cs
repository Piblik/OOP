using LW1._03;
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

        public static void SortByPrice(List<ComputerPart> parts, bool ascending = true)
        {
            parts.Sort((x, y) =>
            {
                if (x > y) return ascending ? -1 : 1;
                if (x < y) return ascending ? 1 : -1;
                return 0;
            });
        }

        public string[] ToRow()
        {
            return new string[] { Type, Brand, Model, ReleaseYear, Price, AdditionalInfo };
        }

        public static implicit operator string[](ComputerPart part)
        {
            return part.ToRow();
        }

        public static bool operator >(ComputerPart a, ComputerPart b)
        {
            return decimal.Parse(a.Price) > decimal.Parse(b.Price);
        }

        public static bool operator <(ComputerPart a, ComputerPart b)
        {
            return decimal.Parse(a.Price) < decimal.Parse(b.Price);
        }

        public static bool operator >=(ComputerPart a, ComputerPart b)
        {
            return int.Parse(a.ReleaseYear) >= int.Parse(b.ReleaseYear);
        }

        public static bool operator <=(ComputerPart a, ComputerPart b)
        {
            return int.Parse(a.ReleaseYear) <= int.Parse(b.ReleaseYear);
        }
    }
}

public class CPU : ComputerPart
{
    public int Cores { get; set; }
    public float FrequencyGHz { get; set; }

    public CPU() { }

    public CPU(
        string type,
        string brand,
        string model,
        string releaseYear,
        string price,
        string additionalInfo,
        int cores,
        float frequencyGHz
        ) : base(type, brand, model, releaseYear, price, additionalInfo)
    {
        Cores = cores;
        FrequencyGHz = frequencyGHz;
    }
}

