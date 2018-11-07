#ifndef USBCONTROL_H
#define USBCONTROL_H
#include "QObject"
#include "enumusb.h"
#include "powertest.h"
#include "powertestinstancegetter.h"

const int OneGroupUsbNumber = 20;

class UsbControl : public QObject
{
    Q_OBJECT
    friend class DeviceOperator;

private:
    explicit UsbControl(QObject *parent = 0);

public:
    ~UsbControl();

    bool SetEnumTestUsbConfig(const uint &un_Pid,
                              const uint &un_Vid,
                              const int &n_DeviceNumber,
                              const int &n_Time,
                              const QMap<int,int> &map_StationPort);

    bool SetPowerTestConfig(const QMap<int,int> &map_StationPort);

    bool StartUsbEnumTest();
    bool StartPowerTest();

    bool GetEnumResult(QMap<int,bool> &map_EnumResult);

    bool GetTestResult(QMap<int,bool> &map_EnumResult,
                       QMap<int,bool> &map_OpenDeviceResult,
                       QMap<int, bool> &map_SendCmdResult);

    bool ExitUsbControl();

private:
    bool ExitEnumUsbTest();
    bool ExitPowerTest();

    void WorkSleep(ushort un_Msec);

signals:
    void sig_EnumUsbComplete();
    void sig_SendPowerTestComplete();

public slots:
    void slot_EnumUsbTestComplete();
    void slot_SendPowerTestomplete();

private slots:

private:
    EnumUsb *m_pEnumUsb;
    PowerTest *m_pPowerTest;
    PowerTestInstanceGetter *m_pPowerTestInstanceGetter;
};

#endif // USBCONTROL_H
