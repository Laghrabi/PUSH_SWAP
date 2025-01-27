#include "push_swap.h"

int find_position(t_stack *stack)
{
    t_stack *current;
    int min;
    int min_pos;
    int current_pos;


    if (stack == NULL)
        return (-1);
    current = stack;
    min = current->data;
    min_pos = 0;
    current_pos = 0;
    while(current != NULL)
    {
        if (current->data < min)
        {
            min = current->data;
            min_pos = current_pos;
        }
        current = current->next;
        current_pos++;
    }
    return (min_pos);
}

void    push_min_to_b(t_stack **stackA, t_stack **stackB, int min_pos)
{
    if(min_pos == 0)
        pb(stackA, stackB);
    else if (min_pos == 1)
    {
        sa(stackA);
        pb(stackA, stackB);
    }
    else if (min_pos == 2)
    {
        ra(stackA);
        ra(stackA);
        pb(stackA, stackB);
    }
}
