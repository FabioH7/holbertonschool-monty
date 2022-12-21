#include "monty.h"
/*
 * pall - function that prints the elements of the linked lists from the head to the end
 * @stack: parameter refering to the nodes
 * @line number: unused in this case
 */
void pall(stack_t **stack, unsigned int  __attribute__((unused)) line_number)
{
	stack_t *ptr;

	ptr = *stack;
	if (*stack == NULL)
		return;
	while (ptr !=  NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
/*
 * pint - function that prints the head of our stack
 * @stack: parameter refering to the nodes
 * @line number: line number being read from the monty file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%i\n", (*stack)->n);
}
/* pop - function that removes the first node of the stack
 * @stack: parameter refering to our nodes
 * @line number: line number being read from the monty file
 */
void pop (stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr,"L%i: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	if ((*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
		return;
	}
	*stack = tmp->next;
	(*stack)->prev = NULL;
	free(tmp);
	return;
}
void add (stack_t **stack, unsigned int line_number)
{
	int sum = 0;

	if ((*stack)->next == NULL || *stack == NULL)
	{
		fprintf(stderr,"L%i: can't add, stack too short\n", line_number);
                exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = sum;
	pop(stack, line_number);
}
