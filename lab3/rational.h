#ifndef TRATIONAL_H
#define TRATIONAL_H

#include <iostream>

class TRational
{
    int numerator_ = 0;
    int denuminator_ = 1;

    void normalize();
public:
    TRational();
    TRational(int numerator);
    TRational(int numerator, int denuminator);
    TRational(const TRational& other);
    TRational& operator=(const TRational& other) = default;
    TRational& operator=(TRational&& other) = default;

    friend bool operator==(const TRational& lhv, const TRational& rhv);
    friend bool operator!=(const TRational& lhv, const TRational& rhv);
    friend bool operator> (const TRational& lhv, const TRational& rhv);
    friend bool operator>=(const TRational& lhv, const TRational& rhv);
    friend bool operator< (const TRational& lhv, const TRational& rhv);
    friend bool operator<=(const TRational& lhv, const TRational& rhv);
    friend TRational operator+ (const TRational& lhv, const TRational& rhv);
    friend TRational operator- (const TRational& lhv, const TRational& rhv);
    friend TRational operator* (const TRational& lhv, const TRational& rhv);
    friend TRational operator/ (const TRational& lhv, const TRational& rhv);

    friend std::ostream& operator<<(std::ostream& str, const TRational& num);

    ~TRational() = default;
};

#endif // TRATIONAL_H
