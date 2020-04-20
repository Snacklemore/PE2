//
// Created by Nico
//

typedef struct stack stack_t;

stack_t * createStack();
static char isEmpty(stack_t *s);
static char isFull(stack_t *s);
float top(stack_t *s);
void pop(stack_t *s);
void push(stack_t *s, float val);
static void decrease(stack_t *s);
static void increase(stack_t *s);
void toScreen(stack_t *s);
float computeAdditive(stack_t *stack);
float computeSubstractive(stack_t *stack);
float computeMultiplicative(stack_t *stack);
float computeDivision(stack_t *stack);