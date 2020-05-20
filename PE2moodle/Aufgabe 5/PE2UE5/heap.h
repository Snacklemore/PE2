//
// Created by nico on.
//

#ifndef OOA1MINHEAPCPP_PQUEUE_H
#define OOA1MINHEAPCPP_PQUEUE_H

#include <iostream>
#include <algorithm>

//two classes to wrap content of the heap, entries are sorted depending on their priority
//heap(heapEntry *entries, int size) takes an array of heap<T>::heapEntry and fills the heap with that data ( example in main.cpp)

template <typename T>
class heap{
public:
    class heapEntry{
        friend class heap;
    public:
        heapEntry();
        heapEntry(T val, float prio);
        T strVal;
        float priority;
    private:

    };
    heapEntry *heapElement;
    void toScreen();
    void decreaseKey(T str1,float p);
    T extractMin();
    T minimum();
    void remove(T str2);
    heap();
    heap(heapEntry *entries,int size);
    ~heap();
    void insert(T val, float p);
    bool isFull();






private:

    void heapify();
    int left(int i);
    int right(int i);
    int ParentIndex(int i);
    void BubbleDown(int i );
    void BubbleUp(int i);
    void buildHeap();
    void pop_back();
    void deleteMin();
    heapEntry getMin();
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


template <typename T>
heap<T>::heapEntry::heapEntry(T val,float prio) {
    strVal = val;
    priority = prio;
}



template <typename T>
heap<T>::heapEntry::heapEntry() {

}

template <typename T>
void heap<T>::toScreen() {
    if (last == 0)
        throw QueueException("Nothing to show");

    for (int i=0;i<last;i++)
        std::cout << i << "::" << "Priority: " << heapElement[i].priority << "   Value:  " << heapElement[i].strVal << std::endl;

}



template <typename T>
heap<T>::heap() {
    size = 2;
    last = 0;
    heapElement = new heapEntry[2];
}


template <typename T>
heap<T>::heap(heapEntry *entries,int _size)
{
    size = _size;
    last = size ;
    heapElement = entries;
    heapify();
}



template <typename T>
heap<T>::~heap() {
    delete[] heapElement;
}



template <typename T>
void heap<T>::increase() {
    size *= 2;
    heapEntry* tmp = new heapEntry[size];
    std::copy_n(heapElement, last, tmp);
    delete[] heapElement;
    heapElement = tmp;
}



template <typename T>
void heap<T>::pop_back() {
    last = last -1;
}


template <typename T>
void heap<T>::heapify() {
    for (int i =last-1;i>=0;--i)
        BubbleDown(i);
}


template <typename T>
int heap<T>::left(int i) {
    return (2*i+1);
}


template <typename T>
int heap<T>::right(int i) {
    return (2*i+2);
}


template <typename T>
void heap<T>::buildHeap() {
    heapify();
}
template <typename T>
int heap<T>::ParentIndex(int i) {
    return (i-1)/2;
}
template <typename T>
void heap<T>::BubbleDown(int i) {
    int length = last;
    if (right(i) >= length)
        return;//leaf
    int min_i = i;
    if (heapElement[i].priority > heapElement[left(i)].priority)
        min_i = left(i);
    if((right(i)<length)&& (heapElement[min_i].priority > heapElement[right(i)].priority))
        min_i = right(i);
    if (min_i != i ){
        heapEntry temp = heapElement[i];
        heapElement[i] = heapElement[min_i];
        heapElement[min_i] = temp;
        BubbleDown(min_i);

    }
}


template <typename T>
bool heap<T>::isFull() {
    if(last >=  size)
        return 1;
    else return 0;
}

template <typename T>
void heap<T>::BubbleUp(int i) {
    if (i==0)
        return;
    if (heapElement[ParentIndex(i)].priority > heapElement[i].priority)
    {
        heapEntry temp = heapElement[ParentIndex(i)];
        heapElement[ParentIndex(i)] = heapElement[i];
        heapElement[i] = temp;
        BubbleUp(ParentIndex(i));
    }
}

template <typename T>
void heap<T>::insert(T val, float p) {
    if (isFull())
        increase();
    heapElement[last].strVal = val;
    heapElement[last].priority = p;
    BubbleUp(last);
    last +=1;

}

template <typename T>
typename heap<T>::heapEntry heap<T>::getMin() {
    return heapElement[0];
}

template <typename T>
void heap<T>::deleteMin() {
    if (last <= 1)
    {
        pop_back();
        return;
    }

    heapElement[0] = heapElement[last - 1];
    pop_back();
    BubbleDown(0);

}


template <typename T>
void heap<T>::decrease() {
    size /= 2;
    heapEntry* tmp = new heapEntry[size];
    std::copy_n(heapElement, last - 1, tmp);
    delete[] heapElement;
    heapElement = tmp;

}

template <typename T>
void heap<T>::decreaseKey(T str1, float p) {
    int pos;
    for ( int i= 0;i<last; i++){
        if(str1 == heapElement[i].strVal)
        {
            pos=i;
            break;
        } else
            pos = -1;

    }
    if ( pos == -1)
        throw QueueException("KEY NOT FOUND!");
    T temp = heapElement[pos].strVal;
    remove(temp);
    insert(temp,p);

}

template <typename T>
void heap<T>::remove(T str2) {
    int pos;
    for (int i =0;i<last;i++){
        if(str2 == heapElement[i].strVal)
            pos=i;
    }
    for (int i=pos;i<last;i++){
        heapElement[i] = heapElement[i + 1];
    }
    if(last <size/2)
        decrease();
    last-=1;
    heapify();

}

template <typename T>
T heap<T>::extractMin() {
    if (last == 0)
        throw QueueException("Nothing to extract");
    T temp;
    temp = getMin().strVal;
    deleteMin();
    return temp;

}
template <typename T>
T heap<T>::minimum() {
    if (last == 0)
        throw QueueException("Nothing to extract");
    T temp;
    temp = getMin().strVal;
    return temp;
}

std::string QueueException::OutStr() {
    return _error;
}
QueueException::QueueException(std::string Str) {
    _error = Str;

}
#endif //OOA1MINHEAPCPP_PQUEUE_H
