#include "monty.h"
/**
 * delete_dnodeint_at_index - deletes the node at index index of a
 * stack_t linked list.
 * @head: pointer to the head node of a Doubley linked list
 * @index: index of node to delete
 * Return: Null
 */

void delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *temp, *ptr;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", gl_line_number);
		exit(EXIT_FAILURE);
	}

	ptr = *head;
	if (index == 0 && ptr->next == NULL)
	{
		free(*head);
		*head = NULL;
		return;
	}
	if (index == 0 && ptr->next != NULL)
	{
		*head = ptr->next;
		(*head)->prev = NULL;
		free(ptr);
		return;
	}
	while (i < index - 1 && ptr && ptr->next)
	{
		ptr = ptr->next;
		i++;
	}
	if (ptr->next == NULL)
		return;

	temp = ptr->next;
	ptr->next = temp->next ? temp->next : NULL;
	if (temp->next)
		temp->next->prev = ptr;
	free(temp);
	dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", gl_line_number);
	exit(EXIT_FAILURE);
}

/**
 * swap_nd - swaps the nodes of a doubly linked list
 * @stack: pointer to head node
 */
void swap_nd(stack_t *stack)
{
	stack_t *temp = stack;
	int data = 0;

	data = temp->n;
	temp->n = (temp->next)->n;
	(temp->next)->n = data;
}

/**
 * dlistint_len - returns number of nodes of a doubly linked list
 * @h: pointer to head node
 *
 * Return: the number of nodes mentioned above
 */
size_t dlistint_len(const stack_t *h)
{
	size_t count = 0;

	if (h == NULL)
	return (0);
	while (h != NULL)
	{
		count++;
		h = h->next;
	}
	return (count);
}

/**
 * add_topnode - add top stack
 * @stack: Pointed to head of a list
 */
void add_topnode(stack_t **stack)
{
	stack_t *tmp = *stack;
	int data = 0;

	data = tmp->n;
	(tmp->next)->n += data;
	delete_dnodeint_at_index(stack, 0);
}
