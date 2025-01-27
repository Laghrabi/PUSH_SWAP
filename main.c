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
    int i;
    char    **chunks;
    t_stack *stackA;
    //t_stack *stackB = NULL;
    int size;

    chunks = NULL;
    if (ac < 2)
        return (0);
    if (!check_input(ac, av, &chunks))
        exit_error(NULL, NULL);
    stackA = fill_stack(chunks);
    size = ft_lstsize(stackA);
    t_stack *cur = stackA;
    printf("Stack A before:\n");
    while (cur)
    {
        printf("[%d]\n", cur->data);
        cur = cur->next;
    }
    printf("Sorted array:\n");
    int *arr = allocate_array(stackA, size);
    i = 0;
    while (i < size)
    {
        printf("[%d] ", arr[i]);
        i++;
    }
    set_index_stackA(stackA, arr, size);
    printf("Stack A index:\n");
    cur = stackA;
    while (cur)
    {
        printf("[%d]\n", cur->index);
        cur = cur->next;
    }
    // stackA = algo(stackA, stackB, size);
    // cur = stackA;
    // printf("Stack A after:\n");
    // while (cur)
    // {
    //     printf("[%d]\n", cur->data);
    //     cur = cur->next;
    // }
    //t_stack *b = stackB;
    // printf("Stack B after:\n");
    // while (b)
    // {
    //     //printf("7\n");
    //     printf("[%d]\n", b->data);
    //     b = b->next;
    // }
    // printf("stack size: %d\n", size);
    // ra(&stackA);
    // printf("Stack A after:\n");
    // while (stackA)
    // {
    //     printf("[%d]\n", stackA->data);
    //     stackA = stackA->next;
    // }


    // print_stack(stackA, "Stack A");
    // print_stack(stackB, "Stack B");

    // sa(&stackA);
    // print_stack(stackA, "Stack A after sa");
    // print_stack(stackB, "Stack B after sa");


    // pb(&stackA, &stackB);
    // print_stack(stackA, "Stack A after pb");
    // print_stack(stackB, "Stack B after pb");

    // pa(&stackA, &stackB);
    // print_stack(stackA, "Stack A after pa");
    // print_stack(stackB, "Stack B after pa");

    // ra(&stackA);
    // print_stack(stackA, "Stack A after ra");

    // rra(&stackA);
    // print_stack(stackA, "Stack A after rra");

    
    // clean_stack(&stackA);
    // clean_stack(&stackB);
    return (0);
}
