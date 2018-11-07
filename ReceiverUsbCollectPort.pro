#-------------------------------------------------
#
# Project created by QtCreator 2018-11-05T09:25:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ReceiverUsbCollectPort
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    UsbControl/usboperator.cpp \
    DataFile/configfile.cpp \

HEADERS += \
        mainwindow.h \
    UsbControl/usboperator.h \
    DataFile/configfile.h \
    DataFile/datafile_define.h \

FORMS += \
        mainwindow.ui

LIBS += -L/usr/local/lib -lusb-1.0
INCLUDEPATH +=/usr/local/include

LIBS += -L"/usr/lib/x86_64-linux-gnu" -lusb-1.0
INCLUDEPATH += /usr/include/libusb-1.0
