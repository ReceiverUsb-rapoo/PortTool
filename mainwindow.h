#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "UsbControl/usboperator.h"
#include "DataFile/configfile.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void InquiryPort();

    void WriteAndSave();

public slots:
    void slot_RunComplete();

private:
    Ui::MainWindow *ui;
    UsbOperator *m_pUsbOperator;
};

#endif // MAINWINDOW_H
