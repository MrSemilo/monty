#include "monty.h"
/**
 * opcode_stack - Function for select parameter.
 *
 * @opcode: Entry parameter.
 * @stack: Double pointer to the head of the Stack.
 * @line_number: Number of the line.
 *
 * Return: Nothing.
 */
int opcode_stack(char *opcode, stack_t **stack, unsigned int line_number)
{
	unsigned int code = 0;

	instruction_t operation[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"nop", nop},
		{"pop", pop},
		{"swap", swap},
		{"add", _add},
		{NULL, NULL}
	};

	while (code < 7)
	{
	if (strcmp(operation[code].opcode, opcode) == 0)
	{
		operation[code].f(stack, line_number);
		return (EXIT_SUCCESS);
	}
	code++;
	}
	if (!operation[code].opcode)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
