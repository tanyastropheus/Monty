#include "monty.h"
/**
 * get_op - selecting appropriate function based on the input opcode
 * @s: pointer to the op_code string
 * Return: a pointer to the operator function that corresponds to the opcode
 */

void *(get_op(char *s))(stack_t **stack, unsigned int line_number)
{
	unsigned int i;
	short unsigned int flag;
	instruction_t ops[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap}.
		{"add", op_add},
		{"nop", op_nop},
		{NULL, NULL}.
	}

	flag = 0;
	i = 0;
	while (ops[i].opcode != NULL)
	{
		if (strcmp(s, ops[i].opcode) == 0)
		{
			flag = 1;
			return (ops[i].f);
		}
		i++;
	}
	if (flag == 0 && *s != "\n") /* no matching opcode & not an empty line
				      * in other words, not valid opcode
				      */
		return (NULL);
}
