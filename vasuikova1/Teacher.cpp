#include "Teacher.h"
#include "utils.h"
#include <iostream>
#include <fstream>
#include <limits>



vasuikova_Teacher::vasuikova_Teacher(std::wstring& name, int age, std::wstring& danceStyle)
    : name(name), age(age), danceStyle(danceStyle) {
}

vasuikova_Teacher::~vasuikova_Teacher(){}

void vasuikova_Teacher::readFromConsole() {
    std::wcout << L"������� ��� �������: ";
    std::getline(std::wcin, name);

    std::wcout << L"������� �������: ";
    age = valid_int(18, 80);

    std::wcout << L"������� �����, ������� ��������� �������: ";
    std::getline(std::wcin, danceStyle);
}

void vasuikova_Teacher::displayToConsole() const {
    std::wcout << L"���: " << name
        << L", �������: " << age
        << L", �����: " << danceStyle;
}
    