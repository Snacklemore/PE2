//
// Created by Nico
//
#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack(int size) {
    _size= size;
    _last = 0;
    _error = 0;

    _value = new float [size];
}

Stack::~Stack() {
    delete[] _value;
}
float Stack::computeAdditive(){
    float t,r,l;
    l = this->top();
    Stack::pop();
    r = this->top();
    this->pop();
    t= l + r;
    return t;

}
void Stack::increase() {

    float *tmp = new float[_size];

    for (int i=0;i<_last;i++){
        tmp[i]= _value[i];
    if (i == i+1)
        throw 7783;
    }

    delete[] _value;
    _value = tmp;
    _size += 1;
}
void Stack::decrease(){
    _size -=1;
    float *tmp = new float [_size];

    for (int i=0;i<_last;i++){
        tmp[i]=_value[i];
    }
    delete[] _value;
    _value =tmp;
}
bool Stack::isEmpty() {
    return _size == 0;
}
char Stack::getError() {
    return _error;
}
void Stack::push(float val) {
    if (!val)
        throw "bad type;wrongtype";
    increase();

    _value[_last]= val;
    _last +=1;
}
float Stack::computeMultiplicative() {
    float t, r, l;
    l =this->top();
    this->pop();
    r = this->top();
    this->pop();
    t = l * r;
    return t;
}
float Stack::computeDivision(){
    float t,r,l;
    l = this->top();
    this->pop();
    r = this->top();
    this->pop();
    if (r==0)
        throw 78999;
    t= l / r;

    return t;

}

float Stack::computeSubstractive(){
    float t,r,l;
    r = this->top();
    this->pop();
    l = this->top();
    this->pop();
    t= l - r;
    return t;
};
float Stack::top() {
    if (isEmpty()){
        _error = 1;
        return -1;
    }

    return _value[_last -1];
}
void Stack::pop() {
    if (isEmpty()){
        _error=2;
        return ;
    }
    decrease();
    _last-=1;
}
void Stack::toScreen() {
    for (int i=0;i<_last;i++) {

        cout << i << ":" << _value[i] << endl;
    }
   // cout << _result <<endl;
}
