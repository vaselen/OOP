#include "DanceStudio.h"
#include "utils.h"
#include <locale>
#include <iostream>
#include <limits>

using namespace std;    
void displayMenu() {
    wcout << L"МЕНЮ" << endl;
    wcout << L"1. Добавить учителя" << endl;
    wcout << L"2. Показать список учителей" << endl;
    wcout << L"3. Сохранить в файл" << endl;
    wcout << L"4. Загрузить из файла" << endl;
    wcout << L"5. Отчистить список учителей" << endl;
    wcout << L"6. Выход" << endl;
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
    DanceStudio studio;
    const std::wstring filename = L"teachers.txt";

    while(true) {
        displayMenu();
        int choice = valid_int(0, 6);

        switch (choice) {
        case 1:
            studio.addTeacher();
            break;

        case 2:
            studio.displayAllTeachers();
            break;

        case 3:
            studio.writeToFile(filename);
            break;

        case 4:
            studio.readFromFile(filename);
            break;

        case 5:
            studio.clearList();
            break;

        case 6:
            wcout << L"Выход из программы..." << endl;
            return 0;
            break;

        default:
            wcout << L"Неправильная команда. Попробуйте еще раз." << endl;
            break;
        }
    } 
}