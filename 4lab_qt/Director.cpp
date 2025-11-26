#include "Director.h"
#include "EditDialog.h"
#include "TeacherListDialog.h"
#include <QPainter>

vasuikova_Director::vasuikova_Director() : vasuikova_Teacher(), work_experience(0), phone_number(L"") {}

vasuikova_Director::vasuikova_Director(const std::wstring& name, int age, const std::wstring& danceStyle,
                                       int work_experience, const std::wstring& phone_number)
    : vasuikova_Teacher(name, age, danceStyle),
    work_experience(work_experience), phone_number(phone_number) {}

void vasuikova_Director::displayToConsole() const {
    qDebug() << "Руководитель:" << name << "Возраст:" << age << "Стиль:" << danceStyle
             << "Стаж:" << work_experience << "Телефон:" << phone_number;
}

void vasuikova_Director::paint(QPainter* painter, int& yPos, int tableX, int col1, int col2, int col3, int col4, int col5) const {
    int totalWidth = col1 + col2 + col3 + col4 + col5;

    //строка таблицы для руководителя
    painter->save();
    painter->setBrush(QBrush(QColor(149, 18, 161)));
    painter->drawRect(tableX, yPos, totalWidth, 30);
    painter->restore();

    painter->drawLine(tableX + col1, yPos, tableX + col1, yPos + 30);
    painter->drawLine(tableX + col1 + col2, yPos, tableX + col1 + col2, yPos + 30);
    painter->drawLine(tableX + col1 + col2 + col3, yPos, tableX + col1 + col2 + col3, yPos + 30);
    painter->drawLine(tableX + col1 + col2 + col3 + col4, yPos, tableX + col1 + col2 + col3 + col4, yPos + 30);

    painter->drawText(tableX + 5, yPos + 5, col1 - 10, 20, Qt::AlignLeft, QString::fromStdWString(name));
    painter->drawText(tableX + col1 +5, yPos + 5, col2 - 10, 20, Qt::AlignLeft, QString("%1 лет").arg(age));
    painter->drawText(tableX + col1 + col2 +5, yPos + 5, col3 - 10, 20, Qt::AlignLeft, QString::fromStdWString(danceStyle));

    painter->drawText(tableX + col1 + col2 + col3 + 5, yPos + 5, col4 - 10, 20, Qt::AlignLeft, QString("%1 лет").arg(work_experience));
    painter->drawText(tableX + col1 + col2 + col3 + col4 + 5, yPos + 5, col5 - 10, 20, Qt::AlignLeft, QString::fromStdWString(phone_number));

    yPos += 30;
}

QRect vasuikova_Director::getTextRect(int col1, int col2, int col3, int col4, int col5) const {
    return QRect(0, 0, col1 + col2 + col3 + col4 + col5, 30);
}

void vasuikova_Director::updateFromEditDialog(const EditDialog* dialog) {
    if (!dialog) return;
    vasuikova_Teacher::updateFromEditDialog(dialog);
    setWorkExperience(dialog->getExperience());
    setPhoneNumber(dialog->getPhone().toStdWString());
}

void vasuikova_Director::setupEditDialog(EditDialog* dialog) const {
    if (!dialog) return;
    vasuikova_Teacher::setupEditDialog(dialog);
    dialog->setExperience(getWorkExperience());
    dialog->setPhone(QString::fromStdWString(getPhoneNumber()));
    dialog->setDirectorMode(true);
}

void vasuikova_Director::fillFields(TeacherListDialog* dialog) const {
    if (!dialog) return;

    dialog->setName(QString::fromStdWString(getName()));
    dialog->setAge(getAge());
    dialog->setStyle(QString::fromStdWString(getDanceStyle()));

    dialog->setExperience(getWorkExperience());
    dialog->setPhone(QString::fromStdWString(getPhoneNumber()));
    dialog->showDirectorFields(true);
}
