#ifndef CONFIGFILE_H
#define CONFIGFILE_H
#include "datafile_define.h"

class ConfigFile
{
public:
//    bool SavePCTestConfig(const ushort &us_SequenceNumber,
//                          STRUCT_PCTESTCONFIG &struct_PCTestConfig);

//    bool GetPCTestConfig(const ushort &us_SequenceNumber,
//                         STRUCT_PCTESTCONFIG &struct_PCTestConfig);

    bool SaveUsbControlConfig(const ushort &us_SequenceNumber,
                              STRUCT_USBCONTROLCONFIG &struct_UsbControlConfig);

    bool GetUsbControlConfig(const ushort &us_SequenceNumber,
                             STRUCT_USBCONTROLCONFIG &struct_UsbControlConfig);

    bool GetEquitmentConfig(STRUCT_EQUITMENTCONFIG &struct_EquitmentConfig);

    bool SaveEquitmenConfig(STRUCT_EQUITMENTCONFIG &struct_EquitmentConfig);


public:
    bool TransformToList(const QString &str_Data, QList<int> &list_Data);

    bool TransformToQString(const QList<int> &list_Data, QString &str_Data);

    void TransformToList(const QString &str_Data, QList<QString> &list_Data);

    bool TransformToQString(const QList<QString> &list_Data, QString &str_Data);

    bool TransformToMap(const QString &str_Data,
                        QMap<int,int> &map_SequenceData);

    bool TransformToQString(const QMap<int,int> &map_SequenceData,
                            QString &str_Data);


private:
    bool TransformToQString(const ushort &us_SequenceNumber,
                            const QMap<int,int> &map_SequenceData,
                            QString &str_Data);

    bool TransformToMap(const ushort &us_SequenceNumber,
                        const QString &str_Data,
                        QMap<int,int> &map_SequenceData);

};

#endif // CONFIGFILE_H
