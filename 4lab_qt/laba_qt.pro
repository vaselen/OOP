QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# Исправляем пути к Boost
INCLUDEPATH += "C:/boost/vcpkg/installed/x64-windows/include"

CONFIG(debug, debug|release) {
  LIBS += -L"C:\boost\vcpkg\installed\x64-windows\debug\bin"
  LIBS += -L"C:\boost\vcpkg\installed\x64-windows\debug\lib"
  LIBS += -lboost_serialization-vc143-mt-gd-x64-1_89
} else {
  LIBS += -L"C:\boost\vcpkg\installed\x64-windows\debug\bin"
  LIBS += -lboost_serialization-vc143-mt-x64-1_89
}

# Добавляем определение для Windows
win32 {
  QMAKE_CXXFLAGS += /utf-8
  QMAKE_CFLAGS += /utf-8
  DEFINES += _SCL_SECURE_NO_WARNINGS
}

SOURCES += \
    DanceStudio.cpp \
    Director.cpp \
    EditDialog.cpp \
    main.cpp \
    MainWindow_vasuikova.cpp \
    Teacher.cpp \
    TeacherListDialog.cpp

HEADERS += \
    DanceStudio.h \
    Director.h \
    MainWindow_vasuikova.h \
    Teacher.h \
    EditDialog.h \
    TeacherListDialog.h

FORMS += \
    MainWindow_vasuikova.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
