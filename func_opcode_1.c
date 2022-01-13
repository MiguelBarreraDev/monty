#include "monty.h"

/**
 * f_add - adds the top two elements of the stack.
 *
 * @stack: head of the linked list.
 * @line_number: line number.
 * Return: no return.
 */
void f_add(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		band = true;
		return;
	}
	(*stack)->next->n += (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * f_nop - doesn't do anythinhg.
 *
 * @stack: head of the linked list.
 * @line_number: line number.
 * Return: no return.
 */
void f_nop(_uu_ stack_t **stack, _uu_ unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * f_sub - subtracts the top element to the second
 * top element of the stack.
 *
 * @stack: head of the linked list.
 * @line_number: line number.
 * Return: no return.
 */
void f_sub(stack_t **stack, unsigned int line_number)
{

	if (!stack || !(*stack) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		band = true;
		return;
	}

	(*stack)->next->n -= (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * f_div - divides the second element by the top element of the stack.
 *
 * @stack: head of the linked list.
 * @line_number: line number.
 * Return: no return.
 */
void f_div(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		band = true;
		return;
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u can't be divided by zero\n", line_number);
		band = true;
		return;
	}


	(*stack)->next->n /= (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * f_mul - multiplies the top element to the second top
 * element of the stack.
 *
 * @stack: head of the linked list.
 * @line_number: line number.
 * Return: no return.
 */
void f_mul(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		band = true;
		return;
	}
	(*stack)->next->n *= (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
