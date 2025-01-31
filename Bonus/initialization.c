/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:36:19 by claghrab          #+#    #+#             */
/*   Updated: 2025/01/31 11:36:21 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/**
 * fill_stack - Fills a stack with integers from a string array.
 * @av: Array of strings representing integers.
 *
 * Converts each string to an integer, validates the range, and adds
 * it to a dynamically allocated linked list (stack). Exits on errors.
 *
 * Return: Pointer to the head of the created stack.
 */

t_stack	*fill_stack(char **av)
{
	ssize_t	nbr;
	t_stack	*stack;
	t_stack	*new_node;
	int		i;

	i = 0;
	nbr = 0;
	stack = NULL;
	while (av[i])
	{
		nbr = ft_atoi(av[i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
			exit_error(&stack, NULL);
		new_node = ft_lstnew((int)nbr);
		if (!new_node)
			exit_error(&stack, NULL);
		ft_lstadd_back(&stack, new_node);
		i++;
	}
	return (stack);
}
