#ifndef TCOMPLEX_H
#define TCOMPLEX_H

#include <iostream>

class TComplex {
    double re_;
    double im_;
public:
    TComplex();
    TComplex(double re);
    TComplex(double re, double im);

    TComplex operator-() const;

    friend TComplex operator+(const TComplex& lhv, const TComplex& rhv);
    friend TComplex operator-(const TComplex& lhv, const TComplex& rhv);
    friend TComplex operator*(const TComplex& lhv, const TComplex& rhv);
    friend TComplex operator/(const TComplex& lhv, const TComplex& rhv);

    friend std::istream& operator >>(std::istream& str, TComplex& num);
    friend std::ostream& operator <<(std::ostream& str, const TComplex& num);

    friend TComplex abs(const TComplex& num);

    friend bool operator>(const TComplex& lhv, const TComplex& rhv);
    friend bool operator<(const TComplex& lhv, const TComplex& rhv);
};

#endif // TCOMPLEX_H
