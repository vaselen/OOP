#include "MainWindow_vasuikova.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;  // Изменено с MainWindow_vasuikova на MainWindow
    w.show();
    return a.exec();
}
