#include <malloc.h>

//
// Created by Nico on 11.04.2017.
//
typedef struct pqentry pqentry_t;
typedef struct pqueue priorityqueue_t;

priorityqueue_t * pqueue_create();
void pqueue_destroy(priorityqueue_t *pq);
void pqueue_insert(priorityqueue_t *pq, char* value, float p);
static void increase(priorityqueue_t* pq);
void toScreen(priorityqueue_t* pq);
static int isFull(priorityqueue_t* pq);
char* pqueue_extractMinSortedDesc(priorityqueue_t *pq);
void pqueue_remove(priorityqueue_t *pq, char*value);
void pqueue_decreaseKey(priorityqueue_t *pq, char* value, float p);
int findpos(priorityqueue_t *pq,float p);