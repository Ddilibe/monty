#include "monty.h"

/**
 * print_out - Function for reading the file
 * @file: Input for the file
 *
 * Return: No return
 */
void print_out(FILE *file)
{
	char *line, *check;
	int i = 1;
	unsigned int q = 1;
	stack_t *head;

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
		printf("%s\n", line);
		command(&head, line, q);
		check = fgets(line, MAX_LENGTH, file);
		q++;
	}
	free(line);
}

/**
 * get_array - Function to turn a line to an array
 * @c: Input string
 * @new_string: pointer to the pointer to the new string
 *
 * Return:  a poniter to a new string
 */
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
