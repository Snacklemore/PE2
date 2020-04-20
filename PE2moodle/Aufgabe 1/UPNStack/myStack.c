//
// Created by Nico
//

#include <stdio.h>
#include <malloc.h>
#include "myStack.h"
struct stack {
    int size ;
    int next;
    float* values;
    char error;

};


stack_t * createStack(){
    stack_t *s;
    s= (stack_t*)malloc (sizeof(stack_t));
    s->size = 0;
    s->next = 0;
    s->error =0;
    s->values = (float*)malloc (1*sizeof(float));
    return s;
}
char isEmpty(stack_t *s){
    return s->next == 0;
}
float top(stack_t *s){
    if (isEmpty(s)){

    }
    return s->values[s->next-1];
}
static void decrease(stack_t *s){
    s->size -=1;
    s->next -=1;
    s->values = (float *) realloc(s->values , s->size * sizeof(float));



}
static void increase(stack_t *s){
    s->size +=1;
    s->values = (float*) realloc(s->values, s->size *sizeof(float));


}
void pop(stack_t *s){
    if (isEmpty(s)){
        s->error=1;
        return;
    }

    decrease(s);
}
void push(stack_t *s, float val){
    increase(s);
    s->values[s->next]= val;
    s->next +=1;






}
void toScreen(stack_t *s){
    for(int i =0;i<s->size;i++){
        printf("i:%3.2f\n",s->values[i]);
    }
}
static char isFull(stack_t *s){
    return s->size+1 == s->next;
}
float computeAdditive(stack_t *stack){
    float t,r,l;
    l = top(stack);
    pop(stack);
    r = top(stack);
    pop(stack);
    t= l + r;
    return t;

}
float computeSubstractive(stack_t *stack){
    float t,r,l;
    l = top(stack);
    pop(stack);
    r = top(stack);
    pop(stack);
    t= l - r;
    return t;
}
float computeMultiplicative(stack_t *stack){
    float t,r,l;
    l = top(stack);
    pop(stack);
    r = top(stack);
    pop(stack);
    t= l * r;
    return t;
}
float computeDivision(stack_t *stack){
    float t,r,l;
    l = top(stack);
    pop(stack);
    r = top(stack);
    pop(stack);
    t= l / r;
    return t;

}