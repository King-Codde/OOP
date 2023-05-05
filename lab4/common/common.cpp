#include "common.h"

const QChar separator(';');

QString& operator<< (QString& m, const QString& s)
{
    m += s;
    m.append(separator);
    return m;
}

QString& operator<< (QString& m, const int& s)
{
    QString str_s = QString().setNum(s);
    m += str_s;
    return m;
}

int& operator>>(QByteArray& arr,int& res)
{
    int p = arr.indexOf(separator.toLatin1());
    //p = arr.indexOf(separator.toLatin1(),p+1);
    if (p > 0)
    {
        res = arr.left(p).toInt();
    }
    arr = arr.right(arr.length()-p-1);
    return res;
}

/*TRational::TRational(const QByteArray& arr)
{
    int p = arr.indexOf(SEPARATOR);
    numerator = arr.left(p).toInt();
    denominator = arr.right(arr.length()-p-1).toInt();
}*/

