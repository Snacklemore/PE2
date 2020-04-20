//
// Created by nico.
//

#include <algorithm>
#include "pqueue.h"

//heap struktur ( heißt nur pqueue)
pqentry::pqentry() {

}

void priorityqueue::toScreen() {
    if (last == 0)
        throw QueueException("Nothing to show");

    for (int i=0;i<last;i++)
        std::cout << i << "::" <<"Priority: " << pqElement[i].priority << "   Value:  " << pqElement[i].strVal << std::endl;

}

priorityqueue::priorityqueue() {
    size = 2;
    last = 0;
    pqElement = new pqentry[2];
}

priorityqueue::~priorityqueue() {
    delete[] pqElement;
}

void priorityqueue::increase() {
    size *= 2;
    pqentry* tmp = new pqentry[size];
    std::copy_n(pqElement,last,tmp);
    delete[] pqElement;
    pqElement = tmp;
}
void priorityqueue::pop_back() {
    last = last -1;
}

void priorityqueue::heapify() {
    for (int i =last-1;i>=0;--i)
        BubbleDown(i);
}
int priorityqueue::left(int i) {
    return (2*i+1);
}
int priorityqueue::right(int i) {
    return (2*i+2);
}
void priorityqueue::buildHeap() {
    heapify();
}
int priorityqueue::ParentIndex(int i) {
    return (i-1)/2;
}

void priorityqueue::BubbleDown(int i) {
    int length = last;
    if (right(i) >= length)
        return;//leaf
    int min_i = i;
    if (pqElement[i].priority > pqElement[left(i)].priority)
        min_i = left(i);
    if((right(i)<length)&& (pqElement[min_i].priority > pqElement[right(i)].priority))
        min_i = right(i);
    if (min_i != i ){
        pqentry temp = pqElement[i];
        pqElement[i] = pqElement[min_i];
        pqElement[min_i] = temp;
        BubbleDown(min_i);

    }
}
bool priorityqueue::isFull() {
    if(last >=  size)
        return 1;
    else return 0;
}
void priorityqueue::BubbleUp(int i) {
    if (i==0)
        return;
    if (pqElement[ParentIndex(i)].priority >pqElement[i].priority)
    {
        pqentry temp = pqElement[ParentIndex(i)];
        pqElement[ParentIndex(i)] = pqElement[i];
        pqElement[i] = temp;
        BubbleUp(ParentIndex(i));
    }
}
void priorityqueue::insert(std::string val, float p) {
    if (isFull())
        increase();
    pqElement[last].strVal = val;
    pqElement[last].priority = p;
    BubbleUp(last);
    last +=1;

}
pqentry priorityqueue::getMin() {
    return pqElement[0];
}
void priorityqueue::deleteMin() {
    if (last <= 1)
    {
        pop_back();
        return;
    }

    pqElement[0] = pqElement[last-1];
    pop_back();
    BubbleDown(0);

}
void priorityqueue::decrease() {
    size /= 2;
    pqentry* tmp = new pqentry[size];
    std::copy_n(pqElement,last-1,tmp);
    delete[] pqElement;
    pqElement = tmp;

}
void priorityqueue::decreaseKey(std::string str1, float p) {
    int pos;
    for ( int i= 0;i<last; i++){
        if(str1 == pqElement[i].strVal)
            pos=i;
    }
    std::string temp = pqElement[pos].strVal;
    remove(temp);
    insert(temp,p);

}
void priorityqueue::remove(std::string str2) {
    int pos;
    for (int i =0;i<last;i++){
        if(str2 == pqElement[i].strVal)
            pos=i;
    }
    for (int i=pos;i<last;i++){
        pqElement[i] = pqElement[i+1];
    }
    if(last <size/2)
        decrease();
    last-=1;
    heapify();

}
std::string priorityqueue::extractMin() {
    if (last == 0)
        throw QueueException("Nothing to extract");
    std::string temp;
    temp = getMin().strVal;
    deleteMin();
    return temp;

}

std::string priorityqueue::minimum() {
    if (last == 0)
        throw QueueException("Nothing to extract");
    std::string temp;
    temp = getMin().strVal;
    return temp;
}

std::string QueueException::OutStr() {
    return _error;
}
QueueException::QueueException(std::string Str) {
    _error = Str;

}
