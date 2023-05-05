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
    int size() const;
    void copy(number** mass);
    number det() const;
    int rank() const;
    void transpose();
    Tmatrix& operator= (const Tmatrix&);
    friend std::ostream& operator<< (std::ostream&, const Tmatrix&);
    void set(int i, int j, const number& num);
    const number& get(int i, int j) const;
    number& get(int i, int j);
    ~Tmatrix();
};

#endif // TMATRIX_H
