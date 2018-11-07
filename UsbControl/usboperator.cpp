#include "usboperator.h"
#include <QTime>
#include <QCoreApplication>
#include <QEventLoop>
#include <QDebug>

UsbOperator::UsbOperator(QThread *parent)
    : QThread(parent)
{
    m_pLibusbContext    = NULL;
    m_bLibusbState      = false;
    m_unPid             = 0;
    m_unVid             = 0;
    m_nRunTime          = 0;
    m_nDeviceNumber     = 0;
}

UsbOperator::~UsbOperator()
{
    ExitUsbOperator();
}

bool UsbOperator::InitUsbOperator()
{
    int n_Ret = libusb_init(&m_pLibusbContext);
    if(n_Ret < 0){
        m_bLibusbState = false;
        return false;
    }

    m_bLibusbState = true;
    return true;
}

bool UsbOperator::ExitUsbOperator()
{
    if(m_bLibusbState){
        libusb_exit(m_pLibusbContext);
        m_pLibusbContext = NULL;        
    }
    m_bLibusbState = false;
    return true;
}

bool UsbOperator::StartNewOperator()
{
    if(!m_mapLDevice.isEmpty()){
        m_mapLDevice.clear();
    }

    if(!m_listDevicePort.isEmpty()){
        m_listDevicePort.clear();
    }

    return true;
}

bool UsbOperator::GetDevice(QMap<int, libusb_device *> &map_LDevice)
{
    map_LDevice = m_mapLDevice;
    return true;
}

bool UsbOperator::GetDevicePort(QList<int> &list_DevicePort)
{
    list_DevicePort = m_listDevicePort;
    return true;
}

bool UsbOperator::SetFindUsbDeviceConfig(const uint &un_Pid,
                                         const uint &un_Vid,
                                         const int &n_DeviceNumber,
                                         const int &n_Time)
{
    m_unPid = un_Pid;
    m_unVid = un_Vid;
    m_nDeviceNumber = n_DeviceNumber;
    m_nRunTime = n_Time;
    return true;
}

void UsbOperator::WorkSleep(uint un_Msec)
{
    QTime o_DieTime = QTime::currentTime().addMSecs(un_Msec);
    while(QTime::currentTime() < o_DieTime ){
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        QThread::msleep(10);
    }
}

/*
 * Overall summery of the sysfs structure path:
 *
 *  |_usb root hub - bus number - 1
 *      |_ port number - 1 of root hub
 *          |_port number - 3 of intermediate hub
 *              |_current configuration number - 1
 *                  |_ current interface number - 0
 *
 */
bool UsbOperator::FindUsbDevicePort(const uint &un_Pid,
                                    const uint &un_Vid,
                                    QMap<int, libusb_device *> &map_LDevice,
                                    QList<int> &list_DevicePort)
{
   libusb_device **ld_Device = NULL;
   ssize_t ss_Cnt = 0;
   ss_Cnt = libusb_get_device_list(m_pLibusbContext, &ld_Device);
   if(ss_Cnt < 0){
       return false;
   }

   int n_Device = 0;
   libusb_device *ld_pDevice;

   while(ld_Device[n_Device] != NULL){

       struct libusb_device_descriptor ldd_Descriptor;
       ld_pDevice = ld_Device[n_Device];

       n_Device++;

       int n_Ret = 0;
       n_Ret = libusb_get_device_descriptor(ld_pDevice, &ldd_Descriptor);

       if(n_Ret < 0){
           libusb_free_device_list(ld_Device, 1);
           return false;
       }

//       qDebug()<<"un_Pid"<<un_Pid;
//       qDebug()<<"un_Vid"<<un_Vid;

//       qDebug()<<"idProduct"<<ldd_Descriptor.idProduct;
//       qDebug()<<"idVendor"<<ldd_Descriptor.idVendor;

       if(ldd_Descriptor.idProduct == un_Pid && ldd_Descriptor.idVendor == un_Vid){
           QString str_PortName = QString::number(libusb_get_port_number(ld_pDevice));

           libusb_device *ld_pDeviceParent = NULL;
           ld_pDeviceParent = ld_pDevice;

            do{
                ld_pDeviceParent = libusb_get_parent(ld_pDeviceParent);
                if(ld_pDeviceParent){
                    str_PortName += QString::number(libusb_get_port_number(ld_pDeviceParent));
                }

                qDebug()<<"libusb_get_parent";
            }while(ld_pDeviceParent);

            qDebug()<<"str_PortName"<<str_PortName;
            map_LDevice.insert(str_PortName.toInt(), ld_pDevice);

            if(!list_DevicePort.contains(str_PortName.toInt())){
               list_DevicePort.append(str_PortName.toInt());
            }
        }
   }

   libusb_free_device_list(ld_Device, 1);
   return true;
}

void UsbOperator::RunComplete()
{
    emit sig_RunComplete();
}

void UsbOperator::run()
{
    qDebug()<<"run";
    QTime _DieTime = QTime::currentTime().addMSecs(m_nRunTime);
    while(QTime::currentTime() < _DieTime) {
        if(!m_mapLDevice.isEmpty() || !m_listDevicePort.isEmpty()){
            break;
        }

        if(FindUsbDevicePort(m_unPid, m_unVid, m_mapLDevice, m_listDevicePort)){
            //nothing to do
        }
        if(m_listDevicePort.count() >= m_nDeviceNumber){
            break;
        }
        WorkSleep(500);
    }

    RunComplete();
}
