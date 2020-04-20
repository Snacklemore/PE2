//
// Created by Nico
//

//#ifndef STACK_STACK_H
//#define STACK_STACK_H

//#endif //STACK_STACK_H

class Stack {
private:
    float *_value;
    int    _last;
    int    _size;
    char   _error;


    bool isEmpty();
    void increase();
    void decrease();
public:
    float computeSubstractive();
    float computeMultiplicative();
    float computeAdditive();
    float computeDivision();
    Stack(int size);
    ~Stack();
    void push(float val);
    void pop();
    float top();
    char getError();
    void toScreen();
};


