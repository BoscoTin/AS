#include "ac.h"
#include "string.h"
#include "stdio.h"

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
			output = (int)stack_len(s);
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