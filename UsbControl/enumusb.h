#ifndef ENUMUSB_H
#define ENUMUSB_H
#include "usboperator.h"

class EnumUsb : public QObject
{
    Q_OBJECT
public:
    explicit EnumUsb(QObject *parent = 0);
    ~EnumUsb();

    bool InitEnumUsb();
    bool CloseEmumUsb();

    bool GetDevice(QMap<int, libusb_device *> &map_LDevice);

    bool SetEnumUsbConfig(const uint &un_Pid,
                          const uint &un_Vid,
                          const int &n_DeviceNumber,
                          const int &n_Time,
                          const QMap<int,int> &map_StationPort);

    bool StartNewEnumUsb();

    bool GetEnumResult(QMap<int,bool> &map_EnumResult);

private:
    void WorkSleep(ushort un_Msec);

    bool EnumComplete();

signals:
    void sig_EnumComplete();

public slots:
    void slot_EnumComplete();

private slots:

private:
    UsbOperator *m_pUsbOperator;
    QMap<int,int> m_mapStationPort;
};

#endif // ENUMUSB_H
