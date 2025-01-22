#include "push_swap.h"

/**
 * main - Entry point of the program.
 * @ac: Argument count.
 * @av: Argument vector.
 *
 * Validates input, populates a stack with numbers, and prints the stack. 
 * Exits on invalid input or memory allocation errors.
 *
 * Return: 0 on success.
 */

int main(int ac, char **av)
{
    char    **chunks;
    t_stack *stackA;

    chunks = NULL;
    if (ac < 2)
        return (0);
    if (!check_input(ac, av, &chunks))
        exit_error(NULL, NULL);
    stackA = fill_stack(chunks);
    printf("Stack A:\n");
    while (stackA)
    {
        printf("[%d]\n", stackA->data);
        stackA = stackA->next;
    }
    return (0);
}
