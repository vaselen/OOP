#include "DanceStudio.h"
#include "windows.h"
#include <iostream>
#include <fstream>

using namespace std;

vasuikova_DanceStudio::vasuikova_DanceStudio() {}

vasuikova_DanceStudio::~vasuikova_DanceStudio() {
    clearList();
}

void vasuikova_DanceStudio::add(shared_ptr<vasuikova_Teacher> newTeacher) {
    newTeacher->readFromConsole();
    teachers.push_back(newTeacher);
    wcout << L"Учитель добавлен" << endl;
}

void vasuikova_DanceStudio::displayAllTeachers() const {
    if (teachers.empty()) {
        wcout << L"Список преподаватель пустой" << endl;
        return;
    }

    wcout << L"\nСПИСОК ПРЕПОДАВАТЕЛЕЙ" << endl;
    for (size_t i = 0; i < teachers.size(); ++i) {
        teachers[i]->displayToConsole();
        wcout << endl;
    }
}

void vasuikova_DanceStudio::readFromFile(const std::wstring filename)
{
    ifstream ifile(filename);
    boost::archive::binary_iarchive ia(ifile);
    ia >> teachers;
    wcout << L"Преподаватели загружены из файла" << endl;
}

void vasuikova_DanceStudio::writeToFile(const std::wstring filename) const
{
    ofstream ofile(filename);
    boost::archive::binary_oarchive oa(ofile);
    oa << teachers;
    wcout << L"Преподаватели сохранены в файл" << endl;
}

void vasuikova_DanceStudio::clearList() {
    teachers.clear();
    wcout << L"Список очищен" << endl;
}