#include "push_swap.h"

t_stack *fill_stack(char **av)
{
    ssize_t nbr;
    t_stack *stack;
    t_stack *new_node;
    int    i;

    i = 0;
    nbr = 0;
    stack = NULL;
    while (av[i])
    {
        nbr = ft_atoi(av[i]);
        if (nbr < INT_MIN || nbr > INT_MAX)
            exit_error(&stack, NULL);
        new_node = ft_lstnew((int)nbr);
        if (!new_node)
            exit_error(&stack, NULL);
        ft_lstadd_back(&stack, ft_lstnew((int)nbr));
        i++;
    }
    return (stack);
}
