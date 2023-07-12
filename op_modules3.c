#include "monty.h"

/**
 * pchar - prints the char at the top of the stack, followed by a new line
 * @stack: pointer to head of stack
 * @line_number: number of the line in the bytecode file
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	(void)line_number;
	if (top == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, stack empty\n",
			gl_line_number);
		exit(EXIT_FAILURE);
	}
	if ((top->n) >= 0 && (top->n) <= 127)
	{
		printf("%c\n", (char)(top->n));
		return;
	}
	dprintf(STDERR_FILENO, "L%d: can't pchar, value out of range\n",
			gl_line_number);
	exit(EXIT_FAILURE);
}

/**
 * pstr - prints the string starting at the top of the stack, followed
 * by a new line
 * @stack: pointer to head of stack
 * @line_number: number of the line in the bytecode file
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;
	if (*stack == NULL)
	{
		printf("\n");
		return;
	}
	temp = *stack;
	while (temp != NULL && temp->n > 0 && temp->n <= 127)
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotl - top element of the stack becomes the last one, and the second top
 * element of the stack becomes the first one
 * @stack: pointer to head of stack
 * @line_number: number of the line in the bytecode file
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int data = 0;

	if (*stack == NULL || stack == NULL)
		return;
	(void) line_number;
	data = temp->n;
	while (temp->next)
	{
		temp->n = (temp->next)->n;
		temp = temp->next;
	}
	temp->n = data;
}
