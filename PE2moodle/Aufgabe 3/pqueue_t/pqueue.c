//
// Created by Nico on 11.04.2017.
//
#include "pqueue.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

// normale priority queue ohne heap struktur
struct pqueue{
    pqentry_t **pqElement;
    int size;
    int last;
};
struct pqentry{
    char *strVal;
    float priority;
};

priorityqueue_t * pqueue_create(){
    priorityqueue_t *pq;

    pq=(priorityqueue_t*)malloc (sizeof(priorityqueue_t));

    pq->pqElement=(pqentry_t**)malloc (8*sizeof(pqentry_t*));





    pq->size = 8;
    pq->last = 0;



    return  pq;
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
}



static void increase(priorityqueue_t* pq){

    pq->size*=2;
    pq->pqElement=(pqentry_t**)realloc (pq->pqElement,(pq->size)*sizeof(pqentry_t*));
    for (int i=pq->last;i<pq->size;i++){
        pq->pqElement[i]= (pqentry_t *) malloc (sizeof (pqentry_t));
    }


}
char* pqueue_extractMinSortedAsc(priorityqueue_t *pq){


    char *temp;
    temp = pq->pqElement[0]->strVal;
    pqueue_remove(pq,pq->pqElement[0]->strVal);


    return temp;

    // }
}
char* pqueue_extractMinSortedDesc(priorityqueue_t *pq){


    char *temp;
    temp = pq->pqElement[pq->last-1]->strVal;
    pqueue_remove(pq,pq->pqElement[pq->last-1]->strVal);


    return temp;


}




void makespace(priorityqueue_t *pq, int pos){
    for (int i = pq->last;i >pos;i--){
        pq->pqElement[i]=pq->pqElement[i-1];
    }
    pq->last+=1;

}

void pqueue_destroy(priorityqueue_t *pq){
    for (int i =0;i<pq->last;i++){
        free(pq->pqElement[i]->strVal);
        free(pq->pqElement[i]);
    }
    free(pq->pqElement);
    free(pq);
}
void pqueue_insert(priorityqueue_t *pq, char* value, float p){


    if (isFull(pq)==  1){
        increase(pq);

    }
    int pos = findpos(pq,p);
    makespace(pq,pos);

    pq->pqElement[pos]= (pqentry_t*)malloc (sizeof(pqentry_t));
    pq->pqElement[pos]->strVal=(char*) malloc (strlen(value)*sizeof(char));
    strcpy(pq->pqElement[pos]->strVal,value);
    pq->pqElement[pos]->priority = p;




}
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
