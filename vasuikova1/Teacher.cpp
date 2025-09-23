#include "Teacher.h"
#include "utils.h"
#include <iostream>
#include <fstream>
#include <limits>

Teacher::Teacher() : name(L""), age(0), danceStyle(L"") {}

Teacher::Teacher(const std::wstring& name, int age, const std::wstring& danceStyle)
    : name(name), age(age), danceStyle(danceStyle) {
}

void Teacher::readFromConsole() {
    std::wcout << L"Введите имя учителя: ";
    std::getline(std::wcin, name);

    std::wcout << L"Введите возраст: ";
    age = valid_int(18, 80);

    std::wcout << L"Введите стиль, который преподает учитель: ";
    std::getline(std::wcin, danceStyle);
}

void Teacher::displayToConsole() const {
    std::wcout << L"Имя: " << name
        << L", Возраст: " << age
        << L", Стиль: " << danceStyle
        << std::endl;
}

void Teacher::readFromFile(std::wifstream& inFile) {
    std::getline(inFile, name);
    inFile >> age;
    inFile.ignore(10000, '\n');
    std::getline(inFile, danceStyle);
}

void Teacher::writeToFile(std::wofstream& outFile)  {
    outFile << name << std::endl;
    outFile << age << std::endl;
    outFile << danceStyle << std::endl;
}