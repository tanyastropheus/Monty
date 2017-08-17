#include "monty.h"
/**
 * main - provide testing cases for the err_msg function
 * @ac: number of commandline arguments
 * @av: an array of pointersto the commandline arguments
 * Return: 0 if successful
 */
int main(int ac, char **av)
{
	unsigned int line_number;
	char *op_code;
	char *line;
	FILE *fd;
	size_t size;

	line = NULL;
	(void)(ac);
	(void)(av);
	line_number = 3;
	fd = fopen(av[1], "r");
	getline(&line, &size, fd);
	op_code = strtok(line, " ");
	printf("op_code: %s\n", op_code);
/*	err_msg('F', NULL, 0);
	err_msg('O', av[1], 0);
	err_msg('B', op_code, line_number);
*/	err_msg('I', NULL, line_number);
	err_msg('M', NULL, 0);
	err_msg('R', NULL, line_number);
	err_msg('P', NULL, line_number);
	err_msg('S', NULL, line_number);
	err_msg('A', NULL, line_number);

	return (0);
}
