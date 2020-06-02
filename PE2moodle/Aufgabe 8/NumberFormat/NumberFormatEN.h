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
        form = "EN";
    }
    std::string format(Rational num);
    Rational parse(std::string val);



};


#endif //RATIONAL_NUMBERFORMATEN_H
