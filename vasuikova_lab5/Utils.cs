using System;

namespace DanceStudio
{
    public static class Utils
    {
        public static int ReadInt(int minValue, int maxValue)
        {
            int value;
            while (true)
            {
                string input = Console.ReadLine() ?? "";
                if (int.TryParse(input, out value) && value >= minValue && value <= maxValue)
                {
                    return value;
                }
                Console.WriteLine($"Введите число от {minValue} до {maxValue}");
            }
        }
    }
}