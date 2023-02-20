#ifndef TMATRIX_H
#define TMATRIX_H
#include "number.h"
#include "iostream"

class Tmatrix
{
    int matrix_size = 2;
    number **matrix;
public:
    Tmatrix();
    Tmatrix(int);
    number det() const;
    int rank() const;
    void transpose();
    friend std::ostream& operator<< (std::ostream&, const Tmatrix&);
    ~Tmatrix();
};

#endif // TMATRIX_H
