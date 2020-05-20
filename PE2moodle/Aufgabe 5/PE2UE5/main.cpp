#include <iostream>
#include <cstdlib>
#include "heap.h"
int random (int min, int max){
    static bool first = true;
    if (first){
        srand(time(NULL));
        first = false;
    }
    return min+rand() % (max-min);
}


heap<int>::heapEntry* buildEntries(int amount)
{
    heap<int>::heapEntry *entries = new heap<int>::heapEntry[amount];
    for ( int i= 0;i<amount;i++)
    {
        entries[i].priority = random(1,30);
        entries[i].strVal = random(1,30);
    }
    return entries;
}
int main() {

    srand(time(NULL));
    //heap<int> pq;
    heap<int> *pq = new heap<int>(buildEntries(20),20);



    pq->toScreen();

    for (int i= 0 ;i<10;i++){

        pq->insert(random(1,30),random(1,30));

    }

    std::cout <<"Deleting "<< pq->heapElement[0].strVal << std::endl;
    pq->remove(pq->heapElement[0].strVal);
    pq->toScreen();
    std::cout <<"Extrating Min"<< std::endl;
    std::cout << pq->extractMin()<< std::endl;
    pq->toScreen();
    std::cout <<"Decreasing Key of  "<< pq->heapElement[6].strVal << "  to 15" << std::endl;
    pq->decreaseKey(pq->heapElement[6].strVal,15);
    pq->toScreen();
    std::cout <<"Decreasing Key of  "<< "tFie" << "  to 15(which is not there on purpose)" << std::endl;
    try{pq->decreaseKey(40,15);
    }
    catch(QueueException e)
    {std::cout << e.OutStr() << std::endl;}
    pq->toScreen();
    std::cout<<pq->isFull()<<std::endl;







    return 0;
}