#include "monty.h"

/**
 * build_arr - builds array from buffer
 * @token_array: array to build
 * @buffer: strings used to build array
 */
void build_arr(char *token_array[], char *buffer)
{
	char *token;
	int j = 0;

	buffer = strtok(buffer, "\n");
	token = strtok(buffer, " ");
	if (token == NULL)
	{
		token_array[0] = NULL;
		return;
	}
	while (token != NULL)
	{
		token_array[j] = token;
		token = strtok(NULL, " ");
		j++;
	}
	token_array[j] = NULL;
}
