#include "monty.h"

/**
 * main - monty code interpreter
 * @argc: arguments number
 * @argv: arguments
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	FILE *fd;
	int y = 1;
	char *buffer, *token_array[1024];
	stack_t *node = NULL;

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
		if (strcmp(buffer, "\n") == 0)
		{
			y++;
			continue;
		}
		build_arr(token_array, buffer);
		if (token_array[0] == NULL)
		{
			y++;
			continue;
		}
		find_func(token_array, y, &node);
		y++;
	}
	_free(node);
	free(buffer);
	fclose(fd);
	return (0);
}
