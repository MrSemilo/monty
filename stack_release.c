#include "monty.h"

/**
 * free_stack - Free a stack.
 * @stack: Head node.
 * Return: Nothing.
 */
void free_stack(stack_t *stack)
{
	stack_t *fly = stack;

	if (fly != NULL)
	{
		free_stack(fly->next);
		free(fly);
	}
}
