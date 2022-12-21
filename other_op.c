#include "monty.h"

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
