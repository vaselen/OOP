using System;
using System.Collections.Generic;
using System.IO;
using System.Text.Json;
using System.Text.Json.Serialization;

namespace DanceStudio
{
    public class DanceStudio
    {
        private List<Teacher> teachers = new List<Teacher>();

        public void Add(Teacher teacher)
        {
            teacher.ReadFromConsole();
            teachers.Add(teacher);
            Console.WriteLine("Учитель добавлен");
        }

        public void DisplayAllTeachers()
        {
            if (teachers.Count == 0)
            {
                Console.WriteLine("Список преподавателей пустой");
                return;
            }

            Console.WriteLine("\nСПИСОК ПРЕПОДАВАТЕЛЕЙ");
            for (int i = 0; i < teachers.Count; i++)
            {
                teachers[i].DisplayToConsole();
                Console.WriteLine();
            }
        }

        public void ReadFromFile(string filename)
        {
            try
            {
                string json = File.ReadAllText(filename);
                var options = new JsonSerializerOptions
                {
                    Converters = { new JsonStringEnumConverter() }
                };
                teachers = JsonSerializer.Deserialize<List<Teacher>>(json, options) ?? new List<Teacher>();
                Console.WriteLine("Преподаватели загружены из файла");
            }
            catch (FileNotFoundException)
            {
                Console.WriteLine("Файл не найден. Создан новый список.");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка при загрузке: {ex.Message}");
            }
        }

        public void WriteToFile(string filename)
        {
            try
            {
                var options = new JsonSerializerOptions
                {
                    WriteIndented = true,
                    Converters = { new JsonStringEnumConverter() }
                };
                string json = JsonSerializer.Serialize(teachers, options);
                File.WriteAllText(filename, json);
                Console.WriteLine("Преподаватели сохранены в файл");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка при сохранении: {ex.Message}");
            }
        }

        public void ClearList()
        {
            teachers.Clear();
            Console.WriteLine("Список очищен");
        }
    }
}