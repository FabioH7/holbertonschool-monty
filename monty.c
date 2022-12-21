#include "monty.h"

int main(int argc, char *argv[])
{
	FILE *fd;
	char *buffer;
	int i = 0,y = 1, j = 0;
	char *token;
	char *token_array[1024];
	instruction_t arr[] = {{"pall", pall},{"add", add},{"push", NULL},{"swap", swap}, {"pint", pint},{"pop", pop}, {NULL, NULL}};
	stack_t *node = NULL, *tmp;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	buffer = malloc(sizeof(char) * 200);
	while (fgets(buffer, 200, fd))
	{
		j = 0;
		if (strcmp(buffer, "\n") == 0)
		{
			y++;
			continue;
		}
		buffer = strtok(buffer, "\n");
		token = strtok(buffer, " ");
		if (token == NULL)
			continue;
		while (token != NULL)
		{
			token_array[j] = token;
			token = strtok(NULL, " ");
			j++;
		}
		token_array[j] = NULL;
		for (i = 0; arr[i].opcode != NULL; i++)
		{
			if (strncmp(arr[i].opcode, token_array[0], (strlen(token_array[0]))) == 0)
			{
				if (strncmp("push", token_array[0], strlen(token_array[0])) == 0)
				{
					if (token_array[1] == NULL)
					{
						fprintf(stderr, "L%i: usage: push integer\n", y);
                				exit(EXIT_FAILURE);
					}
					node = push(&node, y, token_array[1]);
					if (node == NULL)
						return (1);
				}
				else
					arr[i].f(&node, y);
				break;
			}
		}
		if (arr[i].opcode == NULL)
		{
			fprintf(stderr, "L%i: unknown instruction %s\n", y, token_array[0]);
			exit(EXIT_FAILURE);
		}
		y++;
	}
	while (node != NULL)
        {
                tmp = node;
                node = node->next;
                free(tmp);
        }
	node = NULL;
	free(buffer);
	fclose(fd);
	return (0);
}
