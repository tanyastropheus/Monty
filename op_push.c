#include "monty.h"
/**
 * op_push - push an element on top of the stack made of a doubly linked list
 * @stack: address to the pointer to the top of the stack, or the head node
 * @line_number: line number of the bytecode file  /* need to edit later */
 * Return: Void
 */

void op_push(stack_t **stack, unsigned int line_number)
{

	stack_t *new;

	if (head == NULL) /* invalid pointer
			   * Is it necessary to test this for this project?
			   */
		return (NULL);

	new = create_new_node(line_number);

	new->prev = NULL;
	new->next = *stack;
	if (*stack != NULL) /* if the list is not empty */
		(*stack)->prev = new;
	*stack = new;
}
