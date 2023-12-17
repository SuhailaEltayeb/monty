#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * is_integer - Checks if a string represents an integer.
 * @str: The string to check.
 * Return: True if the string is an integer, false otherwise.
 */
bool is_integer(const char *str)
{
    if (str == NULL || *str == '\0')
        return false;

    while (*str)
    {
        if (!isdigit(*str))
            return false;
        str++;
    }

    return true;
}

/**
 * push - Pushes an element to the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the Monty bytecode file.
 */
void push(stack_t **stack, unsigned int line_number)
{
    char *token;
    int value;
    stack_t *new_node;

    /* Get the next token */
    token = strtok(NULL, " \t\n");

    /* Check if the token is missing or not an integer */
    if (!token || !is_integer(token))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Convert token to integer */
    value = atoi(token);

    /* Create a new node */
    new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    /* Set the value of the new node */
    new_node->n = value;

    /* Set the next of the new node to the current top of the stack */
    new_node->next = *stack;

    /* Set the stack to the new node, making it the new top */
    *stack = new_node;
}

/**
 * pall - Prints all the values on the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the Monty bytecode file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

/**
 * pint - Prints the value at the top of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the Monty bytecode file.
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        handle_error(2, line_number);
    }

    printf("%d\n", (*stack)->n);
}

/**
 * pop - Removes the top element of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the Monty bytecode file.
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL)
    {
        handle_error(3, line_number);
    }

    temp = *stack;
    *stack = (*stack)->next;
    free(temp);
}

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the Monty bytecode file.
 */
void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        handle_error(4, line_number);
    }

    temp = (*stack)->next;
    (*stack)->next = temp->next;
    temp->next = *stack;
    *stack = temp;
}

/**
 * add - Adds the top two elements of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the Monty bytecode file.
 */
void add(stack_t **stack, unsigned int line_number)
{
    int sum;
    stack_t *temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        handle_error(5, line_number);
    }

    sum = (*stack)->n + (*stack)->next->n;
    temp = *stack;
    *stack = (*stack)->next;
    free(temp);
    (*stack)->n = sum;
}

/**
 * nop - Does nothing.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the Monty bytecode file.
 */
void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}

