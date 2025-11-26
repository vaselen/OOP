#include "MainWindow_vasuikova.h"
#include "ui_MainWindow_vasuikova.h"
#include "TeacherListDialog.h"
#include <fstream>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setWindowTitle("Танцевальная студия");
    setMinimumSize(800, 600);

    // connect(ui->editButton, &QPushButton::clicked, this, &MainWindow::on_editButton_clicked);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.translate(300, 0);

    studio.paintTeachers(&painter, width());
}

void MainWindow::on_loadButton_clicked() {
    QString filename = QFileDialog::getOpenFileName(this,
                                                    "Загрузить данные",
                                                    "",
                                                    "All Files (*)");

    if (!filename.isEmpty()) {
        std::ifstream file(filename.toStdString(), std::ios::binary);
        if (file.is_open()) {
            studio.loadFromFile(file);
            update();
            QMessageBox::information(this, "Успех", "Данные успешно загружены из файла!");
        } else {
            QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл для чтения!");
        }
    }
}

void MainWindow::on_saveButton_clicked() {
    QString filename = QFileDialog::getSaveFileName(this,
                                                    "Сохранить данные",
                                                    "",
                                                    "Text Files (*.txt);;All Files (*)");

    if (!filename.isEmpty()) {
        if (!filename.endsWith(".txt", Qt::CaseInsensitive)) {
            filename += ".txt";
        }

        std::ofstream file(filename.toStdString(), std::ios::binary);
        if (file.is_open()) {
            studio.saveToFile(file);
            file.close();
            QMessageBox::information(this, "Успех", "Данные успешно сохранены в файл!");
        } else {
            QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл для записи!");
        }
    }
}

void MainWindow::on_clearButton_clicked() {
    studio.clearList();
    update();
    QMessageBox::information(this, "Успех", "Список преподавателей очищен!");
}

void MainWindow::on_editButton_clicked() {
    TeacherListDialog dialog(&studio, this);

    // Блокирующий вызов диалога
    if (dialog.exec() == QDialog::Accepted) {
        update(); // Перерисовываем главное окно после закрытия диалога
    }
}
