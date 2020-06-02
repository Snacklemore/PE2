#include <iostream>
#include "Rational.h"

int main() {

    Rational q(2,5);
    Rational p(2,7);
    Rational r= p.add(q);
    std::cout << r.toString() << std::endl;


    r.parse("3/5");
    std::cout << r.toString() << std::endl;

    std::cout << p.toString() << std::endl;
    std::cout << q.toString() << std::endl;
    std::cout << p.doubleValue() << std::endl;



}