/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:14:51 by claghrab          #+#    #+#             */
/*   Updated: 2025/01/31 10:17:21 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/**
 * is_sign - Checks if a character is a sign ('+' or '-').
 * @c: Character to check.
 *
 * Return: 1 if the character is a sign, 0 otherwise.
 */

int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

/**
 * is_digit - Checks if a character is a digit ('0' to '9').
 * @c: Character to check.
 *
 * Return: 1 if the character is a digit, 0 otherwise.
 */

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * clean_stack - Frees all nodes in a stack.
 * @stack: Double pointer to the stack to clean.
 *
 * Frees each node and sets the stack pointer to NULL.
 */

void	clean_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

/**
 * free_splited - Frees a null-terminated array of strings.
 * @splited: Array of strings to free.
 *
 * Frees each string and the array itself.
 */

void	free_splited(char **splited)
{
	unsigned int	i;

	i = 0;
	if (!splited)
		return ;
	while (splited[i])
	{
		free(splited[i]);
		i++;
	}
	free(splited);
}
