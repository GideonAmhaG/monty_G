#include "monty.h"

/**
 * push - adds node at the beginning of the stack
 * @stack: head pointer to stack
 * @line_number: line number of the file
 */
void push(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	if (gl_argv != NULL && _isdigit() != 0)
	{
		add_dnodeint(stack, atoi(gl_argv));
		return;
	}
	dprintf(STDERR_FILENO, "L%d: usage: push integer\n", gl_line_number);
	exit(EXIT_FAILURE);
}

/**
 * pall - print elements of a doubly linked list
 * @stack: head pointer to stack
 * @line_number: line number of the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	print_dlistint(*stack);
}

/**
 * pint - prints the value at the top of the stack
 * @stack: head pointer to stack
 * @line_number: line number of file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (stack && *stack)
		pr_head(*stack);
	else
	{
		fclose(byte_file);
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n",
		gl_line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pop - Delete the node at the beginning of the stack
 * @stack: head pointer to stack
 * @line_number: line number of file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (stack && *stack)
	{
		delete_dnodeint_at_index(stack, 0);
		return;
	}
	dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n",
			gl_line_number);
	exit(EXIT_FAILURE);
}
