#include "monty.h"


void print_out(FILE *file)
{
	char *line, *check;
	int i = 1;
	stack_t *head;
	
	input = 1;
	head = malloc(sizeof(stack_t));
	if (head == NULL)
		i = i * 0;
	head = NULL;
	line = malloc(sizeof(char));
	if ((line == NULL))
		printf("Did Not allocate\n");
       
	check = fgets(line, MAX_LENGTH,  file);

	while (check != NULL)
	{
		printf("%s %d\n", line, input);
		command(&head, line);
		check = fgets(line, MAX_LENGTH, file);
		input++;
	}
	free(line);
}

char *get_array(char *c, char **new_string )
{
	int count = 0;
	char *delimiters = " ";
	char *token = strtok(c, delimiters);

	while (token != NULL)
	{
		new_string[count] = token;
		count++;
		token = strtok(c, delimiters);
	}
	count--;
	for( ; count >= 0; count--)
		printf("%s\n", new_string[count]);
	return (*new_string);
}


