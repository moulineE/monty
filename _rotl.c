#include "monty.h"
/**
 * _rotl - function that rotates the stack to the top.
 * @stack: a pointer to the stack top
 * @line_number: not use here
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first = *stack, *last = *stack;
	(void)(line_number);

	while (last->next != NULL)
	{
		last = last->next;
	}
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	last->next->next = NULL;
}
