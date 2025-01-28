/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:36:47 by claghrab          #+#    #+#             */
/*   Updated: 2025/01/28 19:39:00 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * if_sorted - Checks if a stack is sorted in ascending order.
 * @stack: Pointer to the stack to check.
 *
 * Returns 1 if sorted or empty, 0 otherwise.
 */

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

/**
 * only_3 - Sorts a stack with up to 3 elements.
 * @stackA: Double pointer to stackA.
 * @stackB: Double pointer to stackB (unused).
 * @size: Size of stackA (unused).
 *
 * Sorts stackA if it contains up to 3 elements. Returns the sorted stackA.
 */

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

/**
 * only_4 - Sorts a stack with 4 elements.
 * @stackA: Double pointer to stackA.
 * @stackB: Double pointer to stackB (used as temporary storage).
 *
 * Sorts stackA by moving the smallest element to stackB, sorting the remaining 3 elements,
 * and moving the smallest element back. Returns the sorted stackA.
 */

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

/**
 * only_5 - Sorts a stack with 5 elements.
 * @stackA: Double pointer to stackA.
 * @stackB: Double pointer to stackB (used as temporary storage).
 *
 * Sorts stackA by moving the two smallest elements to stackB, sorting the remaining 3 elements,
 * and moving the smallest elements back. Returns the sorted stackA.
 */

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

/**
 * algo - Executes the sorting algorithm for a stack of any size.
 * @stackA: Pointer to the initial stackA.
 * @stackB: Pointer to the initial stackB.
 * @size: Number of elements in stackA.
 *
 * Depending on size, sorts stackA using specialized functions (for sizes <= 5)
 * or a more complex algorithm (for larger sizes). Returns the sorted stackA or NULL.
 */

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
