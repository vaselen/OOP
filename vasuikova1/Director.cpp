#include "Director.h"
#include "utils.h"
#include <iostream>
using namespace std;

vasuikova_Director::vasuikova_Director() : vasuikova_Teacher() {}

vasuikova_Director::vasuikova_Director(std::wstring& name, int age, std::wstring& danceStyle, int work_experience, std::wstring& phone_number) : vasuikova_Teacher(name, age, danceStyle), work_experience(work_experience), phone_number(phone_number){}

void vasuikova_Director::readFromConsole() {
    vasuikova_Teacher::readFromConsole();
    std::wcout << L"Введите стаж работы: ";
    work_experience = valid_int(0, 50);

    std::wcout << L"Введите номер телефона: ";
    std::getline(std::wcin, phone_number);
}

void vasuikova_Director::displayToConsole() const {
    vasuikova_Teacher::displayToConsole();
    std::wcout << L" Стаж работы: " << work_experience
        << L", Номер телефона: " << phone_number
        << std::endl;
}

