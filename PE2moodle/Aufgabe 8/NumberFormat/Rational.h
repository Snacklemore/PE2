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
    Rational(int counter = 1,int denomi = 1,std::string loka= "DE"){
        _counter = counter;
        _denomi = denomi;
        setFormat(loka);

    }
    Rational add(Rational num);
    Rational sub(Rational sub);
    double doubleValue();
    std::string toString();
    Rational parse(std::string val);
    std::string getFormat();


private:
    NumberFormat* nf;
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
