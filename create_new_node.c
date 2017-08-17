#include "monty.h"
/**
 * create_new_node - create a new node for a stack made of a doubly linked list
 * @n: data to be stored at the new node
 * Return: address of the pointer to the new node
 */

stack_t *create_new_node(unsigned int line_number) /* may take line_number as paramter
			    * check back after finishing the error handling func
			    */
{
	stack_t *new;
	char *operand;
	long int op_num;
	char *end;

	new = malloc(sizeof(stack_t));
	if (!new)  /* call error function for failed malloc */
		return (NULL);
	operand = strtok(NULL, " ");  /* buffer is a global var */
	op_num = strol(operand, &end, 10);
	if (*end != NULL) /* operand is not a num & can't be converted */
	{
		/* call error function */
		printf("L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new->n = op_num;
	return (new);
}
