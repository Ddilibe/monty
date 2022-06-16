#include "monty.h"


instruction_t montycodes[] = {
	{"push", opcode_push},
	{"pall", opcode_print},
	{ NULL , NULL}
};


void command(stack_t **head, char *line)
{
	int i, w;
	unsigned int num = 10;
	char **check;

	check = malloc(sizeof(char));
	w = string_tokenizer(line, check, " \n");
	if (w < 10) 
	{
		printf("Passed step 1\n");
		if (check[1])
			num = atoi(check[1]);
		for (i = 0; i < 3; i++)
		{
			printf("Passed recursion step: %s  %s \n", check[0], montycodes[i].opcode);
			if (strcmp(check[0], montycodes[i].opcode) == 0)
			{
				printf("Passed correction step\n");
				montycodes[i].f(head, num);
				break;	
			}
		}
	}
}
