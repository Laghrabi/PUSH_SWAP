#include "push_swap.h"

void    ra(t_stack **stackA)
{
    t_stack *tmp;
    t_stack *last;

    if (!stackA || !(*stackA) || !(*stackA)->next)
        return ;
    tmp = (*stackA)->next;
    last = ft_lstlast(*stackA);
    last->next = *stackA;
    (*stackA)->next = NULL;
    *stackA = tmp;
    write(1, "ra\n", 3);
}

void    rb(t_stack **stackB)
{
    t_stack *tmp;
    t_stack *last;

    if (!stackB || !(*stackB) || !(*stackB)->next)
        return ;
    tmp = (*stackB)->next;
    last = ft_lstlast(*stackB);
    last->next = *stackB;
    (*stackB)->next = NULL;
    *stackB = tmp;
    write(1, "rb\n", 3);
}

void    rr(t_stack **stackA, t_stack **stackB)
{
    ra(stackA);
    rb(stackB);
    write(1, "rr\n", 3);
}