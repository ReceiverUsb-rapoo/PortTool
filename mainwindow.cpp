#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    this->setWindowTitle("ReceiverUsbCollectPort");

    m_pUsbOperator = new UsbOperator;
    m_pUsbOperator->InitUsbOperator();

    connect(m_pUsbOperator, SIGNAL(sig_RunComplete()),
            this, SLOT(slot_RunComplete()));

    connect(ui->pb_Inquiry,&QPushButton::clicked,
            this, &MainWindow::InquiryPort);

    connect(ui->pb_Write,&QPushButton::clicked,
            this,&MainWindow::WriteAndSave);
}

MainWindow::~MainWindow()
{
    m_pUsbOperator->ExitUsbOperator();
    delete ui;
}

void MainWindow::InquiryPort()
{
    m_pUsbOperator->StartNewOperator();
    m_pUsbOperator->SetFindUsbDeviceConfig(ui->le_PID->text().toInt(NULL,16),
                                           ui->le_VID->text().toInt(NULL,16),
                                           1,
                                           1500);

    m_pUsbOperator->start();
}

void MainWindow::WriteAndSave()
{
    ConfigFile o_ConfigFile;
    STRUCT_USBCONTROLCONFIG struct_UsbControlConfig;
    QMap<int,int> map_StationPort;

    o_ConfigFile.GetUsbControlConfig(ui->cb_FWSequenceNumber->currentText().toUShort(),
                                     struct_UsbControlConfig);

    map_StationPort = struct_UsbControlConfig.map_StationPort;

    map_StationPort.insert(ui->le_Address->text().toInt(),
                           ui->le_Port->text().toInt());

    struct_UsbControlConfig.map_StationPort = map_StationPort;

    o_ConfigFile.SaveUsbControlConfig(ui->cb_FWSequenceNumber->currentText().toUShort(),
                                      struct_UsbControlConfig);
}

void MainWindow::slot_RunComplete()
{
    QList<int> list_DevicePort;
    m_pUsbOperator->GetDevicePort(list_DevicePort);

    ui->le_Address->setText(ui->cb_Address->currentText());
    ui->le_Port->setText(QString::number(list_DevicePort.at(0)));
}

