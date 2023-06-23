#include "monty.h"

void _push(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	int n;

	if (arg_n == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(fd);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	if (arg_n[i] > 57 || arg_n[i] < 48)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		printf("arg_n: %s", arg_n);
		fclose(fd);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	n = atoi(arg_n);
	add_dnodeint(stack, n);
}
