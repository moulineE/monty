#include "monty.h"
/**
 * _pstr - function that  prints the string starting
 * at the top of the stack, followed by a new line.
 * @stack: a pointer to the stack top
 * @line_number: not use here
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *read = *stack;
	(void)(line_number);

	while (read->n != 0 && read != NULL && (read->n >= 0 && read->n <= 127))
	{
		printf("%c", read->n);
		read = read->next;
	}
	printf("\n");

}
