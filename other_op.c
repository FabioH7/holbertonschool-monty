#include "monty.h"

/**
 * swap - swap the values of first 2 nodes
 * @stack: head node list
 * @line_number: error line_number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *node;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%i: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	node = ((*stack)->next);
	temp = (*stack)->n;
	(*stack)->n = node->n;
	node->n = temp;
}

/**
 * stack_len - finds node list len
 * @h: node list to find len
 * Return: len
 */
size_t stack_len(const stack_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}
	return (count);
}
