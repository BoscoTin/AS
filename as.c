#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX_SIZE 64

#define OPCODE_EXIT 1
#define OPCODE_PUSH 2
#define OPCODE_POP 3
#define OPCODE_TOP 4
#define OPCODE_LEN 5
#define OPCODE_ADD 6
#define OPCODE_SUB 7
#define OPCODE_MUL 8
#define OPCODE_DIV 9
#define OPCODE_MOD 10

#define CMD_EXIT "EXIT"
#define CMD_PUSH "PUSH"
#define CMD_POP "POP"
#define CMD_TOP "TOP"
#define CMD_LEN "LEN"
#define CMD_ADD "ADD"
#define CMD_SUB "SUB"
#define CMD_MUL "MUL"
#define CMD_DIV "DIV"
#define CMD_MOD "MOD"

struct stack
{
	size_t top;
	int data[MAX_SIZE];
};
typedef struct stack Stack;

int stack_push(Stack* s, int data);

int stack_pop(Stack* s);

size_t stack_len(Stack* s);

void stack_init(Stack* s);

int stack_top(Stack* s);

size_t match_op(const char* str);

void exec_op_code(Stack* s, int op, int n);




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
		return -1;
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


size_t match_op(const char* str)
{
	size_t op = -1;
	char* command[] = {
		CMD_EXIT,
		CMD_PUSH,
		CMD_POP,
		CMD_TOP,
		CMD_LEN,
		CMD_ADD,
		CMD_SUB,
		CMD_MUL,
		CMD_DIV,
		CMD_MOD
	};
	int i = 0;
	for (; i < 10; i++)
		if (!strcmp(str, command[i]))
		{
			op = i;
			break;
		}
	return op + 1;
}

void exec_op_code(Stack* s, int op, int n)
{
	int output = 0;
	int a, b;
	switch (op)
	{
		case OPCODE_LEN:
			output = stack_len(s);
			break;
		case OPCODE_TOP:
			output = stack_top(s);
			break;
		case OPCODE_POP:
			output = stack_pop(s);
			break;
		case OPCODE_PUSH:
			output = stack_push(s, n);
			break;
		case OPCODE_ADD:
			a = stack_pop(s);
			b = stack_pop(s);
			output = a + b;
			stack_push(s, output);
			break;
		case OPCODE_SUB:
			a = stack_pop(s);
			b = stack_pop(s);
			output = a - b;
			stack_push(s, output);
			break;
		case OPCODE_MUL:
			a = stack_pop(s);
			b = stack_pop(s);
			output = a * b;
			stack_push(s, output);
			break;
		case OPCODE_DIV:
			a = stack_pop(s);
			b = stack_pop(s);
			output = a / b;
			stack_push(s, output);
			break;
		case OPCODE_MOD:
			a = stack_pop(s);
			b = stack_pop(s);
			output = a % b;
			stack_push(s, output);
			break;
		case OPCODE_EXIT:
			exit(1);
			break;
		default:
			puts("Unknown Command");
	}
	printf("%d\n", output);
}


int main(void)
{
	Stack stack;
	Stack* s = &stack;
	stack_empty(s);
	int n;
	size_t op;
	char command[4];
	printf("> ");
	while (scanf("%s %d", command, &n) != EOF)
	{
		op = match_op(command);
		exec_op_code(s, op, n);
		printf("> ");
	}
	return 0;
}