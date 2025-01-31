/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:24:00 by claghrab          #+#    #+#             */
/*   Updated: 2025/01/31 10:17:57 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/**
 * pa - Moves the top element from stackB to stackA.
 * @stackA: Double pointer to stackA.
 * @stackB: Double pointer to stackB.
 *
 * If stackB is not empty,
	moves the top element from stackB to stackA and prints "pa".
 */

void	pa(t_stack **stackA, t_stack **stackB)
{
	t_stack	*tmp;

	if (!stackB || !(*stackB))
		return ;
	tmp = *stackB;
	*stackB = (*stackB)->next;
	tmp->next = *stackA;
	*stackA = tmp;
}

/**
 * pb - Moves the top element from stackA to stackB.
 * @stackA: Double pointer to stackA.
 * @stackB: Double pointer to stackB.
 *
 * If stackA is not empty,
	moves the top element from stackA to stackB and prints "pb".
 */

void	pb(t_stack **stackA, t_stack **stackB)
{
	t_stack	*tmp;

	if (!stackA || !(*stackA))
		return ;
	tmp = *stackA;
	*stackA = (*stackA)->next;
	tmp->next = *stackB;
	*stackB = tmp;
}
