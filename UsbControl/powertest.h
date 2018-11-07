#ifndef POWERTEST_H
#define POWERTEST_H
#include <QThreadPool>
#include <QMutex>
#include <QTimer>
#include <QObject>
#include <QMap>
#include "libusb-1.0/libusb.h"

class PowerTest : public QObject
{
    Q_OBJECT
    friend class PowerTestInstanceGetter;

private:
    explicit PowerTest(QObject *parent = 0);

public:
    ~PowerTest();

public:
    bool SetPowerTestConfig(const QMap<int,int> &map_StationPort);

    bool OpenUsbDevice(const QMap<int, libusb_device *> &map_LDevice);

    bool CloseUsbDevice();

    bool StartPowerTest();

    bool GetPowerTestResult(QMap<int,bool> &map_OpenDeviceResult,
                            QMap<int, bool> &map_SendCmdResult);

    //for other thread
    bool WriteSendCmdResult(int n_Station, bool b_Result);
    //for other thread
    bool StartSinglePowerTest(libusb_device_handle *p_LDHandle);

private:
    bool WriteCmdInDongle(libusb_device_handle *p_LDHandle,
                          uchar *uc_Data,
                          ushort us_Length);

    bool ReadDetailsFromDongle(libusb_device_handle *p_LDHandle,
                               uchar *uc_Data,
                               ushort us_Length);

    bool SendCmdToDogle(libusb_device_handle *p_LDHandle,
                        uchar *uc_Data,
                        ushort us_Length);

    bool JudgeEnterCommandModel(libusb_device_handle *p_LDHandle);
    bool EnterTestModel(libusb_device_handle *p_LDHandle);
    bool TestSignalCarrier(libusb_device_handle *p_LDHandle);

    bool CompletePowerTest();

    void WorkSleep(uint un_Msec);

signals:
    void sig_SendCmdComplete();

private slots:
    void slot_TimeOut();

private:
    QThreadPool m_oQThreadPool;
    QMutex m_oQMutex;
    QTimer *m_pQTimer;

    QMap<int, libusb_device_handle * > m_mapLDHandle;
    QMap<int, bool> m_mapSendCmdResult;
    QMap<int,bool> m_mapOpenDeviceResult;
    QMap<int, int> m_mapStationPort;
};

#endif // POWERTEST_H
