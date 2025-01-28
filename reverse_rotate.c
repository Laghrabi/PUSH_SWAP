/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:25:59 by claghrab          #+#    #+#             */
/*   Updated: 2025/01/28 19:26:03 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * rra - Rotates stackA in reverse (moves the last element to the front).
 * @stackA: Double pointer to stackA.
 *
 * If stackA has more than one element, rotates stackA in reverse and prints "rra".
 */

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

/**
 * rrb - Rotates stackB in reverse (moves the last element to the front).
 * @stackB: Double pointer to stackB.
 *
 * If stackB has more than one element, rotates stackB in reverse and prints "rrb".
 */

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

/**
 * rrr - Rotates both stackA and stackB in reverse.
 * @stackA: Double pointer to stackA.
 * @stackB: Double pointer to stackB.
 *
 * Rotates both stackA and stackB in reverse and prints "rrr".
 */

void    rrr(t_stack **stackA, t_stack **stackB)
{
    rra(stackA);
    rrb(stackB);
    write(1, "rrr\n", 4);
}
