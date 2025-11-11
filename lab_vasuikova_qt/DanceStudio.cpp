#include "DanceStudio.h"
#include <QPainter>
#include <fstream>
#include <algorithm>
#include <functional>
#include <iostream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/export.hpp>

BOOST_CLASS_EXPORT_IMPLEMENT(vasuikova_Teacher)
BOOST_CLASS_EXPORT_IMPLEMENT(vasuikova_Director)

vasuikova_DanceStudio::vasuikova_DanceStudio() {}

vasuikova_DanceStudio::~vasuikova_DanceStudio() {
    clearList();
}

void vasuikova_DanceStudio::addTeacher(std::shared_ptr<vasuikova_Teacher> teacher) {
    teachers.push_back(teacher);
}

void vasuikova_DanceStudio::clearList() {
    teachers.clear();
}

void vasuikova_DanceStudio::loadFromFile(std::ifstream& file) {
    try{
        boost::archive::binary_iarchive ia(file);
        ia >> teachers;
    }
    catch (const boost::archive::archive_exception& e) {
        std::cout << "Ошибка при чтении бинарного архива Boost: " << e.what() << std::endl;
    }
}

void vasuikova_DanceStudio::saveToFile(std::ofstream& file) const {

    boost::archive::binary_oarchive oa(file);
    oa << teachers;
}


void vasuikova_DanceStudio::paintTeachers(QPainter* painter, int width) const {
    int yPos = 75;

    painter->setFont(QFont("Arial", 14, QFont::Bold));
    painter->drawText(10, 30, "Список преподавателей танцевальной студии");
    painter->setFont(QFont("Arial", 10));

    int col1 = 200;
    int col2 = 80;
    int col3 = 150;
    int col4 = 80;
    int col5 = 150;
    int totalWidth = col1 + col2 + col3 + col4 + col5;

    int tableX = 10;

    painter->drawRect(tableX, 50, totalWidth, 25);
    painter->drawText(tableX + 5, 55, col1, 25, Qt::AlignLeft, "ФИО");
    painter->drawText(tableX + col1 + 5, 55, col2, 25, Qt::AlignLeft, "Возраст");
    painter->drawText(tableX + col1 + col2 + 5, 55, col3, 25, Qt::AlignLeft, "Стиль");
    painter->drawText(tableX + col1 + col2 + col3 + 5, 55, col4, 25, Qt::AlignLeft, "Стаж");
    painter->drawText(tableX + col1 + col2 + col3 + col4 + 5, 55, col5, 25, Qt::AlignLeft, "Телефон");

    //разделители заголовков
    painter->drawLine(tableX + col1, 50, tableX + col1, 75);
    painter->drawLine(tableX + col1 + col2, 50, tableX + col1 + col2, 75);
    painter->drawLine(tableX + col1 + col2 + col3, 50, tableX + col1 + col2 + col3, 75);
    painter->drawLine(tableX + col1 + col2 + col3 + col4, 50, tableX + col1 + col2 + col3 + col4, 75);

    auto paintFunc = std::bind(&vasuikova_Teacher::paint,
                               std::placeholders::_1,
                               painter,
                               std::ref(yPos),
                               tableX, col1, col2, col3, col4, col5);

//    std::for_each(teachers.begin(), teachers.end(),
//                  [&](const std::shared_ptr<vasuikova_Teacher>& teacher) {
//                      paintFunc(teacher.get());
//                  });

    std::for_each(teachers.begin(), teachers.end(), paintFunc);
}

int vasuikova_DanceStudio::calculateTotalHeight(int width) const {
    int totalHeight = 90;

    int col1 = 200;
    int col2 = 80;
    int col3 = 150;
    int col4 = 80;
    int col5 = 150;

    auto heightFunc = std::bind(&vasuikova_Teacher::getTextRect,
                                std::placeholders::_1,
                                col1, col2, col3, col4, col5);

    // std::for_each(teachers.begin(), teachers.end(),
    //               [&](const std::shared_ptr<vasuikova_Teacher>& teacher) {
    //                   totalHeight += heightFunc(teacher.get()).height();
    //               });

    std::for_each(teachers.begin(), teachers.end(), heightFunc);

    return totalHeight;
}
