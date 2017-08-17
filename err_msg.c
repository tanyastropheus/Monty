#include "monty.h"
/**
 * err_msg - print out corresponding error messages & carry out resulting action
 * @code: denotes different error cases
 * @s: message specific to the error case
 * @line_number: denotes at which bytecode line the error is encountered
 * Return: Void
 */

void err_msg(char code, char *s, unsigned int line_number)
{
	switch(code) {
	case 'F':
		printf("Usage: monty file\n");
		exit(EXIT_FAILURE);
	case 'O':
		printf("Error: Can't open file %s\n", argv[1]); /* need to check argv[1] passing */
		exit(EXIT_FAILURE);
	case 'B':
		printf("L%u: unknown instruction %s\n", line_number, op_code); /* need to check op_code */
		exit(EXIT_FAILURE);
	case 'N':
		printf("L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	case 'M':
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
}
