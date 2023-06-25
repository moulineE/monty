#include "monty.h"
/**
 * _pop - function that removes the top element of the stack.
 * @stack: a pointer to the stack top
 * @line_number: the opcode file line
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *read = *stack;

	if (read != NULL)
	{
		*stack = read->next;
		(*stack)->prev = NULL;
		free(read);
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
}
