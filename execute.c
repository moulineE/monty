#include "monty.h"
/**
 * execute - function that select and execute the correct opreation
 * @cmd: the op code line
 * @stack: the stack top head
 * @line_number: the line number
 */
void execute(char *cmd, stack_t **stack, int line_number)
{
	unsigned int i = 0;
	char *op;
	instruction_t optf[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{NULL, NULL}
	};

	op = strtok(cmd, " \n\t");
	(gl_var.arg_n) = strtok(NULL, " \n\t");
	while ((optf[i].opcode != NULL) && (op != NULL))
	{
		if (strcmp(op, optf[i].opcode) == 0)
		{
			optf[i].f(stack, line_number);
			return;
		}
		i++;
	}
	if (optf[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
		fclose(gl_var.fd);
		free(cmd);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
return;
}
