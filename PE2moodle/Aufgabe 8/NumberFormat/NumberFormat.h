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
    virtual std::string toString() = 0;
    std::string getForm()
    {
        return form;
    }


protected:
    virtual int* splitDouble(double d);
    std::string form;
};


#endif //RATIONAL_NUMBERFORMAT_H
