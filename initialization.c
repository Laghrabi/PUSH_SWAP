#include <push_swap.h>

t_stack *fill_stack(int ac, char **av)
{
    int nbr;
    t_stack *stack;
    t_stack *new_node;
    unsigned int    i;

    i = 0;
    nbr = 0;
    stack = NULL;
    while (av[i])
    {
        nbr = ft_atoi(av[i]);
        new_node = ft_lstnew(nbr);
        if (!new_node)
            exit_error(&stack, NULL);
        ft_lstadd_back(&stack, ft_lstnew(nbr));
        i++;
    }
    return (stack);
}
