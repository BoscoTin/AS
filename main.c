#include "stdio.h"
#include "stdlib.h"
#include "stack.h"
#include "op.h"

int main(void)
{
	Stack stack;
	Stack* s = &stack;
	stack_init(s);
	int n, op;
	char command[4];
	printf("> ");
	while (scanf("%s %d", command, &n) != EOF)
	{
		op = match_op(command);
		exec_op_code(s, op, n);
	}
	return 0;
}
