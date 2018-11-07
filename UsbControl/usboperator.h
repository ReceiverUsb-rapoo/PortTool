#ifndef USBOPERATOR_H
#define USBOPERATOR_H
#include <QObject>
#include <QMap>
#include <QThread>
#include "libusb-1.0/libusb.h"

class UsbOperator : public QThread
{
    Q_OBJECT
public:
    explicit UsbOperator(QThread *parent = 0);
    ~UsbOperator();

    bool InitUsbOperator();
    bool ExitUsbOperator();

    bool StartNewOperator();

    bool GetDevice(QMap<int, libusb_device *> &map_LDevice);

    bool GetDevicePort(QList<int> &list_DevicePort);

    bool SetFindUsbDeviceConfig(const uint &un_Pid,
                                const uint &un_Vid,
                                const int &n_DeviceNumber,
                                const int &n_Time);

private:
    void WorkSleep(uint un_Msec);
    bool FindUsbDevicePort(const uint &un_Pid,
                           const uint &un_Vid,
                           QMap<int, libusb_device *> &map_LDevice,
                           QList<int> &list_DevicePort);
    void RunComplete();

protected:
    void run();

signals:
    void sig_RunComplete();

private slots:

private:
    libusb_context  *m_pLibusbContext;
    bool m_bLibusbState;
    uint m_unPid;
    uint m_unVid;
    int m_nRunTime;
    int m_nDeviceNumber;
    QMap<int, libusb_device * > m_mapLDevice;
    QList<int> m_listDevicePort;
};

#endif // USBOPERATOR_H
