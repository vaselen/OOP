#pragma once


#include "Teacher.h"
#include <vector>
#include <fstream>
#include <string>

class DanceStudio {
private:
    std::vector<Teacher*> teachers;

public:
    DanceStudio();
    ~DanceStudio();

    void addTeacher();
    void displayAllTeachers() const;
    void readFromFile(const std::wstring& filename);
    void writeToFile(const std::wstring& filename) ;
    void clearList();

    size_t getTeachersCount() const { return teachers.size(); }
    bool isEmpty() const { return teachers.empty(); }
};
