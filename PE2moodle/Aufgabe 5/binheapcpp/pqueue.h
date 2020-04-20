//
// Created by nico on.
//

#ifndef OOA1MINHEAPCPP_PQUEUE_H
#define OOA1MINHEAPCPP_PQUEUE_H

#include <iostream>


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
    std::string extractMin();
    std::string minimum();
    void remove(std::string str2);
    priorityqueue();
    ~priorityqueue();
    void insert(std::string val, float p);





private:
    bool isFull();
    void heapify();
    int left(int i);
    int right(int i);
    int ParentIndex(int i);
    void BubbleDown(int i );
    void BubbleUp(int i);
    void buildHeap();
    void pop_back();
    void deleteMin();
    pqentry getMin();
    void decrease();
    void increase();
    int size=1;
    int last=0;


};
class QueueException{
private:
    std::string _error;
public:
    std::string OutStr();
    QueueException(std::string Str);
};

#endif //OOA1MINHEAPCPP_PQUEUE_H
