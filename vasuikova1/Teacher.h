#pragma once

#include <iostream>
#include <fstream>
#include <string>

class Teacher {
private:
    std::wstring name;
    int age;
    std::wstring danceStyle;

public:
    Teacher();
    Teacher(const std::wstring& name, int age, const std::wstring& danceStyle);

    void readFromConsole();
    void displayToConsole() const;
    void readFromFile(std::wifstream& inFile);
    void writeToFile(std::wofstream& outFile) ;

    std::wstring getName() const { return name; }
    int getAge() const { return age; }
    std::wstring getDanceStyle() const { return danceStyle; }
};

