#include "monty.h"

void push(stack_t **stack, unsigned int line_num)
{
        char *value = strtok(NULL, DELIMITERS);
        stack_t *new_node;

        if (!stack)
        {
                fprintf(stderr, "L%d: Need to use line_num\n", line_num);
                exit(EXIT_FAILURE);
        }
        new_node = malloc(sizeof(stack_t));
        if (!new_node)
        {
                exit(EXIT_FAILURE);
        }
        new_node = new_Node(atoi(value));
        new_node->next = (*stack);
        new_node->prev = NULL;
        if (*stack)
                (*stack)->prev = new_node;
        *stack = new_node;
}

void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *h = *stack;
	(void)line_num;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

stack_t *new_Node(int n)
{
        stack_t *node = NULL;

        node = malloc(sizeof(stack_t));
        if (node == NULL)
        {
                fprintf(stderr, "Error: malloc failed\n");
                exit(EXIT_FAILURE);
        }
        node->n = n;
        node->next = NULL;
        node->prev = NULL;

        return (node);
}

