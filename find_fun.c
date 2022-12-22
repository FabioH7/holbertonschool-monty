#include "monty.h"

/**
 * find_func - finds function found at array and calls that function with args
 * @token_array: where the commands and arguments are stored
 * @y: line number
 * @node: node list where we execute our functions
 */
void find_func(char *token_array[], int y, stack_t **node)
{
	int i;
	instruction_t arr[] = {{"pall", pall}, {"add", add}, {"push", NULL},
	{"swap", swap}, {"pint", pint}, {"pop", pop},
	{"nop", NULL}, {NULL, NULL}};

	for (i = 0; arr[i].opcode != NULL; i++)
	{
		if (strncmp(arr[i].opcode, token_array[0], (strlen(token_array[0]))) == 0)
		{
			if (strncmp("nop", token_array[0], strlen(token_array[0])) == 0)
				return;
			if (strncmp("push", token_array[0], strlen(token_array[0])) == 0)
			{
				if (token_array[1] == NULL)
				{
					fprintf(stderr, "L%i: usage: push integer\n", y);
					exit(EXIT_FAILURE);
				}
				*node = push(node, y, token_array[1]);
				if (node == NULL)
					exit(EXIT_FAILURE);
			}
			else
				arr[i].f(node, y);
			break;
		}
	}
	if (arr[i].opcode == NULL)
	{
		fprintf(stderr, "L%i: unknown instruction %s\n", y, token_array[0]);
		exit(EXIT_FAILURE);
	}
}
