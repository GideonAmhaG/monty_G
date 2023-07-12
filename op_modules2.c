#include "monty.h"

/**
 * sub - subtracts the top element of the stack from the
 * second top element of the stack
 * @stack: pointer to head of stack
 * @line_number: number of the line in the bytecode file
 * Return: Nothing
 */
void sub(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (dlistint_len(*stack) >= 2)
	{
		sub_topnode(stack);
		return;
	}
	dprintf(STDERR_FILENO, "L%d: can't sub, stack too short\n",
			gl_line_number);
	exit(EXIT_FAILURE);
}

/**
 * op_div - divides the second top element of the stack by the
 * top element of the stack
 * @stack: pointer to head of stack
 * @line_number: number of the line in the bytecode file
 * Return: Nothing
 */
void op_div(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (dlistint_len(*stack) >= 2)
	{
		div_topnode(stack);
		return;
	}
	dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n",
			gl_line_number);
	exit(EXIT_FAILURE);
}
/**
 * op_mul - multiplies the second top element of the stack
 * with the top element of the stack.
 * @stack: pointer to head of stack
 * @line_number: number of the line in the bytecode file
 * Return: Nothing
 */
void op_mul(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (dlistint_len(*stack) >= 2)
	{
		mul_topnode(stack);
		return;
	}
	dprintf(STDERR_FILENO, "L%d: can't mul, stack too short\n",
			gl_line_number);
	exit(EXIT_FAILURE);
}

/**
 * op_mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 * @stack: pointer to head of stack
 * @line_number: number of the line in the bytecode file
 * Return: Nothing
 */
void op_mod(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (dlistint_len(*stack) >= 2)
	{
		mod_topnode(stack);
		return;
	}
	dprintf(STDERR_FILENO, "L%d: can't mod, stack too short\n",
			gl_line_number);
	exit(EXIT_FAILURE);
}
