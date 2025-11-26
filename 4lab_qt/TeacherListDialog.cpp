#include "TeacherListDialog.h"
#include "EditDialog.h"
#include <algorithm>

TeacherListDialog::TeacherListDialog(vasuikova_DanceStudio* studio, QWidget* parent)
    : QDialog(parent), danceStudio(studio) {
    setupUI();
    refreshList();
    setWindowTitle("Редактирование списка преподавателей");
    setMinimumSize(800, 500);
}

TeacherListDialog::~TeacherListDialog() {}

void TeacherListDialog::setupUI() {
    auto* mainLayout = new QHBoxLayout(this);

    // Левая панель - список
    auto* leftLayout = new QVBoxLayout();
    teacherList = new QListWidget(this);
    connect(teacherList, &QListWidget::currentRowChanged, this, &TeacherListDialog::onSelectionChanged);
    leftLayout->addWidget(teacherList);

    // Кнопки управления списком
    auto* listButtonLayout = new QHBoxLayout();
    addButton = new QPushButton("Добавить");
    editButton = new QPushButton("Редактировать");
    deleteButton = new QPushButton("Удалить");
    closeButton = new QPushButton("Закрыть");

    connect(addButton, &QPushButton::clicked, this, &TeacherListDialog::onAddClicked);
    connect(editButton, &QPushButton::clicked, this, &TeacherListDialog::onEditClicked);
    connect(deleteButton, &QPushButton::clicked, this, &TeacherListDialog::onDeleteClicked);
    connect(closeButton, &QPushButton::clicked, this, &QDialog::accept);

    listButtonLayout->addWidget(addButton);
    listButtonLayout->addWidget(editButton);
    listButtonLayout->addWidget(deleteButton);
    listButtonLayout->addWidget(closeButton);
    leftLayout->addLayout(listButtonLayout);

    mainLayout->addLayout(leftLayout);

    // Правая панель - поля ввода (только для чтения)
    auto* rightLayout = new QVBoxLayout();
    auto* fieldsGroup = new QGroupBox("Информация о преподавателе", this);
    auto* fieldsLayout = new QVBoxLayout(fieldsGroup);

    // Функция для добавления поля
    auto addField = [fieldsLayout](const QString& label, QLineEdit** field, QLabel** labelPtr = nullptr) {
        auto* layout = new QHBoxLayout();
        QLabel* lbl = new QLabel(label);
        layout->addWidget(lbl);
        *field = new QLineEdit();
        (*field)->setReadOnly(true); // Все поля только для чтения
        layout->addWidget(*field);
        fieldsLayout->addLayout(layout);

        if (labelPtr) {
            *labelPtr = lbl;
        }
    };

    // Добавляем поля
    addField("ФИО:", &nameField);
    addField("Возраст:", &ageField);
    addField("Стиль:", &styleField);
    addField("Стаж:", &experienceField, &experienceLabel);
    addField("Телефон:", &phoneField, &phoneLabel);

    rightLayout->addWidget(fieldsGroup);
    mainLayout->addLayout(rightLayout);
}

void TeacherListDialog::refreshList() {
    teacherList->clear();

    const auto& teachers = danceStudio->getTeachers();

    // Используем for_each и лямбда-функцию для перебора элементов
    std::for_each(teachers.begin(), teachers.end(),
                  [this](const std::shared_ptr<vasuikova_Teacher>& teacher) {
                      if (teacher) {
                          teacherList->addItem(teacher->getDisplayName());
                      }
                  });

    if (teacherList->count() > 0) {
        teacherList->setCurrentRow(0);
    }
}

void TeacherListDialog::onSelectionChanged() {
    updateFields();
}

void TeacherListDialog::updateFields() {
    // Очищаем поля
    nameField->clear();
    ageField->clear();
    styleField->clear();
    experienceField->clear();
    phoneField->clear();

    int currentRow = teacherList->currentRow();
    if (currentRow < 0) return;

    auto& teachers = danceStudio->getTeachers();
    if (currentRow >= static_cast<int>(teachers.size())) return;

    const auto& teacher = teachers[currentRow];
    if (!teacher) return;

    teacher->fillFields(this);
}

void TeacherListDialog::onAddClicked() {
    EditDialog dialog(this, EditDialog::Mode::Add);

    if (dialog.exec() == QDialog::Accepted) {
        std::shared_ptr<vasuikova_Teacher> newTeacher;

        if (dialog.isDirector()) {
            auto director = std::make_shared<vasuikova_Director>();
            dialog.getDirectorData(director.get());
            newTeacher = director;
        } else {
            auto teacher = std::make_shared<vasuikova_Teacher>();
            dialog.getTeacherData(teacher.get());
            newTeacher = teacher;
        }

        danceStudio->addTeacher(newTeacher);
        refreshList();
        // Выбираем добавленный элемент
        teacherList->setCurrentRow(teacherList->count() - 1);
    }
}

void TeacherListDialog::onEditClicked() {
    int currentRow = teacherList->currentRow();
    if (currentRow < 0) return;

    auto& teachers = danceStudio->getTeachers();
    if (currentRow >= static_cast<int>(teachers.size())) return;

    auto& teacher = teachers[currentRow];
    if (!teacher) return;

    EditDialog dialog(this, EditDialog::Mode::Edit);
    dialog.setTeacherData(teacher.get()); // Используем новый метод

    if (dialog.exec() == QDialog::Accepted) {
        if (dialog.isDirector()) {
            if (typeid(*teacher) != typeid(vasuikova_Director)) {
                auto newDirector = std::make_shared<vasuikova_Director>();
                dialog.getDirectorData(newDirector.get());
                teacher = newDirector;
            } else {
                dialog.getDirectorData(static_cast<vasuikova_Director*>(teacher.get()));
            }
        } else {
            dialog.getTeacherData(teacher.get());
        }

        refreshList();
        teacherList->setCurrentRow(currentRow);
    }
}

void TeacherListDialog::onDeleteClicked() {
    int currentRow = teacherList->currentRow();
    if (currentRow < 0) return;

    auto& teachers = danceStudio->getTeachers();
    if (currentRow >= static_cast<int>(teachers.size())) return;

    teachers.erase(teachers.begin() + currentRow);

    refreshList();

    if (teacherList->count() > 0) {
        int newRow = currentRow;
        if (currentRow >= teacherList->count()) {
            newRow = teacherList->count() - 1;
        }
        teacherList->setCurrentRow(newRow);
    }

    updateFields();
}

void TeacherListDialog::setName(const QString& name) {
    nameField->setText(name);
}

void TeacherListDialog::setAge(int age) {
    ageField->setText(QString::number(age));
}

void TeacherListDialog::setStyle(const QString& style) {
    styleField->setText(style);
}

void TeacherListDialog::setExperience(int experience) {
    experienceField->setText(QString::number(experience));
}

void TeacherListDialog::setPhone(const QString& phone) {
    phoneField->setText(phone);
}

void TeacherListDialog::showDirectorFields(bool show) {
    experienceLabel->setVisible(show);
    experienceField->setVisible(show);
    phoneLabel->setVisible(show);
    phoneField->setVisible(show);
}
