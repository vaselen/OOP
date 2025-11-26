#include "EditDialog.h"
#include "Teacher.h"
#include "Director.h"

EditDialog::EditDialog(QWidget* parent, Mode mode)
    : QDialog(parent), currentMode(mode) {
    setupUI();
    setWindowTitle(mode == Mode::Add ? "Добавить преподавателя" : "Редактировать преподавателя");
    setMinimumSize(600, 500);
}

EditDialog::~EditDialog() {}

void EditDialog::setupUI() {
    auto* mainLayout = new QVBoxLayout(this);

    directorCheckBox = new QCheckBox("Руководитель", this);
    connect(directorCheckBox, &QCheckBox::toggled, this, &EditDialog::onDirectorToggled);
    mainLayout->addWidget(directorCheckBox);

    auto* inputGroup = new QGroupBox("Данные преподавателя", this);
    auto* formLayout = new QVBoxLayout(inputGroup);

    auto* nameLayout = new QHBoxLayout();
    nameLayout->addWidget(new QLabel("ФИО:"));
    nameEdit = new QLineEdit();
    nameLayout->addWidget(nameEdit);
    formLayout->addLayout(nameLayout);

    auto* ageLayout = new QHBoxLayout();
    ageLayout->addWidget(new QLabel("Возраст:"));
    ageEdit = new QLineEdit();
    ageEdit->setValidator(new QIntValidator(1, 100, this));
    ageLayout->addWidget(ageEdit);
    formLayout->addLayout(ageLayout);

    auto* styleLayout = new QHBoxLayout();
    styleLayout->addWidget(new QLabel("Стиль танца:"));
    styleEdit = new QLineEdit();
    styleLayout->addWidget(styleEdit);
    formLayout->addLayout(styleLayout);

    // Поля только для директора (изначально скрыты)
    auto* experienceLayout = new QHBoxLayout();
    experienceLabel = new QLabel("Стаж:");
    experienceLayout->addWidget(experienceLabel);
    experienceEdit = new QLineEdit();
    experienceEdit->setValidator(new QIntValidator(0, 100, this));
    experienceLayout->addWidget(experienceEdit);
    formLayout->addLayout(experienceLayout);

    auto* phoneLayout = new QHBoxLayout();
    phoneLabel = new QLabel("Телефон:");
    phoneLayout->addWidget(phoneLabel);
    phoneEdit = new QLineEdit();
    phoneLayout->addWidget(phoneEdit);
    formLayout->addLayout(phoneLayout);

    mainLayout->addWidget(inputGroup);

    auto* buttonLayout = new QHBoxLayout();

    if (currentMode == Mode::Add) {
        auto* addButton = new QPushButton("Добавить");
        connect(addButton, &QPushButton::clicked, this, &QDialog::accept);
        buttonLayout->addWidget(addButton);
    } else {
        auto* editButton = new QPushButton("Сохранить");
        connect(editButton, &QPushButton::clicked, this, &QDialog::accept);
        buttonLayout->addWidget(editButton);
    }

    auto* cancelButton = new QPushButton("Отмена");
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);
    buttonLayout->addWidget(cancelButton);

    mainLayout->addLayout(buttonLayout);

    onDirectorToggled(false);
}

void EditDialog::onDirectorToggled(bool checked) {
    experienceLabel->setVisible(checked);
    experienceEdit->setVisible(checked);
    phoneLabel->setVisible(checked);
    phoneEdit->setVisible(checked);
}

void EditDialog::setTeacherData(const vasuikova_Teacher* teacher) {
    if (!teacher) return;
    teacher->setupEditDialog(this);
}

void EditDialog::setDirectorMode(bool isDirector) {
    directorCheckBox->setChecked(isDirector);
}

void EditDialog::getTeacherData(vasuikova_Teacher* teacher) const {
    if (!teacher) return;
    teacher->updateFromEditDialog(this);
}

void EditDialog::getDirectorData(vasuikova_Director* director) const {
    if (!director) return;
    director->updateFromEditDialog(this);
}
