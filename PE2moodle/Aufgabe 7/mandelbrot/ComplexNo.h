//
// Created by root on 18.04.20.
//

#ifndef MANDELBROTSET_COMPLEXNO_H
#define MANDELBROTSET_COMPLEXNO_H

#include <iostream>
#include <math.h>
class ComplexNo {
public:
    ComplexNo(double real,double imag)
    {
        _real = real;
        _imag = imag;
    }

    friend std::ostream& operator<<(std::ostream& os, ComplexNo& nr);
    friend ComplexNo operator+ (ComplexNo &first,ComplexNo &second);
    friend ComplexNo operator- (ComplexNo &first,ComplexNo &second);
    friend ComplexNo operator* (ComplexNo &first,ComplexNo &second);

    double abs();
    double getReal() const;
    void setReal(double real);
    double getImag() const;
    void setImag(double imag);
private:
    double _real,_imag;


};




#endif //MANDELBROTSET_COMPLEXNO_H
