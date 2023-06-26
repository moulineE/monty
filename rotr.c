#include "monty.h"
/**
 * _rotr - function that rotates the stack to the bottom.
 * @stack: a pointer to the stack top
 * @line_number: not use here
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *first = *stack, *last = *stack;
	(void)(line_number);

	if (first == NULL || first->next == NULL)
	{
		return;
	}
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->prev->next = NULL;
	last->next = first;
	last->prev = NULL;
	(*stack)->prev = last;
	*stack = last;
}
