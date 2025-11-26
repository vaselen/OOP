#pragma once

#include <QString>
#include <QPainter>
#include <QRect>
#include <QDebug>
#include <boost/serialization/access.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/export.hpp>

class EditDialog;
class TeacherListDialog;// Предварительное объявление

class vasuikova_Teacher {
protected:
    std::wstring name;
    int age;
    std::wstring danceStyle;

    friend class boost::serialization::access;

public:
    vasuikova_Teacher() : name(L""), age(0), danceStyle(L"") {}
    vasuikova_Teacher(const std::wstring& name, int age, const std::wstring& danceStyle);
    virtual ~vasuikova_Teacher();

    const std::wstring& getName() const { return name; }
    int getAge() const { return age; }
    const std::wstring& getDanceStyle() const { return danceStyle; }

    void setName(const std::wstring& newName) { name = newName; }
    void setAge(int newAge) { age = newAge; }
    void setDanceStyle(const std::wstring& newStyle) { danceStyle = newStyle; }

    virtual void displayToConsole() const;
    virtual void paint(QPainter* painter, int& yPos, int tableX, int col1, int col2, int col3, int col4, int col5) const;
    virtual QRect getTextRect(int col1, int col2, int col3, int col4, int col5) const;

    virtual void updateFromEditDialog(const EditDialog* dialog);
    virtual void setupEditDialog(EditDialog* dialog) const;
    virtual void fillFields(TeacherListDialog* dialog) const;

    virtual QString getDisplayName() const { return QString::fromStdWString(name); }

    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& name;
        ar& age;
        ar& danceStyle;
    }
};
