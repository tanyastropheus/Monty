#include "monty.h"
/**
 * main - interpreter for Monty bytecode files
 * @ac: number of commandline arguments, including the filename
 * @av: array of pointers to the commandine arguments
 * Return: 0 if successful
 */

global_t global = {NULL, NULL, NULL};

int main(int ac, char *av[])
{
	ssize_t r_count;
	size_t size;
	char *op_code;
	unsigned int line_number;
	void (*fp)(stack_t **stack, unsigned int line_number);

	if (ac != 2) /* if no file is given, or more than one argv */
		err_message(ERR_FILE, NULL, 0);
	global.fptr = fopen(av[1], "r");
	if (!(global.fptr))
		err_message(ERR_OPEN, av[1], 0);

	line_number = 1;
	while ((r_count = getline(&(global.line), &size, global.fptr)) != -1)
	{
		op_code = strtok(global.line, "\n\t\r ");
		if (!op_code) /* if the line is empty */
			;
		else
		{
			fp = get_op(op_code);
			if (fp == NULL)  /* bytecode invalid */
				err_message(ERR_INVAL, op_code, line_number);
			fp(&(global.stack), line_number);
		}
		line_number++;
	}
	fclose(global.fptr);
	free(global.line);
	free_stack(global.stack);
	return (0);  /* getline returns -1 on the first run
		      * while loop doesn't execute
		      * means the file is empty
		      */
}
