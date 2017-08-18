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
		err_msg('M', NULL, 0);
	operand = strtok(NULL, "\n\r\t ");
	op_num = strtol(operand, &end, 10);
	if (*end) /* operand is not a num & can't be converted */
		err_msg('I', NULL, line_number);
	new->n = op_num;
	return (new);
}
