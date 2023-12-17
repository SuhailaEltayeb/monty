#include "monty.h"

/* Function prototypes */
void run_Monty(FILE *file);
instruction_t *find_instruction(char *opcode);

/* Global stack variable */
stack_t *global_stack;

/**
 * run_Monty - function to rn monty interpreter
 * @file: file to be interpreted
 *
 * Return: Nothing
 */
void run_Monty(FILE *file)
{
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	char *opcode;

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		opcode = strtok(line, " \t\n");
		if (opcode != NULL)
		{
			instruction_t *instruction = find_instruction(opcode);

			if (instruction != NULL)
			{
				instruction->f(&global_stack, line_number);
			}
			else
			{
				handle_error(7, line_number);
			}
		}
	}
	free(line);
}

/**
 * find_instruction - function to read opcode instructions
 * @opcode: opcode of specific operation to be executed
 *
 * Return: num
 */
instruction_t *find_instruction(char *opcode)
{
	int i;
	instruction_t *found_instruction = NULL;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			/* Dynamically allocate memory for a copy of the structure */
			found_instruction = malloc(sizeof(instruction_t));
			if (found_instruction == NULL)
			{
				/* Handle allocation failure if needed */
				exit(EXIT_FAILURE);
			}
			/* Copy the content of the structure */
			*found_instruction = instructions[i];
			break;
		}
	}
	if (found_instruction == NULL)
	{
		free(found_instruction);
	}
	return (found_instruction);
}
