/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:35:07 by claghrab          #+#    #+#             */
/*   Updated: 2025/01/31 11:27:18 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * ra - Rotates stackA (moves the first element to the end).
 * @stackA: Double pointer to stackA.
 *
 * If stackA has more than one element, rotates stackA and prints "ra".
 */

void	ra(t_stack **stackA)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!stackA || !(*stackA) || !(*stackA)->next)
		return ;
	tmp = (*stackA)->next;
	last = ft_lstlast(*stackA);
	last->next = *stackA;
	(*stackA)->next = NULL;
	*stackA = tmp;
	write(1, "ra\n", 3);
}

/**
 * rb - Rotates stackB (moves the first element to the end).
 * @stackB: Double pointer to stackB.
 *
 * If stackB has more than one element, rotates stackB and prints "rb".
 */

void	rb(t_stack **stackB)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!stackB || !(*stackB) || !(*stackB)->next)
		return ;
	tmp = (*stackB)->next;
	last = ft_lstlast(*stackB);
	last->next = *stackB;
	(*stackB)->next = NULL;
	*stackB = tmp;
	write(1, "rb\n", 3);
}

/**
 * rr
	- Rotates both stackA and stackB (moves the first
	element of each to the end).
 * @stackA: Double pointer to stackA.
 * @stackB: Double pointer to stackB.
 *
 * Rotates both stackA and stackB simultaneously and prints "rr".
 */

void	rr(t_stack **stackA, t_stack **stackB)
{
	ra(stackA);
	rb(stackB);
	write(1, "rr\n", 3);
}
