#include "monty.h"

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
	return (0);
}

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

void close_file(FILE *file)
{
	fclose(file);
}

