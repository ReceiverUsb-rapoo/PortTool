#include "configfile.h"
#include <QDir>
#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QApplication>
#include <QStringList>
#include <QtDebug>

//bool ConfigFile::SavePCTestConfig(const ushort &us_SequenceNumber,
//                                  STRUCT_PCTESTCONFIG &struct_PCTestConfig)
//{
//    QString str_FilePath = QDir::currentPath() +
//            PCConfigPath;

//    QDir o_QDir(str_FilePath);
//    if(!o_QDir.exists()){
//        o_QDir.mkpath(str_FilePath);
//    }


//    str_FilePath += "/" + QString::number(us_SequenceNumber) +
//    PCConfigFileName;


//    QFile o_QFileConfig(str_FilePath);

//    if(!o_QFileConfig.open(QIODevice::WriteOnly | QIODevice::Text)){
//        return false;
//    }

//    QXmlStreamWriter o_QXmlStreamWriter(&o_QFileConfig);
//    o_QXmlStreamWriter.setAutoFormatting(true);
//    o_QXmlStreamWriter.writeStartDocument();
//    o_QXmlStreamWriter.writeStartElement("PCConfig_" + QString::number(us_SequenceNumber));

//    o_QXmlStreamWriter.writeTextElement("Versions", struct_PCTestConfig.str_ProjectVersions);
//    o_QXmlStreamWriter.writeTextElement("str_ProjectName", struct_PCTestConfig.str_ProjectName);

//    o_QXmlStreamWriter.writeTextElement("TestType", QString::number(struct_PCTestConfig.TestType));
//    o_QXmlStreamWriter.writeTextElement("un_FWPosition", QString::number(struct_PCTestConfig.un_FWPosition));
//    o_QXmlStreamWriter.writeTextElement("us_FWPid", QString::number(struct_PCTestConfig.us_FWPid));
//    o_QXmlStreamWriter.writeTextElement("us_FWVid", QString::number(struct_PCTestConfig.us_FWVid));
//    o_QXmlStreamWriter.writeTextElement("us_PoweredDelay", QString::number(struct_PCTestConfig.us_PoweredDelay));
//    o_QXmlStreamWriter.writeTextElement("us_ReadRFDelay", QString::number(struct_PCTestConfig.us_ReadRFDelay));
//    o_QXmlStreamWriter.writeTextElement("us_DischargeTimeSelect", QString::number(struct_PCTestConfig.us_DischargeTimeSelect));
//    o_QXmlStreamWriter.writeTextElement("us_DUTVoltageSelect", QString::number(struct_PCTestConfig.us_DUTVoltageSelect));
//    o_QXmlStreamWriter.writeTextElement("uc_RetestTimes", QString::number(struct_PCTestConfig.uc_RetestTimes));
//    o_QXmlStreamWriter.writeTextElement("uc_SingleTestCount", QString::number(struct_PCTestConfig.uc_SingleTestCount));
//    o_QXmlStreamWriter.writeTextElement("us_SinglePowerDelay", QString::number(struct_PCTestConfig.us_SinglePowerDelay));
//    o_QXmlStreamWriter.writeTextElement("us_SinglePowerTime", QString::number(struct_PCTestConfig.us_SinglePowerTime));
//    o_QXmlStreamWriter.writeTextElement("uc_PowerAvgTimes", QString::number(struct_PCTestConfig.uc_PowerAvgTimes));
//    o_QXmlStreamWriter.writeTextElement("uc_PowerChannel", QString::number(struct_PCTestConfig.uc_PowerChannel));
//    o_QXmlStreamWriter.writeTextElement("uc_PowerTestSwitch", QString::number(struct_PCTestConfig.uc_PowerTestSwitch));
//    o_QXmlStreamWriter.writeTextElement("us_FirstPowerTestDelay", QString::number(struct_PCTestConfig.us_FirstPowerTestDelay));
//    o_QXmlStreamWriter.writeTextElement("us_EnumTime", QString::number(struct_PCTestConfig.us_EnumTime));
//    o_QXmlStreamWriter.writeTextElement("uc_EnumTestSwitch", QString::number(struct_PCTestConfig.uc_EnumTestSwitch));
////    o_QXmlStreamWriter.writeTextElement("str_EnumPositionPort", struct_PCTestConfig.str_EnumPositionPort);
//    o_QXmlStreamWriter.writeTextElement("str_DUTFWPositions", struct_PCTestConfig.str_DUTFWPositions);
//    o_QXmlStreamWriter.writeTextElement("str_PowerDUTPositions", struct_PCTestConfig.str_PowerDUTPositions);
//    o_QXmlStreamWriter.writeTextElement("str_PowerTestGroups", struct_PCTestConfig.str_PowerTestGroups);
//    o_QXmlStreamWriter.writeTextElement("str_RFPowerDBUponLimit", struct_PCTestConfig.str_RFPowerDBUponLimit);
//    o_QXmlStreamWriter.writeTextElement("str_RFPowerDBLowerLimit", struct_PCTestConfig.str_RFPowerDBLowerLimit);

//    o_QXmlStreamWriter.writeEndElement();
//    o_QXmlStreamWriter.writeEndDocument();
//    o_QFileConfig.close();

//    return true;
//}

//bool ConfigFile::GetPCTestConfig(const ushort &us_SequenceNumber,
//                                 STRUCT_PCTESTCONFIG &struct_PCTestConfig)
//{
//    QString str_FilePath = QDir::currentPath() +
//            PCConfigPath;

//    QDir o_QDir(str_FilePath);
//    if(!o_QDir.exists()){
//        o_QDir.mkpath(str_FilePath);
//    }

//    str_FilePath += "/" + QString::number(us_SequenceNumber) + PCConfigFileName;

//    QFile o_QFileConfig(str_FilePath);

//    if(!o_QFileConfig.open(QIODevice::ReadOnly | QIODevice::Text)){
//        return false;
//    }

//    QXmlStreamReader o_QXmlStreamReader(&o_QFileConfig);
////    o_QXmlStreamReader.readNext();
//    while(!o_QXmlStreamReader.atEnd()){
//        QXmlStreamReader::TokenType Token = o_QXmlStreamReader.readNext();
////        qDebug()<<"name"<<o_QXmlStreamReader.name();
////        qDebug()<<"text"<<o_QXmlStreamReader.text();
////        qDebug()<<" ";
////        qDebug()<<" ";

//        if(Token == QXmlStreamReader::StartDocument){
//            continue;
//        }

//        if(Token == QXmlStreamReader::EndElement){
//            continue;
//        }

//        if(Token == QXmlStreamReader::Characters){
//            continue;
//        }


//        if(o_QXmlStreamReader.name() == "Versions"){
//            o_QXmlStreamReader.readNext();
//            struct_PCTestConfig.str_ProjectVersions = o_QXmlStreamReader.text().toString();
//        }
//        else if(o_QXmlStreamReader.name() == "str_ProjectName"){
//            o_QXmlStreamReader.readNext();
//            struct_PCTestConfig.str_ProjectName = o_QXmlStreamReader.text().toString();
//        }
//        else if(o_QXmlStreamReader.name() == "TestType"){
//            o_QXmlStreamReader.readNext();
//            struct_PCTestConfig.TestType = (ENUM_TESTTYPE)o_QXmlStreamReader.text().toInt();
//        }
//        else if(o_QXmlStreamReader.name() == "un_FWPosition"){
//            o_QXmlStreamReader.readNext();
//            struct_PCTestConfig.un_FWPosition = o_QXmlStreamReader.text().toUInt();
//        }
//        else if(o_QXmlStreamReader.name() == "us_FWPid"){
//            o_QXmlStreamReader.readNext();
//            struct_PCTestConfig.us_FWPid = o_QXmlStreamReader.text().toUShort();
//        }
//        else if(o_QXmlStreamReader.name() == "us_FWVid"){
//            o_QXmlStreamReader.readNext();
//            struct_PCTestConfig.us_FWVid = o_QXmlStreamReader.text().toUShort();
//        }
//        else if(o_QXmlStreamReader.name() == "us_PoweredDelay"){
//            o_QXmlStreamReader.readNext();
//            struct_PCTestConfig.us_PoweredDelay = o_QXmlStreamReader.text().toUShort();
//        }
//        else if(o_QXmlStreamReader.name() == "us_ReadRFDelay"){
//            o_QXmlStreamReader.readNext();
//            struct_PCTestConfig.us_ReadRFDelay = o_QXmlStreamReader.text().toUShort();
//        }
//        else if(o_QXmlStreamReader.name() == "us_DischargeTimeSelect"){
//            o_QXmlStreamReader.readNext();
//            struct_PCTestConfig.us_DischargeTimeSelect = o_QXmlStreamReader.text().toUShort();
//        }
//        else if(o_QXmlStreamReader.name() == "us_DUTVoltageSelect"){
//            o_QXmlStreamReader.readNext();
//            struct_PCTestConfig.us_DUTVoltageSelect = o_QXmlStreamReader.text().toUShort();
//        }
//        else if(o_QXmlStreamReader.name() == "uc_RetestTimes"){
//            o_QXmlStreamReader.readNext();
//            struct_PCTestConfig.uc_RetestTimes = (uchar)o_QXmlStreamReader.text().toInt();
//        }
//        else if(o_QXmlStreamReader.name() == "uc_SingleTestCount"){
//            o_QXmlStreamReader.readNext();
//            struct_PCTestConfig.uc_SingleTestCount = (uchar)o_QXmlStreamReader.text().toInt();
//        }
//        else if(o_QXmlStreamReader.name() == "us_SinglePowerDelay"){
//            o_QXmlStreamReader.readNext();
//            struct_PCTestConfig.us_SinglePowerDelay = o_QXmlStreamReader.text().toUShort();
//        }
//        else if(o_QXmlStreamReader.name() == "us_SinglePowerTime"){
//            o_QXmlStreamReader.readNext();
//            struct_PCTestConfig.us_SinglePowerTime = o_QXmlStreamReader.text().toUShort();
//        }
//        else if(o_QXmlStreamReader.name() == "uc_PowerAvgTimes"){
//            o_QXmlStreamReader.readNext();
//            struct_PCTestConfig.uc_PowerAvgTimes = (uchar)o_QXmlStreamReader.text().toInt();
//        }
//        else if(o_QXmlStreamReader.name() == "uc_PowerChannel"){
//            o_QXmlStreamReader.readNext();
//            struct_PCTestConfig.uc_PowerChannel = (uchar)o_QXmlStreamReader.text().toInt();
//        }
//        else if(o_QXmlStreamReader.name() == "uc_PowerTestSwitch"){
//            o_QXmlStreamReader.readNext();
//            struct_PCTestConfig.uc_PowerTestSwitch = (uchar)o_QXmlStreamReader.text().toInt();
//        }
//        else if(o_QXmlStreamReader.name() == "us_FirstPowerTestDelay"){
//            o_QXmlStreamReader.readNext();
//            struct_PCTestConfig.us_FirstPowerTestDelay = o_QXmlStreamReader.text().toUShort();
//        }
//        else if(o_QXmlStreamReader.name() == "us_EnumTime"){
//            o_QXmlStreamReader.readNext();
//            struct_PCTestConfig.us_EnumTime = o_QXmlStreamReader.text().toUShort();
//        }
//        else if(o_QXmlStreamReader.name() == "uc_EnumTestSwitch"){
//            o_QXmlStreamReader.readNext();
//            struct_PCTestConfig.uc_EnumTestSwitch = (uchar)o_QXmlStreamReader.text().toInt();
//        }
//        else if(o_QXmlStreamReader.name() == "str_DUTFWPositions"){
//            o_QXmlStreamReader.readNext();
//            struct_PCTestConfig.str_DUTFWPositions = o_QXmlStreamReader.text().toString();
//        }
////        else if(o_QXmlStreamReader.name() == "str_EnumPositionPort"){
////            o_QXmlStreamReader.readNext();
////            struct_PCTestConfig.str_EnumPositionPort = o_QXmlStreamReader.text().toString();
////        }
//        else if(o_QXmlStreamReader.name() == "str_PowerDUTPositions"){
//            o_QXmlStreamReader.readNext();
//            struct_PCTestConfig.str_PowerDUTPositions = o_QXmlStreamReader.text().toString();
//        }
//        else if(o_QXmlStreamReader.name() == "str_PowerTestGroups"){
//            o_QXmlStreamReader.readNext();
//            struct_PCTestConfig.str_PowerTestGroups = o_QXmlStreamReader.text().toString();
//        }
//        else if(o_QXmlStreamReader.name() == "str_RFPowerDBUponLimit"){
//            o_QXmlStreamReader.readNext();
//            struct_PCTestConfig.str_RFPowerDBUponLimit = o_QXmlStreamReader.text().toString();
//        }
//        else if(o_QXmlStreamReader.name() == "str_RFPowerDBLowerLimit"){
//            o_QXmlStreamReader.readNext();
//            struct_PCTestConfig.str_RFPowerDBLowerLimit = o_QXmlStreamReader.text().toString();
//        }
//    }

//    if(o_QXmlStreamReader.hasError()){
//        qDebug() << QString::fromLocal8Bit("错误信息：%1  行号：%2  列号：%3  字符位移：%4").
//                    arg(o_QXmlStreamReader.errorString()).
//                    arg(o_QXmlStreamReader.lineNumber()).
//                    arg(o_QXmlStreamReader.columnNumber()).
//                    arg(o_QXmlStreamReader.characterOffset());
//        return false;
//    }

//    return true;
//}


bool ConfigFile::SaveUsbControlConfig(const ushort &us_SequenceNumber,
                                     STRUCT_USBCONTROLCONFIG &struct_UsbControlConfig)
{  
    QString str_FilePath = QDir::currentPath() +
            UsbControlConfigPath;

    QDir o_QDir(str_FilePath);
    if(!o_QDir.exists()){
        o_QDir.mkpath(str_FilePath);
    }

    str_FilePath += "/" + QString::number(us_SequenceNumber) + UsbControlFileName;

    QFile o_QFileConfig(str_FilePath);

    if(!o_QFileConfig.open(QIODevice::WriteOnly | QIODevice::Text)){
        return false;
    }

    QXmlStreamWriter o_QXmlStreamWriter(&o_QFileConfig);
    o_QXmlStreamWriter.setAutoFormatting(true);
    o_QXmlStreamWriter.writeStartDocument();
    o_QXmlStreamWriter.writeStartElement("UsbControl_" + QString::number(us_SequenceNumber));

    o_QXmlStreamWriter.writeTextElement("un_Pid", QString::number(struct_UsbControlConfig.un_Pid));
    o_QXmlStreamWriter.writeTextElement("un_Vid", QString::number(struct_UsbControlConfig.un_Vid));
    o_QXmlStreamWriter.writeTextElement("n_Time", QString::number(struct_UsbControlConfig.n_Time));

    QString str_StationPort;
    TransformToQString(us_SequenceNumber,
                       struct_UsbControlConfig.map_StationPort,
                       str_StationPort);

    o_QXmlStreamWriter.writeTextElement("str_StationPort",str_StationPort);

    o_QXmlStreamWriter.writeEndElement();
    o_QXmlStreamWriter.writeEndDocument();
    o_QFileConfig.close();

    return true;
}

bool ConfigFile::GetUsbControlConfig(const ushort &us_SequenceNumber,
                                     STRUCT_USBCONTROLCONFIG &struct_UsbControlConfig)
{
    QString str_FilePath = QDir::currentPath() +
            UsbControlConfigPath;

    QDir o_QDir(str_FilePath);
    if(!o_QDir.exists()){
        o_QDir.mkpath(str_FilePath);
    }

    str_FilePath += "/" + QString::number(us_SequenceNumber) + UsbControlFileName;

    QFile o_QFileConfig(str_FilePath);
    if(!o_QFileConfig.open(QIODevice::ReadOnly | QIODevice::Text)){
        return false;
    }

    QXmlStreamReader o_QXmlStreamReader(&o_QFileConfig);
    o_QXmlStreamReader.readNext();
    while(!o_QXmlStreamReader.atEnd()){
        QXmlStreamReader::TokenType Token = o_QXmlStreamReader.readNext();

        if(Token == QXmlStreamReader::StartDocument){
            continue;
        }

        if(Token == QXmlStreamReader::EndElement){
            continue;
        }

        if(Token == QXmlStreamReader::Characters){
            continue;
        }

        if(o_QXmlStreamReader.name() == "un_Pid"){
            o_QXmlStreamReader.readNext();
            struct_UsbControlConfig.un_Pid = o_QXmlStreamReader.text().toInt();
        }
        else if(o_QXmlStreamReader.name() == "un_Vid"){
            o_QXmlStreamReader.readNext();
            struct_UsbControlConfig.un_Vid = o_QXmlStreamReader.text().toInt();
        }
        else if(o_QXmlStreamReader.name() == "n_Time"){
            o_QXmlStreamReader.readNext();
            struct_UsbControlConfig.n_Time = o_QXmlStreamReader.text().toInt();
        }
        else if(o_QXmlStreamReader.name() == "str_StationPort"){
            o_QXmlStreamReader.readNext();
            QString str_Data = o_QXmlStreamReader.text().toString();
            QMap<int, int> map_SequenceData;

            TransformToMap(us_SequenceNumber, str_Data, map_SequenceData);
            struct_UsbControlConfig.map_StationPort = map_SequenceData;
        }
    }

    if(o_QXmlStreamReader.hasError()){
        return false;
    }

    return true;
}

bool ConfigFile::GetEquitmentConfig(STRUCT_EQUITMENTCONFIG &struct_EquitmentConfig)
{    
    QString str_FilePath = QDir::currentPath() +
            EquitmentConfigPath;

    QDir o_QDir(str_FilePath);
    if(!o_QDir.exists()){
        o_QDir.mkpath(str_FilePath);
    }

    str_FilePath += "/" + EquitmentFileName;

    QFile o_QFileConfig(str_FilePath);

    if(!o_QFileConfig.open(QIODevice::ReadOnly | QIODevice::Text)){
        return false;
    }

    QXmlStreamReader o_QXmlStreamReader(&o_QFileConfig);
    o_QXmlStreamReader.readNext();
    while(!o_QXmlStreamReader.atEnd()){
        QXmlStreamReader::TokenType Token = o_QXmlStreamReader.readNext();

        if(Token == QXmlStreamReader::StartDocument){
            continue;
        }

        if(Token == QXmlStreamReader::EndElement){
            continue;
        }

        if(Token == QXmlStreamReader::Characters){
            continue;
        }

        if(o_QXmlStreamReader.name() == "Com"){
            o_QXmlStreamReader.readNext();
            QString str_ComList = o_QXmlStreamReader.text().toString();
            QList<QString> list_ComName;

            TransformToList(str_ComList, list_ComName);
            struct_EquitmentConfig.list_ComName = list_ComName;
        }
        else if(o_QXmlStreamReader.name() == "un_ComPid"){
            o_QXmlStreamReader.readNext();
            struct_EquitmentConfig.un_ComPid = o_QXmlStreamReader.text().toUInt();
        }
        else if(o_QXmlStreamReader.name() == "un_ComVid"){
            o_QXmlStreamReader.readNext();
            struct_EquitmentConfig.un_ComVid = o_QXmlStreamReader.text().toUInt();
        }
        else if(o_QXmlStreamReader.name() == "str_ComputerIP"){
            o_QXmlStreamReader.readNext();
            struct_EquitmentConfig.str_ComputerIP = o_QXmlStreamReader.text().toString();
        }
        else if(o_QXmlStreamReader.name() == "us_ComputerPort"){
            o_QXmlStreamReader.readNext();
            struct_EquitmentConfig.us_ComputerPort = o_QXmlStreamReader.text().toUShort();
        }
        else if(o_QXmlStreamReader.name() == "n_OpemWithComName"){
            o_QXmlStreamReader.readNext();
            struct_EquitmentConfig.n_OpemWithComName = o_QXmlStreamReader.text().toInt();
        }
        else if(o_QXmlStreamReader.name() == "n_OpemWithPidVid"){
            o_QXmlStreamReader.readNext();
            struct_EquitmentConfig.n_OpemWithPidVid = o_QXmlStreamReader.text().toInt();
        }
        else if(o_QXmlStreamReader.name() == "n_BoxUnuse"){
            o_QXmlStreamReader.readNext();
            struct_EquitmentConfig.n_BoxUnuse = o_QXmlStreamReader.text().toInt();
        }
        else if(o_QXmlStreamReader.name() == "n_RobotUnuse"){
            o_QXmlStreamReader.readNext();
            struct_EquitmentConfig.n_RobotUnuse = o_QXmlStreamReader.text().toInt();
        }
        else if(o_QXmlStreamReader.name() == "BoxIP"){
            o_QXmlStreamReader.readNext();
            QString str_BoxIPList = o_QXmlStreamReader.text().toString();
            QList<QString> list_BoxIP;

            TransformToList(str_BoxIPList, list_BoxIP);
            struct_EquitmentConfig.list_BoxIP = list_BoxIP;
        }
        else if(o_QXmlStreamReader.name() == "RobotIP"){
            o_QXmlStreamReader.readNext();
            QString str_RobotIPList = o_QXmlStreamReader.text().toString();
            QList<QString> list_RobotIP;

            TransformToList(str_RobotIPList, list_RobotIP);
            struct_EquitmentConfig.list_RobotIP = list_RobotIP;
        }
    }
    if(o_QXmlStreamReader.hasError()){
        return false;
    }

    return true;
}

bool ConfigFile::SaveEquitmenConfig(STRUCT_EQUITMENTCONFIG &struct_EquitmentConfig)
{
    QString str_FilePath = QDir::currentPath() +
            EquitmentConfigPath;

    QDir o_QDir(str_FilePath);
    if(!o_QDir.exists()){
        o_QDir.mkpath(str_FilePath);
    }

    str_FilePath += "/" + EquitmentFileName;

    QFile o_QFileConfig(str_FilePath);

    if(!o_QFileConfig.open(QIODevice::WriteOnly | QIODevice::Text)){
        return false;
    }

    QString str_ComName = "";
    QString str_BoxIP = "";
    QString str_RobotIP = "";

    TransformToQString(struct_EquitmentConfig.list_ComName, str_ComName);
    TransformToQString(struct_EquitmentConfig.list_BoxIP, str_BoxIP);
    TransformToQString(struct_EquitmentConfig.list_RobotIP, str_RobotIP);

    QXmlStreamWriter o_QXmlStreamWriter(&o_QFileConfig);
    o_QXmlStreamWriter.setAutoFormatting(true);
    o_QXmlStreamWriter.writeStartDocument();
    o_QXmlStreamWriter.writeStartElement("Equitment");

    o_QXmlStreamWriter.writeTextElement("Com", str_ComName);
    o_QXmlStreamWriter.writeTextElement("un_ComPid", QString::number(struct_EquitmentConfig.un_ComPid));
    o_QXmlStreamWriter.writeTextElement("un_ComVid", QString::number(struct_EquitmentConfig.un_ComVid));
    o_QXmlStreamWriter.writeTextElement("str_ComputerIP", struct_EquitmentConfig.str_ComputerIP);
    o_QXmlStreamWriter.writeTextElement("us_ComputerPort", QString::number(struct_EquitmentConfig.us_ComputerPort));
    o_QXmlStreamWriter.writeTextElement("n_OpemWithComName", QString::number(struct_EquitmentConfig.n_OpemWithComName));
    o_QXmlStreamWriter.writeTextElement("n_OpemWithPidVid", QString::number(struct_EquitmentConfig.n_OpemWithPidVid));
    o_QXmlStreamWriter.writeTextElement("n_BoxUnuse", QString::number(struct_EquitmentConfig.n_BoxUnuse));
    o_QXmlStreamWriter.writeTextElement("n_RobotUnuse", QString::number(struct_EquitmentConfig.n_RobotUnuse));
    o_QXmlStreamWriter.writeTextElement("BoxIP", str_BoxIP);
    o_QXmlStreamWriter.writeTextElement("RobotIP", str_RobotIP);

    o_QXmlStreamWriter.writeEndElement();
    o_QXmlStreamWriter.writeEndDocument();
    o_QFileConfig.close();

    return true;
}

bool ConfigFile::TransformToList(const QString &str_Data,
                                 QList<int> &list_Data)
{
    QString str_OneData;
    QStringList strlist_Data = str_Data.split(',');

    if(strlist_Data.isEmpty()){
        return false;
    }

    for(int i = 0; i < strlist_Data.count(); i++){
        str_OneData = strlist_Data.at(i);
        list_Data.append(str_OneData.toInt());
    }
    return true;
}

bool ConfigFile::TransformToQString(const QList<int> &list_Data,
                                    QString &str_Data)
{
    if(list_Data.isEmpty()){
        return false;
    }

    QStringList strlist_Data;
    for(int i = 0; i < list_Data.count(); i++){
        strlist_Data.append(QString::number(list_Data.at(i)));
    }

    str_Data = strlist_Data.join(',');
    return true;
}

void ConfigFile::TransformToList(const QString &str_Data,
                                 QList<QString> &list_Data)
{
    QStringList strlist_Data = str_Data.split(',');

    if(strlist_Data.isEmpty()){
        return;
    }

    for(int i = 0; i < strlist_Data.count(); i++){
        list_Data.append(strlist_Data.at(i));
    }
}

bool ConfigFile::TransformToQString(const QList<QString> &list_Data,
                                    QString &str_Data)
{
    QStringList strlist_Data;

    if(list_Data.isEmpty()){
        return false;
    }

    for(int i = 0; i < list_Data.count(); i++){
        strlist_Data.append(list_Data.at(i));
    }

    str_Data = strlist_Data.join(',');
    return true;
}

bool ConfigFile::TransformToMap(const QString &str_Data,
                                QMap<int, int> &map_SequenceData)
{
    QStringList strlist_Data = str_Data.split(',');
    QString str_OneData = "";
    for(int i = 1; i <= strlist_Data.count(); i++){
        str_OneData = strlist_Data.at(i - 1);
        map_SequenceData.insert(i,str_OneData.toInt());
    }

    return true;
}

bool ConfigFile::TransformToQString(const QMap<int, int> &map_SequenceData,
                                    QString &str_Data)
{
    QStringList strlist_Data;
    for(int i = 1; i <= map_SequenceData.count(); i++){
        strlist_Data.append(QString::number(map_SequenceData.value(i)));
    }

    str_Data = strlist_Data.join(',');

    return true;
}


bool ConfigFile::TransformToQString(const ushort &us_SequenceNumber,
                                    const QMap<int, int> &map_SequenceData,
                                    QString &str_Data)
{
    int n_Number = map_SequenceData.count();
    int n_OneData = 0;
    QStringList strlist_Data;

    int n_UpperSequence = (us_SequenceNumber - 1)*OneGroupUsbNumber_DataFile;

    if(map_SequenceData.isEmpty()){
        return false;
    }

    for(int i = 1; i <= n_Number; i++){
        n_OneData = map_SequenceData.value(i + n_UpperSequence);
        strlist_Data.append(QString::number(n_OneData));

        /*
        QMapIterator<int, int> map_IteratorSequenceData(map_SequenceData);
        while(map_IteratorSequenceData.hasNext()){
            map_IteratorSequenceData.next();
            if(map_IteratorSequenceData.key() == i){
                strlist_Data.append(QString::number(map_IteratorSequenceData.value()));
            }
        }
        */
    }

    str_Data = strlist_Data.join(',');
    return true;
}

bool ConfigFile::TransformToMap(const ushort &us_SequenceNumber,
                                const QString &str_Data,
                                QMap<int, int> &map_SequenceData)
{
    QStringList strlist_Data = str_Data.split(',');
    QString str_OneData = "";

    int n_UpperSequence = (us_SequenceNumber - 1)*OneGroupUsbNumber_DataFile;

    if(strlist_Data.isEmpty()){
        return false;
    }

    for(int i = 1; i <= strlist_Data.count(); i++){
        str_OneData = strlist_Data.at(i + n_UpperSequence - 1);
        map_SequenceData.insert(i, str_OneData.toInt());
    }

    return true;
}
