#include "monty.h"

/**
 * f_push - pushes an element to the stack.
 *
 * @stack: head of the linked list.
 * @line_number: line number.
 * Return: no return.
 */
void f_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL, *tmp = NULL;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		band = true;
		return;
	}

	if (!argInt)
	{
		free(new_node);
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		band = true;
		return;
	}
	new_node->n = number;
	if (mode == false)
	{
		if (*stack != NULL)
			(*stack)->prev = new_node;
		new_node->next = *stack;
		new_node->prev = NULL;
		*stack = new_node;
	}
	else
	{
		tmp = *stack;
		if (*stack == NULL)
		{
			*stack = new_node;
			new_node->next = NULL;
			new_node->prev = NULL;
		}
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new_node;
			new_node->next = NULL;
			new_node->prev = tmp;
		}
	}
}

/**
 * f_pall - prints all values on the stack.
 *
 * @stack: head of the linked list.
 * @line_number: line number.
 * Return: no return.
 */
void f_pall(stack_t **stack, _uu_ unsigned int line_number)
{
	stack_t *tmp = *stack;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * f_pint - prints the value at the top of the stack.
 *
 * @stack: head of the linked list.
 * @line_number: line number.
 * Return: no return.
 */
void f_pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		band = true;
		return;
	}
	printf("%d\n", (*stack)->n);
}

/**
 * f_pop - removes the top element of the stack.
 *
 * @stack: head of the linked list.
 * @line_number: line number.
 * Return: no return.
 */
void f_pop(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		band = true;
		return;
	}
	if ((*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
	}
	else
	{
		*stack = (*stack)->next;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
}

/**
 * f_swap - swaps the top two elements of the stack.
 *
 * @stack: head of the linked list.
 * @line_number: line number.
 * Return: no return.
 */
void f_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (!stack || !(*stack) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		band = true;
		return;
	}

	tmp = (*stack)->next;
	(*stack)->prev = tmp;
	(*stack)->next = tmp->next;

	tmp->prev = NULL;
	if (tmp->next)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	*stack = tmp;
}
