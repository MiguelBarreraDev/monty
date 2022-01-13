#include "monty.h"

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
	if (!stack || !(*stack) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		band = true;
		return;
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		band = true;
		return;
	}

	(*stack)->next->n %= (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * f_pchar - print the char value of the first element.
 *
 * @stack: head of the linked list.
 * @line_number: line number.
 * Return: no return.
 */
void f_pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack) || !(*stack)->n)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		band = true;
		return;
	}
	if ((*stack)->n < 0 || (*stack)->n >= 128)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		band = true;
		return;
	}
	printf("%c\n", (*stack)->n);
}
