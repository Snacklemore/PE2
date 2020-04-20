#include <iostream>
#include "pqeue.h"
int random (int min, int max){
    static bool first = true;
    if (first){
        srand(time(NULL));
        first = false;
    }
    return min+rand() % (max-min);
}
std::string randStr(size_t length){

    char str[length];
    str[length-1]='\0';
    size_t i =0;
    int r;
    for (i=0;i<length-1;i++){
        for(;;){
            r = rand()%57 + 65;
            if((r>=65 && r <= 90 ) ||(r >= 97 && r <= 122)){
                str[i] = (char)r;
                break;
            }
        }
    }
    return std::string(str);
}
int main() {
    srand(time(NULL));
    priorityqueue pq;
    std::string str1;
    float wert;
    try{
    pq.extractMinSortedDesc();
    }catch(QueueException e){
        std::cout << e.OutStr() << std::endl;

    }
    for (int i= 0 ;i<10;i++){
        pq.insert(randStr(6),random(1,30));
    }
    pq.toScreen();
    std::cout <<"Deleting "<< pq.pqElement[0].strVal << std::endl;
    pq.remove(pq.pqElement[0].strVal);
    pq.toScreen();
    std::cout <<"Extrating Min"<< std::endl;
    std::cout << pq.extractMinSortedDesc()<< std::endl;
    pq.toScreen();
    std::cout <<"Decreasing Key of  "<< pq.pqElement[6].strVal << "  to 15" << std::endl;
    pq.decreaseKey(pq.pqElement[6].strVal,15);
    pq.toScreen();
    std::cout <<"Decreasing Key of  "<< "tFie" << "  to 15(which is not there on purpose)" << std::endl;
    try{pq.decreaseKey("tFie",15);
        }
    catch(QueueException e)
    {std::cout << e.OutStr() << std::endl;}
    pq.toScreen();






    return 0;
}