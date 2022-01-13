#include "main.h"
/**
 * f_mod - computes the rest of the division of the
 * second element.
 *
 * @stack: head of the linked list.
 * @line_number: line number.
 * Return: no return.
 */
void f_mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L<%u>: can't mod, stack too short\n", line_number);
		band = true;
		return;
	}
	if ((*stack)->next->n == 0)
	{
		fprintf(stderr, "L<%u> division by zero\n", line_number);
		band = true;
		return;
	}

	(*stack)->n %= (*stack)->next->n;
	(*stack)->next->n = (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 *
 *
 */
void f_pchar(_uu_ stack_t **stack, _uu_ unsigned int line_number)
{
	return;
}
