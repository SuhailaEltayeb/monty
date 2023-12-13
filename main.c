#include "monty.h"

/**
 * main - entry point of the program
 * @argc: arguments count
 * @argv: arguments list
 *
 * Return: number of arguemnts
 */
int main(int argc, char *argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	File *file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file <file>\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	run_monty(file);
	fclose(file);
	return (0);
}
