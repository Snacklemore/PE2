//
// Created by Nico
//
#include "pqueue.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

//heapstruktur ( heißt einfach nur pqueue)
struct pqueue{
    pqentry_t **pqElement;
    int size;
    int last;
    int size_t;
};
struct pqentry{
    char *strVal;
    float priority;
};

priorityqueue_t * pqueue_create(){
    priorityqueue_t *pq;

    pq=(priorityqueue_t*)malloc (sizeof(priorityqueue_t));

    pq->pqElement=(pqentry_t**)malloc (2*sizeof(pqentry_t*));
    if (pq == NULL)
        printf("No memory");





    pq->size = 2;
    pq->last = 0;
    pq->size_t = 0;



    return  pq;
}
void swap(priorityqueue_t *pq, int element1, int element2){
    pqentry_t *helper;


    helper = pq->pqElement[element1];
    //pq->pqElement[hlpLast] = pq->pqElement[0];
    //pq->pqElement[0] = helper;
    pq->pqElement[element1] = pq->pqElement[element2];
    pq->pqElement[element2] = helper;


}
static void decrease (priorityqueue_t *pq){



    for (int i=pq->size;i>pq->size;i--){
        free(pq->pqElement[i]);
        free(pq->pqElement[i]->strVal);

    }
    pq->size/=2;
    pq->pqElement=(pqentry_t**)realloc (pq->pqElement,(pq->size)*sizeof(pqentry_t*));


}

static int isFull(priorityqueue_t *pq){
    if (pq->last-1 >= pq->size)
    return 1;
    else return 0;

}

void pqueue_remove(priorityqueue_t *pq, char*value){
    int pos;
    for(int i=0;i<pq->last;i++){
        if (strcmp(value,pq->pqElement[i]->strVal)==0){
            pos=i;

        }
    }
    for (int i=pos;i<pq->last;i++){
        pq->pqElement[i] = pq->pqElement[i+1];

    }
    if(pq->last < pq->size / 2)
        decrease(pq);

    pq->last-=1;
    heapify(pq);
}
void pop_back(priorityqueue_t *pq) {
    pq->last = pq->last - 1;
}

void deleteMin(priorityqueue_t *pq){
    if (pq->last <= 1)
        return;
    pq->pqElement[0] = pq->pqElement[pq->last-1];
    pop_back(pq);
    BubbleDown(pq,0);
   // heapify(pq);

}



char* pqueue_extractMinSortedAsc(priorityqueue_t *pq){


    char *temp;
    temp = pq->pqElement[0]->strVal;
    pqueue_remove(pq,pq->pqElement[0]->strVal);

    pq->size*=2;
    pq->pqElement=(pqentry_t**)realloc (pq->pqElement,(pq->size)*sizeof(pqentry_t*));
    for (int i=pq->last;i<pq->size;i++){
        pq->pqElement[i]= (pqentry_t *) malloc (sizeof (pqentry_t));
    }

    return temp;

    // }
}
char* pqueue_extractMin(priorityqueue_t *pq){


    char *temp;
    temp = getMin(pq)->strVal;
    deleteMin(pq);
    //heapify(pq);

    return temp;


}
pqentry_t* getMin(priorityqueue_t *pq){
    return pq->pqElement[0];

}




void makespace(priorityqueue_t *pq, int pos){
    for (int i = pq->last;i >pos;i--){
        pq->pqElement[i]=pq->pqElement[i-1];
    }


}

void pqueue_destroy(priorityqueue_t *pq){
    for (int i =0;i<pq->last;i++){
        free(pq->pqElement[i]->strVal);
        free(pq->pqElement[i]);
    }
    free(pq->pqElement);
    free(pq);
}
void heapify(priorityqueue_t *pq){
    for (int i = pq->last-1; i >=0;--i)
        BubbleDown(pq, i);


}
int left(int i){
    return   (2*i+1);
}
int size(priorityqueue_t *pq){
    return pq->size_t;

}
int right(int i ){
    return (2*i+2);
}
void buildHeap(priorityqueue_t *pq){
    heapify(pq);
}
void BubbleDown(priorityqueue_t *pq, int i){
    int length = pq->last ;
    if(right(i) >= length)
        return;//leaf
    int min_i = i;
    if (pq->pqElement[i]->priority > pq->pqElement[left(i)]->priority)
        min_i = left(i);
    if((right(i) < length) && (pq->pqElement[min_i]->priority > pq->pqElement[right(i)]->priority))
        min_i = right(i);
    if(min_i != i)
    {
        //swap()
        pqentry_t *temp = pq->pqElement[i];
        pq->pqElement[i] = pq->pqElement[min_i];
        pq->pqElement[min_i] = temp;
        BubbleDown(pq,min_i);

    }

}
int ParentIndex(int i){
    return  (i - 1 ) /2;
}
void BubbleUp(priorityqueue_t *pq, int i){
    if (i ==0)
        return;
    if (pq->pqElement[ParentIndex(i)]->priority > pq->pqElement[i]->priority)
    {
        //swap()
        pqentry_t *temp = pq->pqElement[ParentIndex(i)];
        pq->pqElement[ParentIndex(i)] = pq->pqElement[i];
        pq->pqElement[i] = temp;
        BubbleUp(pq,ParentIndex(i));
    }
}
void pqueue_insert(priorityqueue_t *pq, char* value, float p){


    if (isFull(pq)==  1){
        increase(pq);

    }



    pq->pqElement[pq->last]= (pqentry_t*)malloc (sizeof(pqentry_t));
    if (pq == NULL)
        printf("no Memory");
    pq->pqElement[pq->last]->strVal=(char*) malloc (strlen(value)*sizeof(char));
    if (pq == NULL)
        printf("nomemory");

    strcpy(pq->pqElement[pq->last]->strVal,value);
    pq->pqElement[pq->last]->priority = p;
    BubbleUp(pq,pq->last);



   // int hlpLast = pq->last;
   /* while (pq->pqElement[hlpLast]->priority < pq->pqElement[hlpLast/2]->priority)
    {
     swap(pq,hlpLast);
     hlpLast = hlpLast/2;
    }*/

    pq->last+=1;


}

static void increase(priorityqueue_t* pq){
    pq->size*=2;
    pq->pqElement=(pqentry_t**)realloc (pq->pqElement,(pq->size)*sizeof(pqentry_t*));
    for (int i=pq->last;i<pq->size;i++){
        pq->pqElement[i]= (pqentry_t *) malloc (sizeof (pqentry_t));
    }


}
//deprecated
int findpos(priorityqueue_t *pq,float p){


        for (int i = 0; i < pq->last; i++) {
            if (pq->pqElement[i]->priority <= p) {

                return i;
            }

        }

    return pq->last;


}

void pqueue_decreaseKey(priorityqueue_t *pq, char* value, float p){
    int pos;
    for(int i=0;i<pq->last;i++){
        if (strcmp(value,pq->pqElement[i]->strVal)==0){
            pos=i;

        }
    }
    char* temp = pq->pqElement[pos]->strVal;
    pqueue_remove(pq,temp);
    pqueue_insert(pq,temp,p);



}

void toScreen(priorityqueue_t* pq){
    if(pq->last==0){

        printf("Heap leeeer");
        return;
    }
    else{

        for (int i=0;i<pq->last;i++){
            printf("%s,%f,    :%d\n",pq->pqElement[i]->strVal,pq->pqElement[i]->priority,i);
        }
    }
}
