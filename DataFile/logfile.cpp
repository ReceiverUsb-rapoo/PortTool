#include "logfile.h"
#include <QDir>
#include <QFile>
#include <QApplication>
#include <QDateTime>

LogFile::LogFile()
{

}

QString LogFile::Addlog(const QString &str_Info)
{
    QDir o_QDir;

    QString str_Path = QDir::currentPath() + LogPath;

    if(!o_QDir.exists(str_Path)){
        o_QDir.mkpath(str_Info);
    }

    QDateTime o_QDateTime = QDateTime::currentDateTime();
    str_Path = str_Path + QString("/%1-%2-%3").
            arg(o_QDateTime.date().year()).
            arg(o_QDateTime.date().month()).
            arg(o_QDateTime.date().day()) + LogFileName;

    QFile o_QFile(str_Path);

    if(!o_QFile.open(QIODevice::WriteOnly|QIODevice::Append|QIODevice::Text)){
        return str_Info;
    }

    QString str_InfoAddTime = QString("%1:%2:%3 %4\r\n").
            arg(o_QDateTime.time().hour()).
            arg(o_QDateTime.time().minute()).
            arg(o_QDateTime.time().second()).
            arg(str_Info);

    o_QFile.write(str_InfoAddTime.toStdString().c_str());

    o_QFile.close();

    return str_InfoAddTime;
}
