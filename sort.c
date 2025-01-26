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

t_stack *only_3(t_stack **stackA, t_stack **stackB)
{
    int min_pos;

    min_pos = find_position(*stackA);
    if (*stackA == NULL)
        return (NULL);
    push_min_to_b(stackA, stackB, min_pos);
    if (*stackA && (*stackA)->next && (*stackA)->data > (*stackA)->next->data)
        sa(stackA);
    pa(stackA, stackB);
    return (*stackA);
}

t_stack *only_4(t_stack **stackA, t_stack **stackB)
{
    int min_pos;

    min_pos = find_position(*stackA);
    if (*stackA == NULL)
        return (NULL);
    push_min_to_b(stackA, stackB, min_pos);
    if (min_pos == 3)
    {
        rra(stackA);
        pb(stackA, stackB);
    }
    only_3(stackA, stackB);
    pa(stackA, stackB);
    return (*stackA);
}

t_stack *only_5(t_stack **stackA, t_stack **stackB)
{
    int min_pos;

    min_pos = find_position(*stackA);
    if (*stackA == NULL)
        return (NULL);
    push_min_to_b(stackA, stackB, min_pos);
    if (min_pos == 3)
    {
        rra(stackA);
        rra(stackA);
        pb(stackA, stackB);
    }
    if (min_pos == 4)
    {
        rra(stackA);
        pb(stackA, stackB);
    }
    only_4(stackA, stackB);
    pa(stackA, stackB);
    return (*stackA);
}

t_stack *algo(t_stack *stackA, t_stack *stackB, int size)
{
    if (stackA == NULL || size == 0)
        return (NULL);
    if (size <= 3)
        return (only_3(&stackA, &stackB));
    if (size <= 4)
        return (only_4(&stackA, &stackB));
    if (size <= 5)
        return (only_5(&stackA, &stackB));
    return (NULL); 
}