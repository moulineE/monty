#include "monty.h"
gl_var_t gl_var = {NULL, NULL};
/**
 * main - interpreter for Monty ByteCodes files.
 * @argc: number of arguments
 * @argv: monty op code file
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	size_t bufsize = 0;
	ssize_t line_wc = 1;
	int line_number = 0;
	char *cmd = NULL;


	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	gl_var.fd = fopen(argv[1], "r");
	if (!(gl_var.fd))
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (line_wc > 0)
	{
		line_number++;
		cmd = NULL;
		line_wc = getline(&cmd, &bufsize, gl_var.fd);
		if (line_wc < 1)
		{
			continue;
		}
		execute(cmd, &stack, line_number);
		free(cmd);
	}
	free_dlistint(stack);
	free(cmd);
	fclose(gl_var.fd);
	return (0);
}
