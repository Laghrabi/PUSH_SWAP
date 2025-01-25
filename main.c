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
    t_stack *stackB = NULL;

    chunks = NULL;
    if (ac < 2)
        return (0);
    if (!check_input(ac, av, &chunks))
        exit_error(NULL, NULL);
    stackA = fill_stack(chunks);
    // printf("Stack A before:\n");
    // while (stackA)
    // {
    //     printf("[%d]\n", stackA->data);
    //     stackA = stackA->next;
    // }
    // ra(&stackA);
    // printf("Stack A after:\n");
    // while (stackA)
    // {
    //     printf("[%d]\n", stackA->data);
    //     stackA = stackA->next;
    // }
    // Step 2: Print initial stacks
    print_stack(stackA, "Stack A");
    print_stack(stackB, "Stack B");

    // Step 3: Test operations
    pb(&stackA, &stackB); // Move top of A to B
    print_stack(stackA, "Stack A after pb");
    print_stack(stackB, "Stack B after pb");

    pa(&stackA, &stackB); // Move top of B back to A
    print_stack(stackA, "Stack A after pa");
    print_stack(stackB, "Stack B after pa");

    ra(&stackA); // Rotate A
    print_stack(stackA, "Stack A after ra");

    rra(&stackA); // Reverse Rotate A
    print_stack(stackA, "Stack A after rra");

    // Additional tests for your functions...
    
    // Clean up stacks
    clean_stack(&stackA);
    clean_stack(&stackB);
    return (0);
}
