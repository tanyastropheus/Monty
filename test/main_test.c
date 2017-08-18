#include "monty.h"

global_t global = {NULL, NULL};

int main(int ac, char *av[])
{
	char *line, *op_code;
	ssize_t r_count;
	size_t size;
	FILE *fd;
/*	unsigned int line_number;
	void (*fp)(stack_t **stack, unsigned int line_number);
 */
	if (ac == 1 || ac > 2) /* if no file is given, or more than one argv */
        {
                printf("USAGE: monty file\n");
                exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");

	while ((r_count = getline(&line, &size, fd)) != -1)
	{
		printf("The while loop runs!\n");
/*		op_code = strtok(line, " ");  1st time, returns ptr to opcode
		need to test if line number increments for empty line
		fp = get_op(op_code);
		if (fp == NULL) bytecode invalid
			err_msg('B', op_code, line_number);
		line_number++;
*/	}
	printf("getline return for empty file: %d\n", (int)r_count);
        return (0);  /* getline returns -1 on the first run


	do {
		line = NULL;
		r_count = getline(&line, &size, fd);
		if (r_count == -1)
		{
			printf("EOF\n");
			break;
		}
		op_code = strtok(line, " ");
		printf("opcode: %s\n", op_code);
		printf("printf unsigned int format test: %u\n", 3);
		printf("getline returns: %d\n", (int)r_count);
	} while (r_count != -1);
	return (0);
		     */
}
