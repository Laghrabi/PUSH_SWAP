/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:35:09 by claghrab          #+#    #+#             */
/*   Updated: 2025/01/31 11:37:35 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/**
 * if_sorted - Checks if a stack is sorted in ascending order.
 * @stack: Pointer to the stack to check.
 *
 * Returns 1 if sorted or empty, 0 otherwise.
 */

int	if_sorted(t_stack *stack)
{
	if (stack == NULL)
		return (-1);
	while (stack->next != NULL)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
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
