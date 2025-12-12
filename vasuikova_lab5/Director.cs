using System;
using System.Text.Json.Serialization;

namespace DanceStudio
{
    public class Director : Teacher
    {
        public int WorkExperience { get; set; }
        public string PhoneNumber { get; set; } = "";

        public Director() : base() { }

        public Director(string name, int age, string danceStyle,
                       int workExperience, string phoneNumber)
            : base(name, age, danceStyle)
        {
            WorkExperience = workExperience;
            PhoneNumber = phoneNumber;
        }

        public override void ReadFromConsole()
        {
            base.ReadFromConsole();

            Console.Write("Введите стаж работы: ");
            WorkExperience = Utils.ReadInt(0, 50);

            Console.Write("Введите номер телефона: ");
            PhoneNumber = Console.ReadLine() ?? "";
        }

        public override void DisplayToConsole()
        {
            base.DisplayToConsole();
            Console.Write($", Стаж работы: {WorkExperience}, " +
                             $"Номер телефона: {PhoneNumber}");
        }
    }
}