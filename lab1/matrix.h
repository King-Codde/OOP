#ifndef TMATRIX_H
#define TMATRIX_H
#include "number.h"
#include "iostream"
#include "math.h"

class Tmatrix
{
    int matrix_size = 2;
    number **matrix;
public:
    Tmatrix();
    Tmatrix(int);
    Tmatrix(const Tmatrix&);
    void copy(number** mass);
    number det() const;
    int rank() const;
    void transpose();
    Tmatrix& operator= (const Tmatrix&);
    friend std::ostream& operator<< (std::ostream&, const Tmatrix&);
    void get(int i, int j, number num){
        matrix[i][j] = num;
    }
    ~Tmatrix();
};

#endif // TMATRIX_H
