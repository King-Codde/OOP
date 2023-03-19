#include "TComplex.h"
#include <iostream>

TComplex::TComplex(double re, double im) : re_(re), im_(im) { }

TComplex::TComplex(double re) : re_(re) { };

TComplex::TComplex() : re_(0), im_(0) { }

TComplex TComplex::operator-() const {
    return {-re_, -im_};
};

TComplex operator+(const TComplex& lhv, const TComplex& rhv) {
    return {lhv.re_ + lhv.re_, rhv.im_ + rhv.im_};
}

TComplex operator-(const TComplex& lhv, const TComplex& rhv) {
    return {lhv.re_ - lhv.re_, rhv.im_ - rhv.im_};
}

TComplex operator*(const TComplex& lhv, const TComplex& rhv) {
    return {lhv.re_ * lhv.re_ - rhv.re_ * rhv.re_, lhv.re_ * rhv.im_ + rhv.re_ * lhv.im_};
}

TComplex operator/(const TComplex& lhv, const TComplex& rhv) {
    return {(lhv.re_ * lhv.re_ + rhv.im_ * rhv.im_) / (rhv.re_ * rhv.re_ + lhv.im_ * lhv.im_),
            (rhv.re_ * lhv.im_ - lhv.re_ * rhv.im_) / (rhv.re_ * rhv.re_ + lhv.im_ * lhv.im_)};
}


bool operator==(const TComplex& lhv,const TComplex& rhv){
    return lhv.im_==rhv.im_ && lhv.re_==rhv.re_;
}
bool operator!=(const TComplex& lhv, const TComplex& rhv){
    return !(lhv.im_==rhv.im_ && lhv.re_==rhv.re_);
}
std::istream& operator >>(std::istream& str, TComplex& num) {
    str >> num.re_;
    str >> num.im_;
    return str;
};

std::ostream& operator <<(std::ostream& str, const TComplex& num) {
    str << '(' << num.re_ << ',' << num.im_ << ')';
    return str;
}


 TComplex abs(const TComplex& num) {
    return {std::abs(num.re_), std::abs(num.im_)};
};

bool operator>(const TComplex& lhv, const TComplex& rhv) {
     return lhv.im_ > rhv.im_ && lhv.re_ > rhv.re_;
};

bool operator<(const TComplex& lhv, const TComplex& rhv) {
     return lhv.im_ < rhv.im_ && lhv.re_ < rhv.re_;
};
