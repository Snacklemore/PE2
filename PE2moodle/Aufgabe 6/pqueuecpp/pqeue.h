//
// Created by nico on 27.04.17.
//
#ifndef OOAP2_PQEUE_H
#include <iostream>

#define OOAP2_PQEUE_H


class pqentry{
    friend class priorityqueue;
public:
    pqentry();
    std::string strVal;
    float priority;

private:




};
class priorityqueue{
    friend class pqentry;
public:
    pqentry *pqElement;
    void toScreen();
    void decreaseKey(std::string str1,float p);
    std::string extractMinSortedDesc();
    void remove(std::string str2);
    priorityqueue();
    ~priorityqueue();
    bool isFull();
    void insert(std::string val,float p);
private:
    void increase();
    void makespace (int pos);
    int findpos(float p);
    int size = 2;
    int last = 0;


};
class QueueException {
private:
    std::string _error;
public:
    std::string OutStr();
    QueueException(std::string Str);
};
#endif //OOAP2_PQEUE_H