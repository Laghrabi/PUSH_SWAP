/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:41:12 by claghrab          #+#    #+#             */
/*   Updated: 2025/01/31 11:30:08 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * find_position - Finds the position of the smallest value in the stack.
 * @stack: Pointer to the first node of the stack.
 *

	* Traverses the stack to find the smallest value and returns
	its position (0-indexed).
 * Returns -1 if the stack is NULL.
 */

int	find_position(t_stack *stack)
{
	t_stack	*current;
	int		min;
	int		min_pos;
	int		current_pos;

	if (stack == NULL)
		return (-1);
	current = stack;
	min = current->data;
	min_pos = 0;
	current_pos = 0;
	while (current != NULL)
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

/**
 * push_min_to_b - Moves the smallest element from stackA to stackB.
 * @stackA: Double pointer to the first node of stackA.
 * @stackB: Double pointer to the first node of stackB.
 * @min_pos: Position of the smallest element in stackA.
 *
 * Depending on the position of the smallest element (`min_pos`),
	performs appropriate rotations 
 * or swaps on stackA to bring the smallest element to the top,
	then pushes it to stackB.
 */

void	push_min_to_b(t_stack **stackA, t_stack **stackB, int min_pos)
{
	if (min_pos == 0)
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
	else if (min_pos == 3)
	{
		rra(stackA);
		rra(stackA);
		pb(stackA, stackB);
	}
	else if (min_pos == 4)
	{
		rra(stackA);
		pb(stackA, stackB);
	}
}

/**
 * push_min_second_to_b
	- Moves the second smallest element from stackA to stackB.
 * @stackA: Double pointer to the first node of stackA.
 * @stackB: Double pointer to the first node of stackB.
 * @min_pos: Position of the second smallest element in stackA.
 *
 * Similar to `push_min_to_b`,
	performs necessary rotations or swaps on stackA to bring the 
 * second smallest element to the top, then pushes it to stackB.
 */

void	push_min_second_to_b(t_stack **stackA, t_stack **stackB, int min_pos)
{
	if (min_pos == 0)
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
	else if (min_pos == 3)
	{
		rra(stackA);
		pb(stackA, stackB);
	}
}

/**
 * if_only_space - Checks if all arguments contain only spaces.
 * @ac: Argument count.
 * @av: Argument vector (array of strings).
 *
 * Iterates through each argument and checks if it consists only of spaces.
 * If any argument contains only spaces, returns 0; otherwise, returns 1.
 *
 * Return: 0 if any argument is empty or contains only spaces, 1 otherwise.
 */

int	if_only_space(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] && av[i][j] == ' ')
			j++;
		if (av[i][j] == '\0')
			return (0);
		i++;
	}
	return (1);
}
