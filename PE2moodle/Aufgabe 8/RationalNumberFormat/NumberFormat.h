//
// Created by root on 20.04.20.
//

#ifndef RATIONAL_NUMBERFORMAT_H
#define RATIONAL_NUMBERFORMAT_H


#include <string>
#include <iostream>

#include <math.h>

class Rational;
class NumberFormat {

public:
    virtual std::string format(Rational num) = 0;
    virtual Rational parse(std::string val) = 0;


protected:
    int* splitDouble(double d);
};


#endif //RATIONAL_NUMBERFORMAT_H
