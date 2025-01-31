/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 00:44:13 by claghrab          #+#    #+#             */
/*   Updated: 2025/01/31 11:15:46 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * set_index_stackA
	- Assigns an index to each node in stackA based on its value's
 *                    position in a sorted array.
 * @stackA: Pointer to the head of stackA.
 * @arr: Sorted array of integers representing the data in stackA.
 * @size: Size of the array and the stack.
 *
 * Iterates through stackA, finds each node's value in the sorted array,
 * and assigns the corresponding index to the node.
 * Useful for determining the relative order of elements in stackA.
 */

void	set_index_stacka(t_stack *stackA, int *arr, int size)
{
	int	i;

	if (stackA == NULL || size == 0)
		return ;
	while (stackA)
	{
		i = 0;
		while (i < size)
		{
			if (stackA->data == arr[i])
			{
				stackA->index = i;
				break ;
			}
			i++;
		}
		stackA = stackA->next;
	}
}

/**
 * set_position_stackB - Assigns a sequential position to each node in stackB.
 * @stackB: Pointer to the head of stackB.
 *
 * Traverses the stack and assigns the position of each node, starting from 0.
 * Helps identify the location of nodes for later operations.
 */

void	set_position_stackb(t_stack *stackB)
{
	int	pos;

	if (stackB == NULL)
		return ;
	pos = 0;
	while (stackB)
	{
		stackB->position = pos++;
		stackB = stackB->next;
	}
}

/**
 * bottom_or_top
	- Flags each node in the stack as being in the top or bottom half.
 * @stack: Pointer to the head of the stack.
 *
 * Calculates the size of the stack and iterates through its nodes.
 * Marks each node's `below_line` property:
 *  - 0 for nodes in the top half.
 *  - 1 for nodes in the bottom half.
 * Useful for determining optimal rotations during sorting.
 */

void	bottom_or_top(t_stack *stack)
{
	int	size;

	if (stack == NULL)
		return ;
	size = ft_lstsize(stack);
	while (stack)
	{
		if (stack->position < (size / 2))
			stack->below_line = 0;
		else
			stack->below_line = 1;
		stack = stack->next;
	}
}

/**
 * greater_index
	- Finds and returns the node with the highest index in the stack.
 * @stack: Pointer to the head of the stack.
 * @b_size: Size of stackB.
 *
 * Return: A pointer to the node with the highest index.
 *         NULL if no such node is found or if the stack is empty.
 *
 * Iterates through the stack, checking if a node's index equals b_size - 1
 * (the highest possible index). Returns the node when found.
 */

t_stack	*greater_index(t_stack *stack, int b_size)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->index == (b_size - 1))
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
