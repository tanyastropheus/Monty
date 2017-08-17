#include "monty.h"
/**
 * err_msg - print out corresponding error messages & carry out resulting action
 * @code: denotes different error cases
 * @s: message specific to the error case
 * @line_number: denotes at which bytecode line the error is encountered
 * Return: Void
 */

void err_msg(char code, char *spec, unsigned int line_number)
{
	switch(code) {
	case 'F':
		printf("Usage: monty file\n");
		exit(EXIT_FAILURE);
	case 'O':
		printf("Error: Can't open file %s\n", spec); /* need to check argv[1] passing
							      * seems okay upon first test
							      */
		exit(EXIT_FAILURE);
	case 'B':
		printf("L%u: unknown instruction %s\n", line_number, spec); /* need more testing */
		exit(EXIT_FAILURE);
	case 'I':
		printf("L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	case 'M':
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	case 'R':
		printf("L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	case 'P':
		printf("L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	case 'S':
		printf("L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	case 'A':
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
