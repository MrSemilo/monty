#include "monty.h"

int main(int ac, char *av[])
{
        stack_t *stack = NULL;
        FILE *open;
        char *line = NULL, *tokens = NULL;
        size_t bufsize = 0;
        unsigned int lines = 0;

        if (ac != 2)
        {
                fprintf(stderr, "USAGE: monty file\n");
                return (EXIT_FAILURE);
        }
        open = fopen(av[1], "r");
        if (!open)
        {
                fprintf(stderr, "Error: Can't open file %s\n", av[1]);
                return (EXIT_FAILURE);
        }
        while (getline(&line, &bufsize, open) != EOF)
        {
                lines++;
                tokens =  strtok(line, DELIMITERS);

                _opcode(tokens, &stack, lines);
        }
        return (0);
}
