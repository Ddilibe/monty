#include "monty.h"

/**
 * main - Run the code
 * @argv: Number of arguments
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
		printf("%s\n", argv[1]);
		t = file_extension(argv[1]);
		printf("%s\n", argv[1]);
		if (t == 1)
		{
			printf("Starting open the file\n %s\n", argv[1]);
			file = open_file( argv[1]);
			if (file != NULL)
			{
				print_out(file);
				close_file(file);
				printf("Now Closing\n");
				return (0);
			}
		}
		else
			printf("USAGE: monty file\n");
	}
	else 
		printf("USAGE: monty file\n");
	return 0;
}
