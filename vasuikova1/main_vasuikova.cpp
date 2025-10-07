#include "DanceStudio.h"
#include "Teacher.h"
#include "Director.h"
#include "utils.h"
#include <locale>
#include <iostream>
#include <limits>
#include <boost/serialization/access.hpp>

using namespace std;    

BOOST_CLASS_EXPORT_IMPLEMENT(vasuikova_Teacher)
BOOST_CLASS_EXPORT_IMPLEMENT(vasuikova_Director)

void displayMenu() {
    wcout << L"МЕНЮ" << endl;
    wcout << L"1. Добавить учителя" << endl;
    wcout << L"2. Добавить руководителя" << endl;
    wcout << L"3. Показать список преподавателей" << endl;
    wcout << L"4. Сохранить в файл" << endl;
    wcout << L"5. Загрузить из файла" << endl;
    wcout << L"6. Отчистить список преподавателей" << endl;
    wcout << L"7. Выход" << endl;
    wcout << L"Выберете команду: ";
}

void setupLocale() {
    setlocale(LC_ALL, "rus");
    locale::global(locale("rus_rus.866"));
    wcin.imbue(locale("rus_rus.866"));
    wcout.imbue(locale("rus_rus.866"));
}

int main() {
    setupLocale();
    vasuikova_DanceStudio studio;
    const std::wstring filename = L"teachers.txt";

    while(true) {
        displayMenu();
        int choice = valid_int(1, 7);

        switch (choice) {
        case 1:
            studio.add(make_shared<vasuikova_Teacher>());
            break;

        case 2:
            studio.add(make_shared<vasuikova_Director>());
            break;

        case 3:
            studio.displayAllTeachers();
            break;
                
        case 4:
            studio.writeToFile(filename);
            break;

        case 5:
            studio.readFromFile(filename);
            break;

        case 6:
            studio.clearList();
            break;

        case 7:
            wcout << L"Выход из программы..." << endl;
            return 0;
            break;

        default:
            wcout << L"Неправильная команда. Попробуйте еще раз." << endl;
            break;
        }
    } 
}