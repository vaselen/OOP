#pragma once

#include <QMainWindow>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>
#include "DanceStudio.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent* event) override;

private slots:
    void on_loadButton_clicked();
    void on_saveButton_clicked();
    void on_clearButton_clicked();

private:
    Ui::MainWindow* ui;
    vasuikova_DanceStudio studio;

};
