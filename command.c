#include "monty.h"

instruction_t montycodes[] = {
	{"push", opcode_push},
	{"pall", opcode_print},
	{"pint", opcode_pint},
	{"pop", opcode_pop},
	{"swap", opcode_swap},
	{"nop", opcode_nop},
	{"add", opcode_add},
	{"sub", opcode_sub},
	{"div", opcode_div},
	{"mul", opcode_mul},
	{"mod", opcode_mod},
	{"rotl", opcode_rotl},
	{"rotr", opcode_rotr},
	{ NULL, NULL}
};


/**
 * command - Function to carry the command of a fileline
 * @head: pointer to the pointer to the head
 * @line: Line of the file read
 * @q: Line number for the file
 *
 * Return: No return
 */
void command(stack_t **head, char *line, unsigned int q)
{
	int i, w, cum, vgt, ent;
	char **check;

	check = malloc(sizeof(char));
	vgt = length_of_instr();
	w = string_tokenizer(line, check, " \n	");
	if (w < 10)
	{
		if (check[1])
			cum = atoi(check[1]);
		for (i = 0; i < vgt; i++)
		{
			ent = comment(check[0]);
			if (ent == 0)
			{
			if (montycodes[i].opcode == NULL)
			{
				printf("L%d: unknown instruction %s", q, check[0]);
				exit(EXIT_FAILURE);
			}
			if (strcmp(check[0], montycodes[i].opcode) == 0)
			{
				plain.e = cum;
				montycodes[i].f(head, q);
				break;
			}
			}
		}
	}
}


/**
 * length_of_instr - function to display length of structure
 *
 * Return: Length of structure
 */
int length_of_instr(void)
{
	int i = 1;

	instruction_t montycodes[] = {
		{"push", opcode_push},
		{"pall", opcode_print},
		{"pint", opcode_pint},
		{"pop", opcode_pop},
		{"swap", opcode_swap},
		{"nop", opcode_nop},
		{"add", opcode_add},
		{"sub", opcode_sub},
		{"div", opcode_div},
		{"mul", opcode_mul},
		{"mod", opcode_mod},
		{"rotl", opcode_rotl},
		{"rotr", opcode_rotr},
		{ NULL, NULL}
	};

	while (montycodes[i].opcode != NULL)
	{
		i++;
	}
	i++;
	return (i);
}
