#include "monty.h"
/**
 * err_message - print out error messages & execute the resulting action
 * @code: denotes different error cases
 * @spec: message specific to the error case
 * @line_number: denotes at which bytecode line the error is encountered
 * Return: Void
 */

void err_message(enum err_code code, char *spec, unsigned int line_number)
{
	static const char * const err_msg[] = {
		"Usage: monty file",
		"Error: Can't open file",
		"unknown instruction",
		"usage: push integer",
		"Error: malloc failed",
		"can't pint, stack empty",
		"pop an empty stack",
		"can't swap, stack too short",
		"can't add, stack too short",
		"can't sub, stack too short",
		"can't div, stack too short",
		"division by zero",
		"can't mul, stack too short",
		"can't mod, stack too short",
	};

	if (!spec && line_number == 0)
		printf("%s\n", err_msg[code]);
	else if (line_number == 0)
		printf("%s %s\n", err_msg[code], spec);
	else if (!spec)
		printf("L%u: %s\n", line_number, err_msg[code]);
	else
		printf("L%u:%s %s\n", line_number, err_msg[code], spec);
	free_stack(global.stack);
	fclose(global.fptr);
	free(global.line);
	exit(EXIT_FAILURE);
}
