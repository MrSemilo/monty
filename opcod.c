#include "monty.h"

void _opcode(char *line, stack_t **stack, unsigned int lines_num)
{
	unsigned int count = 0;

	instruction_t specifiers[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	while (count < 2)
	{
		if (strcmp(specifiers[count].opcode, line) == 0)
		{
			specifiers[count].f(stack, lines_num);
			exit(EXIT_SUCCESS);
		}
		count++;
	}

	if (!specifiers[count].opcode)
	{
		fprintf(stderr, "l%u: unknown instruction %s\n", lines_num, line);
		exit(EXIT_SUCCESS);
	}
}
