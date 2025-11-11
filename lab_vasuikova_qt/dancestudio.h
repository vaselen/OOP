#pragma once

#include "Teacher.h"
#include "Director.h"
#include <vector>
#include <memory>
#include <QPainter>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/export.hpp>

BOOST_CLASS_EXPORT_KEY(vasuikova_Teacher)
BOOST_CLASS_EXPORT_KEY(vasuikova_Director)

class vasuikova_DanceStudio {
private:
    std::vector<std::shared_ptr<vasuikova_Teacher>> teachers;

public:
    vasuikova_DanceStudio();
    ~vasuikova_DanceStudio();

    void addTeacher(std::shared_ptr<vasuikova_Teacher> teacher);
    void clearList();
    void loadFromFile(std::ifstream& file);
    void saveToFile(std::ofstream& file) const;

    const std::vector<std::shared_ptr<vasuikova_Teacher>>& getTeachers() const { return teachers; }

    void paintTeachers(QPainter* painter, int width) const;
    int calculateTotalHeight(int width) const;
};
