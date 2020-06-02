//
// Created by root on 20.04.20.
//

#include <cstring>
#include "Rational.h"



Rational Rational::add(Rational num) {
    Rational r;
    std::string numForm = num.nf->getForm();
    r.setFormat(numForm);
    r._counter = _counter * num._denomi + _denomi * num._counter;
    r._denomi = _denomi * num._denomi;
    r.kurzen();
    return r;

}

Rational Rational::sub(Rational sub) {

    Rational r = *this;
    //negate counter
    r.setCounter(r.getCounter() * (-1));


    std::string subForm = sub.nf->getForm();
    r.setFormat(subForm);
    return r.add(sub);

}

double Rational::doubleValue() {
    return (double)_counter /(double) _denomi;

}

std::string Rational::toString() {

    std::string rtn = nf->format(*this);
    return rtn;



}

 /*
    if (LANG == "EN")
    {
        setFormat("EN");
        std::string hlp = nfEN->format(*this);
        delete nfEN;
        return hlp;
    }

    else if (LANG == "DE")
    {
        setFormat("DE");
        std::string hlp = nfDE->format(*this);
        delete nfDE;
        return hlp;
    }*/










void Rational::kurzen() {
    int r;
    int p = _counter;
    int q = _denomi;
    do {
        r = p % q;
        p = q;
        q = r;
    }while (r !=0);
    _counter /= p;
    _denomi /= p;

}

int Rational::getCounter() const {
    return _counter;
}

void Rational::setCounter(int counter) {
    _counter = counter;
}

int Rational::getDenomi() const {
    return _denomi;
}

void Rational::setDenomi(int denomi) {
    _denomi = denomi;
}

void Rational::setFormat(std::string LANG) {
    if (LANG == "EN")
        nf = new NumberFormatEN();
    else if (LANG == "DE")
        nf = new NumberFormatDE();

}

Rational Rational::parse(std::string val) {

    this->_counter = nf->parse(val)._counter;
    this->_denomi = nf->parse(val)._denomi;
    return *this;

}

std::string Rational::getFormat() {
    return nf->getForm();
}
