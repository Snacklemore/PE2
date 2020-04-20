//
// Created by root on 20.04.20.
//

#ifndef RATIONAL_RATIONAL_H
#define RATIONAL_RATIONAL_H


#include <string>
#include "NumberFormatEN.h"
#include "NumberFormatDE.h"
class NumberFormatEN;
class NumberFormatDE;

class Rational {

public:
    Rational(int counter = 1,int denomi = 1){
        _counter = counter;
        _denomi = denomi;

    }
    Rational add(Rational num);
    Rational sub(Rational sub);
    double doubleValue();
    std::string toString(std::string LANG);
    Rational parse(std::string val);


private:
    NumberFormatEN *nfEN;
    NumberFormatDE *nfDE;
    void setFormat(std::string LANG);
    void kurzen();
    int _counter;
    int _denomi;
public:
    int getCounter() const;

    void setCounter(int counter);

    int getDenomi() const;

    void setDenomi(int denomi);


};


#endif //RATIONAL_RATIONAL_H
