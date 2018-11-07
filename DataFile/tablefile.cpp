#include "tablefile.h"
#include <QFile>
#include <QDir>
#include <QDateTime>
#include <QApplication>
#include <QFileDialog>

bool TableFile::SaveTableData_FixeAddress(const ushort &us_SequenceNumber,
                                          QTableWidget *p_QTableWidget)
{
    QString str_FilePath = QDir::currentPath() + TableDataPath;

    QDir o_QDir(str_FilePath);
    if(!o_QDir.exists()){
        o_QDir.mkpath(str_FilePath);
    }

    QDateTime o_QDateTime = QDateTime::currentDateTime();
    str_FilePath += QString::number(us_SequenceNumber) + QString("_%1:%2:%3").
            arg(o_QDateTime.time().hour()).
            arg(o_QDateTime.time().minute()).
            arg(o_QDateTime.time().second()) +
            TableDataFileName;

    return SaveTableData(us_SequenceNumber,
                         str_FilePath,
                         p_QTableWidget);
}

bool TableFile::SaveTableData_SelectAddress(const ushort &us_SequenceNumber,
                                            QTableWidget *p_QTableWidget)
{
    QString str_FilePath = QFileDialog::getSaveFileName(p_QTableWidget,
                                                        "另存为",
                                                        "D:/",
                                                        "file(*.csv)");
    if(str_FilePath.isEmpty()){
        return false;
    }

    return SaveTableData(us_SequenceNumber,
                         str_FilePath,
                         p_QTableWidget);
}

bool TableFile::SaveTableData(const ushort &us_SequenceNumber,
                              const QString &str_FilePath,
                              QTableWidget *p_QTableWidget)
{
    QFile o_QFile(str_FilePath);
    if(!o_QFile.open(QIODevice::WriteOnly)){
        return false;
    }

    QDateTime o_QDateTime = QDateTime::currentDateTime();
    QString str_TimeInfo = "时间," + QString("%1:%2:%3\r\n").
            arg(o_QDateTime.time().hour()).arg(o_QDateTime.time().minute()).
            arg(o_QDateTime.time().second());

    o_QFile.write(str_TimeInfo.toUtf8());
    QString str_TableInfo = "夹具序号：" + QString::number(us_SequenceNumber) + "\r\n";
    o_QFile.write(str_TableInfo.toUtf8());

    QList<QString> list_Header;
    list_Header.append("序号-测试目");
    for(int i = 0; i < p_QTableWidget->columnCount(); i++){
        list_Header.append(p_QTableWidget->horizontalHeaderItem(i)->text());
    }

    QString str_Header = list_Header.join(',') + "\n";
    o_QFile.write(str_Header.toUtf8());

    for(int i = 0; i < p_QTableWidget->rowCount(); i++){
        QList<QString> list_Data;
        list_Data.append(p_QTableWidget->verticalHeaderItem(i)->text());
        for(int j = 0; j < p_QTableWidget->columnCount(); j++){
            list_Data.append(p_QTableWidget->item(i,j)->text());
        }
        QString str_Data = list_Data.join(',') + "\n";
        o_QFile.write(str_Data.toUtf8());
    }

    o_QFile.close();
    return true;
}
