#include "monty.h"

data_n plain;

/**
 * main - Run the code
 * @argc: Number of arguments
 * @argv: arguments passed
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int t;
	FILE *file;

	if (argc == 2)
	{
		t = file_extension(argv[1]);
		if (t == 1)
		{
			file = open_file(argv[1]);
			if (file != NULL)
			{
				print_out(file);
				close_file(file);
				exit(EXIT_SUCCESS);
			}
		}
		else
		{
			printf("USAGE: monty file\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
