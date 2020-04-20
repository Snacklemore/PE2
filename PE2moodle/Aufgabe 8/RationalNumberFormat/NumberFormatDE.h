//
// Created by root on 20.04.20.
//

#ifndef RATIONAL_NUMBERFORMATDE_H
#define RATIONAL_NUMBERFORMATDE_H


#include "NumberFormat.h"
#include "Rational.h"
#include <math.h>
//decimal separotor: ","
//other : "."
class NumberFormatDE: public NumberFormat {
public:
    NumberFormatDE()
    {

    }
    std::string format(Rational num);
    Rational parse(std::string val);

};


#endif //RATIONAL_NUMBERFORMATDE_H
