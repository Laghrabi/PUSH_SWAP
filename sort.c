#include "push_swap.h"

int if_sorted(t_stack *stack)
{
    if (stack == NULL)
        return (1);
    while (stack->next != NULL)
    {
        if ( stack->data > stack->next->data)
            return (0);
        stack = stack->next;
    }
    return (1);
}

t_stack *only_3(t_stack **stackA, t_stack **stackB, int size)
{
    (void)size;
    (void)stackB;
    if (stackA == NULL || *stackA == NULL)
        return (NULL);
    if ((*stackA)->next->next != NULL)
    {
        if ((*stackA)->data > (*stackA)->next->data && (*stackA)->data > (*stackA)->next->next->data)
            ra(stackA);
        else if ((*stackA)->next->data > (*stackA)->data && (*stackA)->next->data > (*stackA)->next->next->data)
            rra(stackA);
    }
    if ((*stackA)->data > (*stackA)->next->data)
        sa(stackA);
    return (*stackA);
}

t_stack *only_4(t_stack **stackA, t_stack **stackB)
{
    int min_pos;

    if (stackA == NULL || *stackA == NULL)
        return (NULL);
    min_pos = find_position(*stackA);
    push_min_second_to_b(stackA, stackB, min_pos);
    only_3(stackA, stackB, 3);
    pa(stackA, stackB);
    return (*stackA);
}

t_stack *only_5(t_stack **stackA, t_stack **stackB)
{
    int min_pos;

    if (stackA == NULL || *stackA == NULL)
        return (NULL);
    min_pos = find_position(*stackA);
    push_min_to_b(stackA, stackB, min_pos);
    min_pos = find_position(*stackA);
    push_min_second_to_b(stackA, stackB, min_pos);
    only_3(stackA, stackB, 3);
    pa(stackA, stackB);
    pa(stackA, stackB);
    return (*stackA);
}

t_stack *algo(t_stack *stackA, t_stack *stackB, int size)
{
    int *arr;
    
    if (if_sorted(stackA) == 0)
    {
        if (stackA == NULL || size == 0)
            return (NULL);
        if (size == 1)
            return (NULL);
        if (size <= 3)
            return (only_3(&stackA, &stackB, size));
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
            bottom_or_top(stackB);
            sort_stackB(&stackA, &stackB);
        }
    }
    return (NULL); 
}
