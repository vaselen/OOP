using System;
using System.Text.Json.Serialization;

namespace DanceStudio
{
    [JsonDerivedType(typeof(Teacher), typeDiscriminator: "teacher")]
    [JsonDerivedType(typeof(Director), typeDiscriminator: "director")]
    public class Teacher
    {
        public string Name { get; set; } = "";
        public int Age { get; set; }
        public string DanceStyle { get; set; } = "";

        public Teacher() { }

        public Teacher(string name, int age, string danceStyle)
        {
            Name = name;
            Age = age;
            DanceStyle = danceStyle;
        }

        public virtual void ReadFromConsole()
        {
            Console.Write("Введите имя учителя: ");
            Name = Console.ReadLine() ?? "";

            Console.Write("Введите возраст: ");
            Age = Utils.ReadInt(18, 80);

            Console.Write("Введите стиль, который преподает учитель: ");
            DanceStyle = Console.ReadLine() ?? "";
        }

        public virtual void DisplayToConsole()
        {
            Console.Write($"Имя: {Name}, Возраст: {Age}, Стиль: {DanceStyle}");
        }
    }
}