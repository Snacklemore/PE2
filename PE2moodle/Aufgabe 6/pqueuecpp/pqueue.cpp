//
// Created by nico on 27.04.17.
//

#include <algorithm>
#include "pqeue.h"

//normale priority queue ohne heap struktur
pqentry::pqentry(){

};

priorityqueue::priorityqueue(){
    try{
        pqElement = new pqentry[2];
    }catch (const std::bad_alloc&){
        return;
    }



};
priorityqueue::~priorityqueue(){
    delete[] pqElement;
}
void priorityqueue::increase() {
    size *=2;
    pqentry* tmp = new pqentry[size];

    std::copy_n(pqElement, last-1, tmp);
    delete[] pqElement;
    pqElement = tmp;
    //delete[] tmp;



}
void priorityqueue::decreaseKey(std::string str1, float p){
    int pos;
    for (int i = 0; i<last;i++){
        if (str1.compare(pqElement[i].strVal)==0){
            pos=i;
            break;
        }else pos = -1;
    }if (pos == -1)
        throw QueueException("KEY NOT FOUND");
    std::string temp = pqElement[pos].strVal;
    remove(temp);
    insert(temp,p);

}
std::string priorityqueue::extractMinSortedDesc(){
    if (last==0)
        throw QueueException("Nothing to extract");
    std::string temp;
    temp = pqElement[last-1].strVal;
    remove(pqElement[last-1].strVal);
    return temp;
}
void priorityqueue::remove(std::string str2) {
    int pos;
    for (int i = 0; i<last;i++){
        if (str2.compare(pqElement[i].strVal)==0){
            pos=i;
        }
    }
    for (int i = pos;i<last;i++){
        pqElement[i]=pqElement[i+1];
    }
    size--;
    pqentry* tmp = new pqentry[size];
    for (int i=0;i<size;i++){
        tmp[i]=pqElement[i];
    }
    delete[] pqElement;
    pqElement = tmp;
    last--;

}
void priorityqueue::toScreen(){
    for (int i =0;i<last;i++){
        std::cout << pqElement[i].priority << std::endl;
        std::cout << pqElement[i].strVal << std::endl;
    }
}
void priorityqueue::makespace(int pos) {
    for (int i = last;i>pos;i--){
        pqElement[i]=pqElement[i-1];
    }

}

int priorityqueue::findpos(float p) {
    for (int i = 0;i< last;i++){
        if(pqElement[i].priority <=p){
            return i;
        }
    }
    return last;

}
bool priorityqueue::isFull() {
    if (last >= size)
        return true;
    else
        return false;

}
void priorityqueue::insert(std::string val,float p){
    if (isFull())
        increase();
    int pos = findpos(p);
    makespace(pos);
    pqElement[pos].strVal = val;
    pqElement[pos].priority = p;
    last++;





}
std::string QueueException::OutStr(){
    return _error;
}
QueueException::QueueException(std::string Str) {
    _error = Str;
}
