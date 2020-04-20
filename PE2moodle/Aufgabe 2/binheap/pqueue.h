#include <malloc.h>
#include <stdbool.h>

//
// Created by Nico
//
typedef struct pqentry pqentry_t;
typedef struct pqueue priorityqueue_t;

priorityqueue_t * pqueue_create();
void pqueue_destroy(priorityqueue_t *pq);
void pqueue_insert(priorityqueue_t *pq, char* value, float p);
static void increase(priorityqueue_t* pq);
void toScreen(priorityqueue_t* pq);
static int isFull(priorityqueue_t* pq);
char* pqueue_extractMin(priorityqueue_t *pq);//deprecated
void pqueue_remove(priorityqueue_t *pq, char*value);
void pqueue_decreaseKey(priorityqueue_t *pq, char* value, float p);
int findpos(priorityqueue_t *pq,float p);//deprecated
void swap(priorityqueue_t *pq, int element1, int element2);
void heapify(priorityqueue_t *pq);
int left(int i); // left(i) gibt index des linken kindes
int right(int i);// right(i) gibt Index des rechten kindes
int ParentIndex(int i);
void BubbleDown(priorityqueue_t *pq, int i);
void BubbleUp(priorityqueue_t *pq, int i);
int size(priorityqueue_t *pq);
void buildHeap(priorityqueue_t *pq);
void pop_back(priorityqueue_t *pq);
void deleteMin(priorityqueue_t *pq);
pqentry_t* getMin(priorityqueue_t *pq);
static void decrease(priorityqueue_t *pq);
