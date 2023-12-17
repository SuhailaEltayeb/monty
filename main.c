#include "monty.h"

/**
 * main - Entry point of the program
 * @argc: Arguments count
 * @argv: Arguments list
 *
 * Return: Number of arguments
 */
int main(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		handle_error(8, 0);
	}
	/* Run Monty interpreter with the provided file */
	run_Monty(file);

	fclose(file);
	return (0);
}
