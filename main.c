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

void print_stack(t_stack *stack, char *name)
{
    printf("%s: ", name);
    while (stack)
    {
        printf("%d ", stack->data);
        stack = stack->next;
    }
    printf("\n");
}

int main(int ac, char **av)
{
    char    **chunks;
    t_stack *stackA;
    t_stack *stackB;
    int size;

    chunks = NULL;
    stackA = NULL;
    stackB = NULL;
    if (ac < 2)
        return (0);
    if (!if_only_space(ac, av))
        exit_error(NULL, NULL);
    if (!check_input(ac, av, &chunks))
        exit_error(NULL, NULL);
    stackA = fill_stack(chunks);
    free_splited(chunks);
    size = ft_lstsize(stackA);
    stackA = algo(stackA, stackB, size);
    clean_stack(&stackA);
    clean_stack(&stackB);
    return (0);
}
