#include "push_swap.h"

void    rra(t_stack **stackA)
{
    t_stack *current;

    if (!stackA || !(*stackA) || !(*stackA)->next)
        return ;
    current = *stackA;
    while (current->next->next)
        current = current->next;
    ft_lstadd_front(stackA, current->next);
    current->next = NULL;
    write(1, "rra\n", 4);
}

void    rrb(t_stack **stackB)
{
    t_stack *current;

    if (!stackB || !(*stackB) || !(*stackB)->next)
        return ;
    current = *stackB;
    while (current->next->next)
        current = current->next;
    ft_lstadd_front(stackB, current->next);
    current->next = NULL;
    write(1, "rrb\n", 4);
}

void    rrr(t_stack **stackA, t_stack **stackB)
{
    rra(stackA);
    rrb(stackB);
    write(1, "rrr\n", 4);
}