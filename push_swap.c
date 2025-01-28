#include "push_swap.h"

// void    into_stackB_100(t_stack **stackA, t_stack **stackB)
// {
//     int b_size;
//     t_stack *current;
    
//     if (stackA == NULL || stackB == NULL || *stackA == NULL)
//         return ;
//     current = *stackA;
//     while (current)
//     {
//         b_size = ft_lstsize(*stackB);
//         if (current->index < b_size)
//         {
//             pb(stackA, stackB);
//             rb(stackB);
//         }
//         else if (current->index < (b_size + 13))
//             pb(stackA, stackB);
//         else
//             ra(stackA);
//         current = *stackA;
//     }
// }

void    into_stackB(t_stack **stackA, t_stack **stackB, int size)
{
    int b_size;
    int chunk;
    t_stack *current;
    
    if (stackA == NULL || stackB == NULL || *stackA == NULL)
        return ;
    if (size == 100)
        chunk = 13;
    else
        chunk = 31;
    current = *stackA;
    while (current)
    {
        b_size = ft_lstsize(*stackB);
        if (current->index < b_size)
        {
            pb(stackA, stackB);
            rb(stackB);
        }
        else if (current->index < (b_size + chunk))
            pb(stackA, stackB);
        else
            ra(stackA);
        current = *stackA;
    }
}

void    put_on_top(t_stack **stackA, t_stack **stackB, int b_size)
{
    t_stack *node;
    
    if (stackA == NULL || stackB == NULL || *stackB == NULL)
        return ;
    node = greater_index(*stackB, b_size);
    if (node == NULL)
        return ;
    while (*stackB != node)
    {
        if (node->below_line == 0)
            rb(stackB);
        else
            rrb(stackB);
    }
    pa(stackA, stackB);
}

void    sort_stackB(t_stack **stackA, t_stack **stackB)
{
    int b_size;
    int i;
    
    if (stackA == NULL || stackB == NULL || *stackB == NULL)
        return ;
    i = ft_lstsize(*stackB);
    while (i > 1)
    {
        b_size = ft_lstsize(*stackB);
        set_position_stackB(*stackB);
        bottom_or_top(*stackB);
        put_on_top(stackA, stackB, b_size);
        i--;
    }
    if (i == 1)
        pa(stackA, stackB);
}
