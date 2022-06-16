#include "monty.h"

/**
 * file_extension - Function to check for a file extension
 * @s: Input string to check
 *
 * Return: 1 if true 0 if false
 */
int file_extension(char *s)
{	
	char **ment;
	char *w;
	
	w = malloc(sizeof(char));
	if (w == NULL)
		return (0);
	strcpy(w, s);
	ment = malloc(sizeof(char));
	string_tokenizer(w, ment, ".");
	if (ment[1])
	{
		if (strcmp(ment[1], "m")== 0)
			return (1);
	}
	return (1);
}

/**
 * open_file - Function to open a file
 * @file: input to the file to be opened
 *
 * Return: content of file if true else close
 */
FILE *open_file(char *file)
{
	FILE *fd;
	fd = fopen(file, "r");

	if (fd == NULL)
        {
        	printf("Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

	return fd;
}

/**
 * close_file - Function to close file
 * @file: pointer to the file
 *
 * Return: No return
 */
void close_file(FILE *file)
{
	fclose(file);
}

