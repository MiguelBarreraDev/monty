#include "main.h"

int number = 0;
bool band = false;
bool argInt = false;

/**
 * main - entry point and general management.
 *
 * @argc: argument values.
 * @argv: argument count.
 * Return: 0 if success, other value if error.
 */
int main(int argc, char **argv)
{
	FILE *ptr = NULL;
	char *path = NULL;

	if (argc != 2)
	{
		fprintf(stderr,"USAGE: monty file\n");
		exit (EXIT_FAILURE);
	}
	path = argv[1];
	ptr = fopen(path, "r");
	if (ptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file <%s>\n", path);
		exit (EXIT_FAILURE);
	}
	read_line(ptr);

	return 0;
}

/**
 * read_line - reads a file line by line and
 * stores it in a buffer.
 *
 * @ptr: file descriptor.
 * Return: no return.
 */
void read_line(FILE *ptr)
{
	char *line = NULL, **items = NULL;
	size_t len = 0, nl = 1;
	long int r_size = 0;
	void (*f)(stack_t **stack, unsigned int line_number) = NULL;
	stack_t *head = NULL;

	while(r_size != EOF)
	{
		len = 0;
		argInt = false;
		r_size = getline(&line, &len, ptr);
		if(r_size != EOF)
		{
			_trim(&line);
			if (!(*line == '#' || strlen(line) < 2))
			{
				items = parameter_to_str(&line);
				f = matcher(items[0]);
				free(items[0]);
				if (!f)
				{
					fprintf(stderr, "L<%ld>: unknown instruction <%s>\n", nl, items[0]);
					band = true;
				}
				else
					f(&head, nl);
			}
			nl++;
		}
		free(line);
		if (r_size == EOF || band == true)
		{
			dfree_list(head);
			fclose(ptr);
			free(items);
		}
		if (band == true)
			exit(EXIT_FAILURE);
	}
}
/**
 * parameter_to_str - split a chain into tokens for
 * further interpretation
 *
 * @str: point to address of the string
 * @return: double pointer
 */
char **parameter_to_str(char **str)
{
	char **tokens = malloc(sizeof(char *) * 3);
	size_t pos = 0;
	int validate = 0;

	if (!tokens)
	{
		fprintf(stderr, "Error: malloc failed\n");
		band = true;
		return (NULL);
	}
	while ((tokens[pos] = strtok(*str, " \n\t")))
	{
		if (strcmp(tokens[0], "push") == 0 && pos > 0)
		{
			validate = validate_number(tokens[pos]);
			if (validate != -1)
			{
				argInt = true;
				number = atoi(tokens[pos]);
			}
		}
		*str = NULL;
		pos++;
	}
	return (tokens);
}
