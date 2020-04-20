//
// Created by root on 18.04.20.
//


#include "ComplexNo.h"

std::ostream& operator<<(std::ostream& os, ComplexNo& nr)
{
    os << nr._real << "+i" << nr._imag;
    return os;
}
ComplexNo operator+ (ComplexNo &first,ComplexNo &second){
    ComplexNo result(0,0);
    result._real = first._real + second._real;
    result._imag = first._imag+ second._imag;
    return result;
}

ComplexNo operator- (ComplexNo &first,ComplexNo &second)
{
    ComplexNo result(0,0);
    result._real = first._real - second._real;
    result._imag = first._imag - second._imag;
    return result;
}

ComplexNo operator* (ComplexNo &first,ComplexNo &second)
{
    //c1 * c2 = (c1.r + c1.i) * (c2.r + c2.i) =
    //   ((cr1.r*cr2.r) - (cr1.i*cr2.i)) + ((cr1.r*cr2.i) + (cr1.i*cr2.r));
    ComplexNo result(0,0);
    result._real = ((first._real*second._real)- (first._imag*second._imag));
    result._imag = ((first._real*second._imag)+ (first._imag*second._real));
    return result;
}

double ComplexNo::getReal() const {
    return _real;
}

void ComplexNo::setReal(double real) {
    _real = real;
}

double ComplexNo::getImag() const {
    return _imag;
}

void ComplexNo::setImag(double imag) {
    _imag = imag;
}

double ComplexNo::abs() {
    double a = _real;
    double b = _imag;
    double res =  pow(a,2.0) + pow(b,2.0);
    res =  sqrt(res);
    return res;
}
