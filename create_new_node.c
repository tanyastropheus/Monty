#include "monty.h"
/**
 * create_new_node - create a new node for a stack made of a doubly linked list
 * @line_number: line number of the bytecode file
 * Return: address of the pointer to the new node
 */

stack_t *create_new_node(unsigned int line_number)
{
	stack_t *new;
	char *operand;
	long int op_num;
	char *end;

	new = malloc(sizeof(stack_t));
	if (!new)
		err_message(ERR_MALLOC, NULL, 0);
	operand = strtok(NULL, "\n\r\t ");
	if (!operand) /* if not operand is given */
	{
		free(new);
		err_message(ERR_INT, NULL, line_number);
	}
	op_num = strtol(operand, &end, 10);
	if (*end) /* operand is not a num & can't be converted */
	{
		free(new);
		err_message(ERR_INT, NULL, line_number);
	}
	new->n = op_num;
	return (new);
}
