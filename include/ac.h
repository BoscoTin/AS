#ifndef _AC_H

#include "stdlib.h"

#define _AC_H

#define MAX_SIZE 64

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

size_t match_op(const char* str);

void exec_op_code(Stack* s, int op, int n);

#endif
