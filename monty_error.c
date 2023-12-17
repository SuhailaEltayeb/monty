#include "monty.h"

/**
 * handle_error - Handles and prints errors.
 * @error_code: Error code
 * @line_number: Line number in the file
 */
void handle_error(int error_code, unsigned int line_number)
{
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			break;
		case 2:
			fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
			break;
		case 3:
			fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
			break;
		case 4:
			fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
			break;
		case 5:
			fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
			break;
		case 6:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 7:
			fprintf(stderr, "L%u: unknown instruction\n", line_number);
			break;
		case 8:
			fprintf(stderr, "Error: Can't open file\n");
			break;
		default:
			fprintf(stderr, "Unknown error at line %u\n", line_number);
	}
	exit(EXIT_FAILURE);
}
