#pragma once

#include "Teacher.h"
#include <vector>
#include <fstream>
#include <string>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/vector.hpp>

class vasuikova_DanceStudio {
private:
    std::vector<std::shared_ptr<vasuikova_Teacher>> teachers;

public:
    vasuikova_DanceStudio();
    ~vasuikova_DanceStudio();

    void add(std::shared_ptr<vasuikova_Teacher> T);
    void displayAllTeachers() const;
    void readFromFile(const std::wstring filename);
    void writeToFile(const std::wstring filename) const;
    void clearList();
};
