//
// Created by root on 20.04.20.
//

#ifndef RATIONAL_NUMBERFORMATEN_H
#define RATIONAL_NUMBERFORMATEN_H

#include "NumberFormat.h"
#include "Rational.h"




//decimal separotor: "."
//other : ","

class NumberFormatEN: public NumberFormat {
public:
    NumberFormatEN()
    {

    }
    std::string format(Rational num);
    Rational parse(std::string val);
private:


};


#endif //RATIONAL_NUMBERFORMATEN_H
