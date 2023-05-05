#include <limits>
#include <numeric>
#include <cmath>

#include "rational.h"

void TRational::normalize() {
    auto gcd = std::gcd(numerator_, denuminator_);
    numerator_      /= gcd;
    denuminator_    /= gcd;
};

TRational::TRational() : numerator_(0), denuminator_(1) { }

TRational::TRational(int numerator) : numerator_(numerator), denuminator_(1) { }

TRational::TRational(int numerator, int denuminator) : numerator_(numerator), denuminator_(denuminator) { };

TRational::TRational(const TRational& other) = default;

bool operator==(const TRational& lhv, const TRational& rhv) {
    return lhv.numerator_ == rhv.numerator_ && lhv.denuminator_ == rhv.denuminator_;
}

bool operator!=(const TRational& lhv, const TRational& rhv) {
    return !(lhv == rhv);
}

bool operator> (const TRational& lhv, const TRational& rhv) {
    return lhv.numerator_ * rhv.denuminator_  > rhv.numerator_ * lhv.denuminator_;
}

bool operator>=(const TRational& lhv, const TRational& rhv) {
    return lhv.numerator_ * rhv.denuminator_  >= rhv.numerator_ * lhv.denuminator_;
}

bool operator< (const TRational& lhv, const TRational& rhv) {
    return !(lhv >= rhv);
}

bool operator<=(const TRational& lhv, const TRational& rhv) {
    return !(lhv > rhv);
}

TRational operator+ (const TRational& lhv, const TRational& rhv) {
    auto ret = TRational(lhv.numerator_ * rhv.denuminator_ + rhv.numerator_ * lhv.denuminator_,
                     lhv.denuminator_ * rhv.denuminator_);
    ret.normalize();
    return ret;
}

TRational operator- (const TRational& lhv, const TRational& rhv) {
    auto ret = TRational(lhv.numerator_ * rhv.denuminator_ - rhv.numerator_ * lhv.denuminator_,
                     lhv.denuminator_ * rhv.denuminator_);
    ret.normalize();
    return ret;
}

TRational operator* (const TRational& lhv, const TRational& rhv) {
    auto ret = TRational(lhv.numerator_ * rhv.numerator_, lhv.denuminator_ * rhv.denuminator_);
    ret.normalize();
    return ret;
}

TRational operator/ (const TRational& lhv, const TRational& rhv) {
    auto ret = TRational(lhv.numerator_ * rhv.denuminator_, lhv.denuminator_ * rhv.numerator_);
    ret.normalize();
    return ret;
}

std::ostream& operator<<(std::ostream& str, const TRational& num) {
    str << '(' << num.numerator_ << '/' << num.denuminator_ << ')';
    return str;
}

std::istream& operator>>(std::istream& str, TRational& num) {
    str >> num.numerator_;
    str >> num.denuminator_;
    num.normalize();
    return str;
};
