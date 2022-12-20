#include "monty.h"

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
