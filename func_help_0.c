#include "monty.h"
/**
 * _trim - function that removes whitespace at the beginning
 * @str: double pointer to string to format
 */
void _trim(char **str)
{
	int i = 0, j = 0, len = 0;
	char *tmp = *str;
	char *fstr = NULL;

	if (**str == ' ' || **str == '\t')
	{
		while ((*(*str + i) == ' ' || *(*str + i) == '\t') && *(*str + i) != '\0')
			i++;
		while (*(*str + i + len) != '\0')
			len++;

		fstr = malloc(sizeof(char) * len + 1);
		while (*(*str + i) != '\0')
		{
			*(fstr + j) = *(*str + i);
			i++;
			j++;
		}
		*(fstr + j) = '\0';
		*str = fstr;
		free(tmp);
	}
}
/**
 * validate_number - validate if the string represents an integer
 * @str_number: the string represents an integer
 *
 * Return: length on success, 0 on failure
 */
int validate_number(char *str_number)
{
	int count = 0, i = 0;

	if (*str_number == '-')
		str_number++;
	for (i = 0; str_number != NULL && str_number[i]; i++)
	{
		if (!(str_number[i] >= '0' && str_number[i] <= '9'))
			count++;
	}
	if (count != 0)
		return (-1);
	return (i);
}
/**
 * dfree_list - free stack.
 *
 * @head: pointer to head of the stack.
 */
void dfree_list(stack_t *head)
{
	if (!head)
		return;
	dfree_list(head->next);
	free(head);
}
