#ifndef _STACK_H

#include "stdlib.h"

#define _STACK_H

#define MAX_SIZE 64

typedef struct stack Stack;

int stack_push(Stack* s, int data);

int stack_pop(Stack* s);

size_t stack_len(Stack s);

void stack_init(Stack* s);

int stack_top(Stack s);

#endif
