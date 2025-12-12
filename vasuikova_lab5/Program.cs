using System;
using System.Text;

namespace DanceStudio
{
    class Program
    {
        static void DisplayMenu()
        {
            Console.WriteLine("МЕНЮ");
            Console.WriteLine("1. Добавить учителя");
            Console.WriteLine("2. Добавить руководителя");
            Console.WriteLine("3. Показать список преподавателей");
            Console.WriteLine("4. Сохранить в файл");
            Console.WriteLine("5. Загрузить из файла");
            Console.WriteLine("6. Очистить список преподавателей");
            Console.WriteLine("7. Выход");
            Console.Write("Выберите команду: ");
        }

        static void Main(string[] args)
        {
            Console.OutputEncoding = Encoding.UTF8;
            Console.InputEncoding = Encoding.UTF8;

            DanceStudio studio = new DanceStudio();
            const string filename = "./teachers.json";

            while (true)
            {
                DisplayMenu();
                int choice = Utils.ReadInt(1, 7);

                switch (choice)
                {
                    case 1:
                        studio.Add(new Teacher());
                        break;

                    case 2:
                        studio.Add(new Director());
                        break;

                    case 3:
                        studio.DisplayAllTeachers();
                        break;

                    case 4:
                        studio.WriteToFile(filename);
                        break;

                    case 5:
                        studio.ReadFromFile(filename);
                        break;

                    case 6:
                        studio.ClearList();
                        break;

                    case 7:
                        Console.WriteLine("Выход из программы...");
                        return;

                    default:
                        Console.WriteLine("Неправильная команда. Попробуйте еще раз.");
                        break;
                }

                Console.WriteLine(); // пустая строка для разделения
            }
        }
    }
}