#include "monty.h"
/**
 * _pchar - function that prints the char at the top of the stack,
 * followed by a new line.
 * @stack: a pointer to the stack top
 * @line_number: not use here
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *read = *stack;

	if (read == NULL || ((read->n < 0) || (read->n > 127)))
	{
		if (read == NULL)
		{
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		}
		else
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		}
		free_dlistint(*stack);
		fclose(gl_var.fd);
		free(gl_var.arg_n);
		free(gl_var.cmd);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", read->n);
}
