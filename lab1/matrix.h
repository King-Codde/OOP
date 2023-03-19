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

    Tmatrix(int _n,int)
    {
        matrix_size = _n;

        matrix = (number**) new number*[matrix_size];

        for (int i = 0; i < matrix_size; i++)
          matrix[i] = (number*)new number[matrix_size];

        for (int i = 0; i < matrix_size; i++)
          for (int j = 0; j < matrix_size; j++)
            matrix[i][j] = 1;
    }

    Tmatrix(const Tmatrix&);
    void copy(number** mass);
    number det() const;
    int rank() const;
    void transpose();
    Tmatrix& operator= (const Tmatrix&);
    friend std::ostream& operator<< (std::ostream&, const Tmatrix&);
    ~Tmatrix();
};

#endif // TMATRIX_H
