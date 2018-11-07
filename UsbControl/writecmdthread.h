#ifndef WRITECMDTHREAD_H
#define WRITECMDTHREAD_H
#include <QRunnable>
#include <QString>
#include "libusb-1.0/libusb.h"

class WriteCmdThread : public QRunnable
{
public:
    void run();
    void SetStation(int n_Station);
    void SetLDHandle(libusb_device_handle *p_LDHandle);
private:
    int m_nStation;
    libusb_device_handle *m_pLDHandle;
};

#endif // WRITECMDTHREAD_H
