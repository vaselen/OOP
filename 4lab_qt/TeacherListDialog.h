#pragma once

#include "DanceStudio.h"
#include <QDialog>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QLabel>


class TeacherListDialog : public QDialog {
    Q_OBJECT

public:
    TeacherListDialog(vasuikova_DanceStudio* studio, QWidget* parent = nullptr);
    ~TeacherListDialog();

    // Методы для работы с полями из Teacher классов
    void setName(const QString& name);
    void setAge(int age);
    void setStyle(const QString& style);
    void setExperience(int experience);
    void setPhone(const QString& phone);
    void showDirectorFields(bool show);

private slots:
    void onAddClicked();
    void onEditClicked();
    void onDeleteClicked();
    void onSelectionChanged();
    void updateFields();

private:
    void setupUI();
    void refreshList();

    vasuikova_DanceStudio* danceStudio;

    QListWidget* teacherList;
    QLineEdit* nameField;
    QLineEdit* ageField;
    QLineEdit* styleField;
    QLineEdit* experienceField;
    QLineEdit* phoneField;

    QLabel* experienceLabel;
    QLabel* phoneLabel;

    QPushButton* addButton;
    QPushButton* editButton;
    QPushButton* deleteButton;
    QPushButton* closeButton;
};
