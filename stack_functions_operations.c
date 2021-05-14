#include "monty.h"

/**
 * nuevo_Nodo - Create new node.
 * @n: Is a value.
 * Return: New node.
 */
stack_t *nuevo_Nodo(int n)
{
	stack_t *node = NULL;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->n = n;
	node->next = NULL;
	node->prev = NULL;

	return (node);
}

/**
 * push - This function pushes an element to the stack.
 *
 * @stack: Double pointer to the head of the Stack.
 * @line_number: Number of the line.
 * Return: Nothing.
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *valor = strtok(NULL, DELIMITERS);
	stack_t *nuevo = NULL;
	int i = 0;
	(void)line_number;

	if (!valor)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (valor[i] != '\0')
	{
		if (!isdigit(valor[i]) && valor[i] != '-')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		i++;
	}

	nuevo = nuevo_Nodo(atoi(valor));

	nuevo->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = nuevo;
	*stack = nuevo;
}

/**
 * nop - doesnt do anything.
 * @stack: Double pointer to the head of the Stack.
 * @line_number: Number of the line.
 * Return: Nothing.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * pop - Removes the top element of the stack.
 * @stack: Double pointer to the head of the Stack.
 * @line_number: Number of the line.
 * Return: Nothing.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node = NULL;

	if (*stack == NULL || stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	node = *stack;
	*stack = node->next;
	if (node->next != NULL)
		node->next->prev = node->prev;
	free(node);
}

/**
 * swap - This function swaps the top two elements of the stack.
 * @stack: Double pointer to the head of the Stack.
 * @line_number: Number of the line.
 * Return: Nothing.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int tmp = 0;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}
