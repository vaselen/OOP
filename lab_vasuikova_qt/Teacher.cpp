#include "Teacher.h"
#include <QPainter>

vasuikova_Teacher::vasuikova_Teacher(const std::wstring& name, int age, const std::wstring& danceStyle)
    : name(name), age(age), danceStyle(danceStyle) {
}

vasuikova_Teacher::~vasuikova_Teacher() {}

void vasuikova_Teacher::displayToConsole() const {
    qDebug() << L"Имя:" << name << L"Возраст:" << age << L"Стиль:" << danceStyle;
}

void vasuikova_Teacher::paint(QPainter* painter, int& yPos, int tableX, int col1, int col2, int col3, int col4, int col5) const {
    int totalWidth = col1 + col2 + col3 + col4 + col5;

    painter->drawRect(tableX, yPos, totalWidth, 30);

    painter->drawLine(tableX + col1, yPos, tableX + col1, yPos + 30);
    painter->drawLine(tableX + col1 + col2, yPos, tableX + col1 + col2, yPos + 30);
    painter->drawLine(tableX + col1 + col2 + col3, yPos, tableX + col1 + col2 + col3, yPos + 30);
    painter->drawLine(tableX + col1 + col2 + col3 + col4, yPos, tableX + col1 + col2 + col3 + col4, yPos + 30);

    painter->drawText(tableX + 5, yPos + 5, col1 - 10, 20, Qt::AlignLeft, QString::fromStdWString(name));
    painter->drawText(tableX + col1 +5, yPos + 5, col2 - 10, 20, Qt::AlignLeft, QString("%1 лет").arg(age));
    painter->drawText(tableX + col1 + col2 + 5, yPos + 5, col3 - 10, 20, Qt::AlignLeft, QString::fromStdWString(danceStyle));

    painter->drawText(tableX + col1 + col2 + col3 + 5, yPos + 5, col4 - 10, 20, Qt::AlignLeft, "-");
    painter->drawText(tableX + col1 + col2 + col3 + col4 + 5, yPos + 5, col5 - 10, 20, Qt::AlignLeft, "-");

    yPos += 30;
}

QRect vasuikova_Teacher::getTextRect(int col1, int col2, int col3, int col4, int col5) const {
    return QRect(0, 0, col1 + col2 + col3 + col4 + col5, 30);
}
