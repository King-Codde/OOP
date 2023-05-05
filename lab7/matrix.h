#ifndef MATRIX_H
#define MATRIX_H
#include <QVector>



class matrix{
public:
    matrix(int);
    qint16 get(int, int);
    void set(qint16, int, int);
    int len(){return length;}
private:
    QVector<QVector<qint16>> vector;
    int length = 0;
};

#endif // MATRIX_H
