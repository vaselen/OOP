#include "DanceStudio.h"
#include "windows.h"
#include <iostream>
#include <fstream>

using namespace std;

DanceStudio::DanceStudio() {}

DanceStudio::~DanceStudio() {
    clearList();
}

void DanceStudio::addTeacher() {//��������
    Teacher* newTeacher = new Teacher();
    newTeacher->readFromConsole();
    teachers.push_back(newTeacher);
    wcout << L"������� ��������" << endl;
}

void DanceStudio::displayAllTeachers() const {
    if (teachers.empty()) {
        wcout << L"������ ������������� ������" << endl;
        return;
    }

    wcout << L"\n������ ��������������" << endl;
    for (size_t i = 0; i < teachers.size(); ++i) {
        teachers[i]->displayToConsole();
    }
}

void DanceStudio::readFromFile(const wstring& filename) {
    wifstream inFile(filename);
    clearList();
    inFile.imbue(locale("ru_RU.UTF-8"));
    int count;
    inFile >> count;
    inFile.ignore();
    for (int i = 0; i < count; ++i) {
        Teacher* teacher = new Teacher();
        teacher->readFromFile(inFile);
        teachers.push_back(teacher);
    }
    wcout << L"������ ��������� " << endl;
}

void DanceStudio::writeToFile(const wstring& filename) 
{
    wofstream outfile(filename);
    outfile.imbue(locale("ru_RU.UTF-8"));
    outfile << teachers.size() << endl;
    for (const auto& teacher : teachers) {
        teacher->writeToFile(outfile);
    }
    wcout << L"������ ���������" << endl;
}

void DanceStudio::clearList() {
    for (auto& teacher : teachers) {
        delete teacher;
    }
    teachers.clear();
    wcout << L"������ ������" << endl;
}