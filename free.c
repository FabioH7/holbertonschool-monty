#include "monty.h"

/**
 * _free - frees a list
 * @head: list to free
 */
void _free(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	head = NULL;
}
