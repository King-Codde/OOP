#ifndef COMMON_H
#define COMMON_H

#include <QString>

enum messages
{
    MATRIX_SIZE_REQUEST = 1,
    SET_VALUE_REQUEST = 2,

    DETERMINANT_REQUEST = 3,
    TRANSPOSE_REQUEST = 4,
    RANG_REQUEST = 5,
    PRINT_REQUEST = 6,

    DETERMINANT_ANSWER = 7,
    //TRANSPOSE_ANSWER = 8,
    RANG_ANSWER = 8,
    PRINT_ANSWER = 9,
};

extern const QChar separator;
QString& operator<< (QString&,const QString&);
QString& operator<< (QString&,const int&);
int& operator>>(QByteArray&,int&);

#endif // COMMON_H
