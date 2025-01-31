/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:22:32 by claghrab          #+#    #+#             */
/*   Updated: 2025/01/31 16:06:51 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * into_stackB
	- Pushes elements from stackA to stackB in chunks based on their index.
 * @stackA: Double pointer to the head of stackA.
 * @stackB: Double pointer to the head of stackB.
 * @size: Size of stackA, used to determine the chunk size.
 *
 * Uses chunk-based logic to move elements from stackA to stackB:
 *
	- Elements with an index less than the current size of
	stackB are pushed to stackB,
 *   and the stackB is rotated.
 * - Elements within the current chunk range are pushed to stackB.
 * - Other elements are rotated in stackA to cycle through the list.
 * Helps prepare stackB for sorting by dividing stackA into manageable chunks.
 */

void	into_stackb(t_stack **stackA, t_stack **stackB, int size)
{
	int		b_size;
	int		chunk;
	t_stack	*current;

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

/**
 * put_on_top
	- Moves a specific node in stackB with the greatest index to the top.
 * @stackA: Double pointer to the head of stackA.
 * @stackB: Double pointer to the head of stackB.
 * @b_size: Size of stackB, used to find the node with the greatest index.
 *

 * Finds the node in stackB with the highest index using
 the greater_index function.
 * Rotates stackB to bring that node to the top:
 * - Rotates forward if the node is in the top half (below_line == 0).
 * - Rotates backward if the node is in the bottom half (below_line == 1).
 * Finally, pushes the node to stackA.
 */

void	put_on_top(t_stack **stackA, t_stack **stackB, int b_size)
{
	t_stack	*node;

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

/**
 * sort_stackB
	- Sorts stackB by moving elements back to stackA in descending order.
 * @stackA: Double pointer to the head of stackA.
 * @stackB: Double pointer to the head of stackB.
 *

	* Iteratively identifies the node with the greatest index in
	stackB and moves it
 * to stackA:
 * - Calculates the size of stackB.
 * - Updates positions and below_line flags for stackB.
 * - Uses put_on_top to bring the node with the greatest index to the top.
 * - Pushes the top node of stackB to stackA.
 * Continues until all nodes are moved from stackB to stackA.
 */

void	sort_stackb(t_stack **stackA, t_stack **stackB)
{
	int	b_size;
	int	i;

	if (stackA == NULL || stackB == NULL || *stackB == NULL)
		return ;
	i = ft_lstsize(*stackB);
	while (i > 1)
	{
		b_size = ft_lstsize(*stackB);
		set_position_stackb(*stackB);
		bottom_or_top(*stackB);
		put_on_top(stackA, stackB, b_size);
		i--;
	}
	if (i == 1)
		pa(stackA, stackB);
}

/**
 * sort_large_stack - Sorts a large stack using an index-based sorting approach.
 * @stackA: Double pointer to stackA.
 * @stackB: Double pointer to stackB (used as temporary storage).
 * @size: Number of elements in stackA.
 *
 * Steps:
 * 1. Allocates and sorts an array of stackA values.
 * 2. Assigns index values to stackA based on sorted order.
 * 3. Moves elements from stackA to stackB in chunks.

	* 4. Sets positions and determines whether elements are
	in the top or bottom half.
 * 5. Sorts stackB and moves elements back to stackA.
 *
 * Return: Pointer to the sorted stackA.
 */

t_stack	*sort_large_stack(t_stack **stackA, t_stack **stackB, int size)
{
	int	*arr;

	arr = allocate_array(*stackA, size);
	set_index_stacka(*stackA, arr, size);
	into_stackb(stackA, stackB, size);
	set_position_stackb(*stackB);
	bottom_or_top(*stackB);
	sort_stackb(stackA, stackB);
	free(arr);
	return (*stackA);
}
