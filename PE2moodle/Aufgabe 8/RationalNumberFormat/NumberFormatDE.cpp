//
// Created by root on 20.04.20.
//

#include "NumberFormatDE.h"

std::string NumberFormatDE::format(Rational num) {
    int *tupel = splitDouble(num.doubleValue());
    return std::to_string(num.getCounter()) +"/" + std::to_string(num.getDenomi())+ " Decimal: "+ std::to_string(tupel[0])+","+std::to_string(tupel[1]);
}

Rational NumberFormatDE::parse(std::string val) {
    char one = val[0];
    char two = val[1];
    if (std::string(&two) != "/")
        std::cout << "wrong notation" << std::endl;
    char three = val[2];

    int ione = std::stoi(std::string(&one));

    int ithree = std::stoi(std::string(&three));
    Rational* r = new Rational(ione,ithree);

    return *r;

}
