#  **Moonty Lenguage Interpeter** :computer:

_holberton 0x19. C - Stacks, Queues - LIFO, FIFO_

## Description

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it.

## The objective of this project:

The goal of this project is to create an interpreter for Monty ByteCodes files.

## Requirements Project

* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 14.04 LTS
* Your programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
* All your files should end with a new line
* A README.md file, at the root of the folder of the project is mandatory
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* You allowed to use a maximum of one global variable
* No more than 5 functions per file
* You are allowed to use the C standard library
* The prototypes of all your functions should be included in your header file called monty.h
* Dont forget to push your header file
* All your header files should be include guarded
* You are expected to do the tasks in the order shown in the project

## Data Structures
```
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
```
```
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
```
## Monty commands Bytecodes
* push <int> : pushes an integer onto the top of the stack.
* pall : prints all values on the stack.
* pint : prints the value at the top of the stack.
* add : adds the top two elements of the stack.
* pop : removes the top element of the stack.
* swap : swaps the top two elements of the stack
* nop : does nothing

### Compilation
You 
```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```

### examples
* **pall**
```
julien@ubuntu:~/monty$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
julien@ubuntu:~/monty$ ./monty bytecodes/00.m
3
2
1
julien@ubuntu:~/monty$
```
* **pint**
```
julien@ubuntu:~/monty$ cat bytecodes/06.m 
push 1
pint
push 2
pint
push 3
pint
julien@ubuntu:~/monty$ ./monty bytecodes/06.m 
1
2
3
julien@ubuntu:~/monty$ 
```
* **pop**
```
julien@ubuntu:~/monty$ cat bytecodes/07.m 
push 1
push 2
push 3
pall
pop
pall
pop
pall
pop
pall
julien@ubuntu:~/monty$ ./monty bytecodes/07.m 
3
2
1
2
1
1
julien@ubuntu:~/monty$ 
```
* **swap**
```
julien@ubuntu:~/monty$ cat bytecodes/09.m 
push 1
push 2
push 3
pall
swap
pall
julien@ubuntu:~/monty$ ./monty bytecodes/09.m 
3
2
1
2
3
1
julien@ubuntu:~/monty$ 
```
* **add**
```
julien@ubuntu:~/monty$ cat bytecodes/12.m 
push 1
push 2
push 3
pall
add
pall

julien@ubuntu:~/monty$ ./monty bytecodes/12.m 
3
2
1
5
1
julien@ubuntu:~/monty$
```
---

## Contribution:heavy_check_mark:
---

# AUTHORS ✒️
* Jaime Garcia.
* Camilo Valencia.
