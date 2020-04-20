#include <iostream>
#include "Rational.h"

int main() {

    Rational q(2,5);
    Rational p(2,7);
    Rational r= p.add(q);
    std::cout << r.toString("DE") << std::endl;


    r.parse("3/5");
    std::cout << r.toString("DE") << std::endl;

    std::cout << p.toString("EN") << std::endl;
    std::cout << q.toString("DE") << std::endl;
    std::cout << p.doubleValue() << std::endl;



}