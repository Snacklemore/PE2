//
// Created by root on 20.04.20.
//
#include <cmath>
#include <iostream>
#include "NumberFormatEN.h"



std::string NumberFormatEN::format(Rational num) {
    int *tupel = NumberFormat::splitDouble(num.doubleValue());
    int tupelh[3] = {0,0};
    tupelh[0] = tupel[0];
    tupelh[1] = tupel[1];
    free(tupel);
    return std::to_string(num.getCounter()) +"/" + std::to_string(num.getDenomi())+ " Decimal: "+ std::to_string(tupelh[0])+"."+std::to_string(tupelh[1]);

}

 Rational NumberFormatEN::parse(std::string val) {
     char one = val[0];
     char two = val[1];
     if (std::string(&two) != "/")
     {
         std::cout << "wrong notation" << std::endl;
     }

     char three = val[2];
     int ione = std::stoi(std::string(&one));

     int ithree = std::stoi(std::string(&three));
     Rational* r = new Rational(ione,ithree);

     return *r;
}



