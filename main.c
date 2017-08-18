#include "monty.h"
/**
 * main - interpreter for Monty bytecode files
 * @ac: number of commandline arguments, including the filename
 * @av: array of pointers to the commandine arguments
 * Return: 0 if successful
 */

global_t global = {NULL, NULL};

int main(int ac, char *av[])
{
	FILE *fd;
	char *line;
	ssize_t r_count;
	size_t size;
	char *op_code;
	unsigned int line_number;
	void (*fp)(stack_t **stack, unsigned int line_number);

	if (ac != 2) /* if no file is given, or more than one argv */
		err_msg('F', NULL, 0);
	fd = fopen(av[1], "r");
	if (!fd)
		err_msg('O', av[1], 0);

	line_number = 1;
	line = NULL;
	while ((r_count = getline(&line, &size, fd)) != -1)
	{
		op_code = strtok(line, "\n\t\r "); /* 1st time, returns ptr to opcode */
		if (!op_code) /* if the line is empty */
			;
		else
		{
			fp = get_op(op_code);
			if (fp == NULL)  /* bytecode invalid */
				err_msg('B', op_code, line_number);
			fp(&(global.stack), line_number);
		}
		line_number++;
	}
	fclose(fd);
	free(line);
	free_stack(global.stack);
	return (0);  /* getline returns -1 on the first run
		      * while loop doesn't execute
		      * means the file is empty
		      */
}
