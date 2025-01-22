#include "push_swap.h"

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
