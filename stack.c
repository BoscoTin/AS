#include "stack.h"

struct stack
{
	size_t top;
	int data[MAX_SIZE];
};

int stack_push(Stack* s, int data)
{
	if (MAX_SIZE == s->top)
		return -1;
	s->data[s->top] = data;
	s->top++;
	return s->top;
}

int stack_pop(Stack* s)
{
	if (0 == s->top)
		return NULL;
	s->top--;
	return s->data[s->top];
}

size_t stack_len(Stack* s)
{
	return s->top;
}

void stack_empty(Stack* s)
{
	s->top = 0;
}

int stack_top(Stack* s)
{
	return s->data[s->top - 1];
}
