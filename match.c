#include "main.h"

/**
 * matcher - search the match and execute the opcode associated.
 *
 * @opc: opcode passed.
 * Return: returns the executed function if there is a match,
 * otherwise returns -1.
 */
void (*matcher(char *opc))(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	instruction_t list_opc[] = {
		{"pall", f_pall},
		{"pop", f_pop},
		{"push", f_push},
		{"pint", f_pint},
		{"swap", f_swap},
		{"add", f_add},
		{"nop", f_nop},
		{"sub", f_sub},
		{"div", f_div},
		{"mul", f_mul},
		{"mod", f_mod},
		{NULL, NULL}
	};
	while (list_opc[i].opcode)
	{
		if (strcmp(list_opc[i].opcode, opc) == 0)
			return (list_opc[i].f);
		i++;
	}

	return (NULL);
}
