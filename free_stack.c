#include "monty.h"
/**
 * free_stack - free the data stored on the stack
 * @stack: pointer to the stack
 * Return: void
 */

void free_stack(stack_t *stack)
{
	stack_t *temp;

	if (!stack)
		return;

	temp = stack;
	while (temp)
	{
		stack = stack->next;
		free(temp);
		temp = stack;
	}
}
