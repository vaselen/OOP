#pragma once

#include "Teacher.h"

#include <boost/serialization/base_object.hpp>
#include <boost/serialization/string.hpp>
#include <QString>
#include <QPainter>
#include <QRect>

class EditDialog;

class vasuikova_Director : public vasuikova_Teacher {
private:
    int work_experience;
    std::wstring phone_number;

    friend class boost::serialization::access;

public:
    vasuikova_Director();
    vasuikova_Director(const std::wstring& name, int age, const std::wstring& danceStyle,
                       int work_experience, const std::wstring& phone_number);

    int getWorkExperience() const { return work_experience; }
    const std::wstring& getPhoneNumber() const { return phone_number; }

    void setWorkExperience(int experience) { work_experience = experience; }
    void setPhoneNumber(const std::wstring& phone) { phone_number = phone; }

    void displayToConsole() const override;
    void paint(QPainter* painter, int& yPos, int tableX, int col1, int col2, int col3, int col4, int col5) const override;
    QRect getTextRect(int col1, int col2, int col3, int col4, int col5) const override;

    void updateFromEditDialog(const EditDialog* dialog) override;
    void setupEditDialog(EditDialog* dialog) const override;
    void fillFields(TeacherListDialog* dialog) const override;

    QString getDisplayName() const override {
        return QString::fromStdWString(getName()) + " (Руководитель)";
    }

    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& boost::serialization::base_object<vasuikova_Teacher>(*this);
        ar& work_experience;
        ar& phone_number;
    }
};
