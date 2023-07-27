#include "monty.h"
/**
 * main - teh entry of the program
 * @argc: number of arguments
 * @argv: pointer to the array of arguments
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	FILE *fptr;
	ssize_t bytes_read;
	size_t l = 0;
	char *line = NULL;
	char *token = NULL;
	int line_number = 0;
	stack_t *head = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	else
	{
		fptr = fopen(argv[1], "r");
		if (fptr == NULL)
		{
			printf("Error: Can't open file %s\n", argv[1]);
			return (EXIT_FAILURE);
		}
		else
		{
			while ((bytes_read = getline(&line, &l, fptr)) != -1)
			{
				line_number++;
				token = get_tokens(line, line_number);
				if (token != NULL)
					get_func(token, &head, line_number);
			}
			free(line);
			free_stack(head);
			fclose(fptr);
		}
	}

	return (0);
}
