//
// Created by root on 20.04.20.
//


#include "NumberFormat.h"

int *NumberFormat::splitDouble(double d) {
    double whole = floor(d);
    double decimal = (d- whole) * 10000;
    int *tupel = (int*) malloc(2 * sizeof(int));
    tupel[0] = whole;
    tupel[1] = decimal;
    return tupel;
}