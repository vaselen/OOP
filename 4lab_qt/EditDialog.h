#pragma once

#include <QDialog>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>

class vasuikova_Teacher;
class vasuikova_Director;

class EditDialog : public QDialog {
    Q_OBJECT

public:
    enum class Mode { Add, Edit };

    EditDialog(QWidget* parent = nullptr, Mode mode = Mode::Add);
    ~EditDialog();

    void getTeacherData(vasuikova_Teacher* teacher) const;
    void getDirectorData(vasuikova_Director* director) const;
    void setTeacherData(const vasuikova_Teacher* teacher);

    bool isDirector() const { return directorCheckBox->isChecked(); }
    void setDirectorMode(bool isDirector);

    QString getName() const { return nameEdit->text(); }
    int getAge() const { return ageEdit->text().toInt(); }
    QString getStyle() const { return styleEdit->text(); }
    int getExperience() const { return experienceEdit->text().toInt(); }
    QString getPhone() const { return phoneEdit->text(); }

    void setName(const QString& name) { nameEdit->setText(name); }
    void setAge(int age) { ageEdit->setText(QString::number(age)); }
    void setStyle(const QString& style) { styleEdit->setText(style); }
    void setExperience(int experience) { experienceEdit->setText(QString::number(experience)); }
    void setPhone(const QString& phone) { phoneEdit->setText(phone); }

private slots:
    void onDirectorToggled(bool checked);

private:
    void setupUI();

    QLineEdit* nameEdit;
    QLineEdit* ageEdit;
    QLineEdit* styleEdit;
    QLineEdit* experienceEdit;
    QLineEdit* phoneEdit;

    QCheckBox* directorCheckBox;

    QLabel* experienceLabel;
    QLabel* phoneLabel;

    Mode currentMode;
};
