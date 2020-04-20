#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "myStack.h"

int main() {
    float right,left,t;
    char *input= (char*) malloc(512 * sizeof(char));
    const char *delim=" ";
    char *ptr = (char*) malloc(512 * sizeof(char));
    stack_t *stack = createStack();
    gets(input) ;
    ptr=strtok(input,delim);
    while (ptr != NULL){
        if (strcmp(ptr,"+")== 0){
            t= computeAdditive(stack);
            push(stack,t);
        }else if (strcmp(ptr,"-")== 0){
            t= computeSubstractive(stack);
            push(stack,t);
        }else if (strcmp(ptr,"*")==0){
            t=computeMultiplicative(stack);
            push(stack,t);
        }else if (strcmp(ptr,"/")==0){
            t=computeDivision(stack);
            push(stack,t);
        }
        else
        push(stack,strtof(ptr,NULL));
        ptr=strtok(NULL,delim);
    }




    toScreen(stack);
    return 0;
}