#include "monty.h"

/**
 * sub_topnode - subtracts top stack
 * @stack: pointer to head of stack_t list
 * Return: Nothing
 */
void sub_topnode(stack_t **stack)
{
	stack_t *temp = *stack;
	int data = 0;

	data = temp->n;
	(temp->next)->n -= data;
	delete_dnodeint_at_index(stack, 0);
}

/**
 * div_topnode - divides second top element by top element of stack
 * @stack: pointer to head of stack_t list
 * Return: Nothing
 */
void div_topnode(stack_t **stack)
{
	stack_t *temp = *stack;
	int data = 0;

	data = temp->n;
	if (data == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", gl_line_number);
		exit(EXIT_FAILURE);
	}
	(temp->next)->n = (temp->next)->n / data;
	delete_dnodeint_at_index(stack, 0);
}

/**
 * mul_topnode - add top stack
 * @stack: pointer to head of stack_t list
 * Return: Nothing
 */
void mul_topnode(stack_t **stack)
{
	stack_t *temp = *stack;
	int data = 0;

	data = temp->n;
	(temp->next)->n = (temp->next)->n * data;
	delete_dnodeint_at_index(stack, 0);
}

/**
 * mod_topnode - computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 * @stack: pointer to head of stack_t list
 * Return: Nothing
 */
void mod_topnode(stack_t **stack)
{
	stack_t *temp = *stack;
	int data = 0;

	data = temp->n;
	if (data == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", gl_line_number);
		exit(EXIT_FAILURE);
	}
	(temp->next)->n = (temp->next)->n % data;
	delete_dnodeint_at_index(stack, 0);
}
