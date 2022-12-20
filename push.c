#include "monty.h"

stack_t *push(stack_t **stack, unsigned int line_number, char *n)
{
	stack_t *new;
	int number = atoi(n);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "can't allocate memory %i", line_number);
		exit(EXIT_FAILURE);
	}
	new->n = number;
	new->prev = NULL;
	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
	return (*stack);
}
