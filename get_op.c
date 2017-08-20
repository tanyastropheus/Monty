#include "monty.h"
/**
 * get_op - selecting appropriate function based on the input opcode
 * @s: pointer to the op_code string
 * Return: a pointer to the operator function that corresponds to the opcode
 */

void (*get_op(char *s))(stack_t **stack, unsigned int line_number)
{
	unsigned int i;
	instruction_t ops[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"mod", op_mod},
		{NULL, NULL},
	};

	i = 0;
	while (ops[i].opcode != NULL)
	{
		if (strcmp(s, ops[i].opcode) == 0)
			return (ops[i].f);
		i++;
	}

	return (NULL);
}
