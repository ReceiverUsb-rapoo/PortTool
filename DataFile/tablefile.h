#ifndef TABLEFILE_H
#define TABLEFILE_H
#include <QString>
#include <QTableWidget>
#include "datafile_define.h"

class TableFile
{
public:
    bool SaveTableData_FixeAddress(const ushort &us_SequenceNumber,
                                   QTableWidget *p_QTableWidget);

    bool SaveTableData_SelectAddress(const ushort &us_SequenceNumber,
                                     QTableWidget *p_QTableWidget);

private:
    bool SaveTableData(const ushort &us_SequenceNumber,
                       const QString &str_FilePath,
                       QTableWidget *p_QTableWidget);
};

#endif // TABLEFILE_H
