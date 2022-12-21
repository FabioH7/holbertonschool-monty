#include "monty.h"

int main(int argc, char *argv[])
{
	FILE *fd;
	char *buffer;
	int i = 0,y = 1, j = 0;
	char *token;
	char *token_array[1024];
	instruction_t arr[] = {{"pall", pall},{"push", NULL},{"pint", pint},{"pop", pop}, {NULL, NULL}};
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
			if (strncmp(token_array[0], arr[i].opcode, strlen(arr[i].opcode)) == 0)
			{
				if (strncmp(token_array[0], "push", strlen("push")) == 0)
					node = push(&node, y, token_array[1]);
				else
					arr[i].f(&node, y);
				break;
			}
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