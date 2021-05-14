#include "monty.h"

/**
 * main - main function of monty program
 * @argc: number of arguments
 * @argv: pointer to array of strings of arguments
 * Return: 0 on success, -1 on failure
 */
int main(int argc, char *argv[])
{
  FILE *op = NULL;
  stack_t *stack = NULL;
  char *command = NULL, *space = NULL;
  size_t lineWeight = 0;
  unsigned int number_line = 0;

  if (argc != 2)
    {
      fprintf(stderr, "USAGE: monty file\n");
      return (EXIT_FAILURE);
    }
  op = fopen(argv[1], "r");
  if (op == NULL)
    {
      fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
      exit(EXIT_FAILURE);
    }
  while (getline(&space, &lineWeight, op) != EOF)
    {
      number_line++;
      command = strtok(space, DELIMITERS);
      if (command == NULL)
	{
	  free(command);
	  continue;
	}
      else if (*command == '#')
	{
	  continue;
	}
      opcode_stack(command, &stack, number_line);
    }
  free(space);
  fclose(op);
  free_stack(stack);

  return (0);
}
