#include "monty.h"
/**
 * main - interpreter for Monty bytecode files
 * @ac: number of commandline arguments, including the filename
 * @av: array of pointers to the commandine arguments
 * Return: 0 if successful
 */

global_t global.line = NULL;
global_t global.stack = NULL; /* initialize an empty list */

int main(int ac, char *av[])
{
	FILE *fd;
	char *line;
	ssize_t r_count;
	size_t size;
	char *op_code;
	char *operand;  /* need to set as global var */
	long int op_num;
	char *end;
	unsigned int line_number;
	void (*fp)(stack_t **stack, unsigned int line_number);

	if (ac != 2) /* if no file is given, or more than one argv */
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	if (!fd)
	{
		printf("Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	line_number = 1;
	line = NULL;  /* why do we need to do this in shell? */
	while (r_count = getline(&line, &size, fd) != -1)
	{
		op_code = strtok(line, " "); /* 1st time, returns ptr to opcode */
		/* need to test if line number increments for empty line */
		fp = get_op(op_code);
		if (fp == NULL)  /* bytecode invalid */
		{
			printf("L%u: unknown instruction %s\n", line_number, op_code);
			exit(EXIT_FAILURE);
		}
/* to be handled in the sub-function */
/*		if (strcmp(op_code, "push") == 0)  /* if the opcode is push, check for operand */
/*		{
			operand = strtok(NULL, " ");
			op_num = strtol(operand, &end, 10);
			if (*end != NULL)  /* operand is not a num & cannot be converted to int */
/*			{
				printf("L%u: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
		}
*/		line_number++;
	}

	exit();  /* getline returns -1 on the first run
		  * while loop doesn't execute
		  * means the file is empty
		  */
}
