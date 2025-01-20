#include "push_swap.h"

int main(int ac, char **av)
{
    char    **chunks;
    t_stack *stackA;
    //t_stack *stackB;

    chunks = NULL;
    if (ac < 2)
        return (0);
    if (!check_input(ac, av, &chunks))
        exit_error(NULL, NULL);
    if (chunks != NULL)
    {
        stackA = fill_stack(chunks);
        free_splited(chunks);
    }
    else
        stackA = fill_stack(av + 1);
    printf("Stack A:\n");
    while (stackA)
    {
        printf("%d\n", stackA->data);
        stackA = stackA->next;
    }
    return (0);
}
