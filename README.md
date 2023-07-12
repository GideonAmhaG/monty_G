# The Monty language
![Latest commit](https://img.shields.io/github/last-commit/EskiasYilma/monty?style=round-square)

---
![](https://pbs.twimg.com/media/CFYYWy6UEAE9Ow-.png)
---

## Introduction

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it.

### The goal of this project is to create an interpreter for Monty ByteCodes files.

## The monty program

* Usage: ``monty file``: where file is the path to the file containing Monty byte code
* If the user does not give any file or more than one argument to your program, print the error message ``USAGE: monty`` file, followed by a new line, and exit with the status ``EXIT_FAILURE``
* If, for any reason, its not possible to open the file, print the error message ``Error: Can't open file <file>``, followed by a new line, and exit with the status ``EXIT_FAILURE``; where <file> is the name of the file
* If the file contains an invalid instruction, print the error message ``L<line_number>: unknown instruction <opcode>``, followed by a new line, and exit with the status ``EXIT_FAILURE``:
  - where is the line number where the instruction appears.
  - Line numbers always start at 1
* The monty program runs the bytecodes line by line and stop if either:
  - it executed properly every line of the file
  - it finds an error in the file
  - an error occured
If you cant malloc anymore, print the error message ``Error: malloc failed``, followed by a new line, and exit with status ``EXIT_FAILURE``.
You have to use ``malloc`` and ``free`` and are not allowed to use any other function from ``man malloc`` (realloc, calloc, )

## Data structures

Please use the following data structures for this project. Dont forget to include them in your header file.


```C
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

```C
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
## Compilation & Output
* Your code will be compiled this way:
````bash
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
````

## OP-CODES Implemented

```C
push - USAGE push <int>
pall - USAGE pall
pint - USAGE pint
pop  - USAGE pop
swap - USAGE swap
add  - USAGE add
sub  - USAGE sub
div  - USAGE div
mul  - USAGE mul
mod  - USAGE mod
nop  - USAGE nop
#
```

## USAGE
````bash
$ ./monty <monty_file>
````

## Authors
* **Eskias Yilma** - [EskiasYilma](https://github.com/EskiasYilma)
* **Gideon Amaha** - [GideonAmhaG](https://github.com/GideonAmhaG)
