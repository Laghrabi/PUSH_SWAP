#include "push_swap.h"

void    pa(t_stack **stackA, t_stack **stackB)
{
    t_stack *tmp;

    if (!stackB || !(*stackB))
        return ;
    tmp = *stackB;
    *stackB = (*stackB)->next;
    tmp->next = *stackA;
    *stackA = tmp;
    write(1, "pa\n", 3);
}

void    pb(t_stack **stackA, t_stack **stackB)
{
    t_stack *tmp;

    if (!stackA || !(*stackA))
        return ;
    tmp = *stackA;
    *stackA = (*stackA)->next;
    tmp->next = *stackB;
    *stackB = tmp;
    write(1, "pb\n", 3);
}