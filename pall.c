#include "monty.h"
/**
 * _pall - function that print the stack
 * @stack: a pointer to the stack top
 * @line_number: not use here
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *read = *stack;
	(void)(line_number);

	while (read != NULL)
	{
		printf("%d\n", read->n);
		read = read->next;
	}
}
