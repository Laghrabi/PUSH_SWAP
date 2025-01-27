#include "push_swap.h"

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
    int *arr;

    if (stackA == NULL || size == 0)
        return (NULL);
    if (size <= 3)
        return (only_3(&stackA, &stackB));
    else if (size <= 4)
        return (only_4(&stackA, &stackB));
    else if (size <= 5)
        return (only_5(&stackA, &stackB));
    else
    {
        arr = allocate_array(stackA, size);
        set_index_stackA(stackA, arr, size);
        into_stackB(&stackA, &stackB, size);
        set_position_stackB(stackB);
        bettom_or_top(stackB);
        sort_stackB(&stackA, &stackB);
    }
    return (NULL); 
}
