/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:19:33 by claghrab          #+#    #+#             */
/*   Updated: 2025/01/31 11:37:21 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * main - Entry point of the program.
 * @ac: Argument count.
 * @av: Argument vector.
 *
 * Validates input, populates a stack with numbers, and prints the stack. 
 * Exits on invalid input or memory allocation errors.
 *
 * Return: 0 on success.
 */

int	main(int ac, char **av)
{
	char	**chunks;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	chunks = NULL;
	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	if (!if_only_space(ac, av))
		exit_error(NULL, NULL);
	if (!check_input(ac, av, &chunks))
		exit_error(NULL, NULL);
	stack_a = fill_stack(chunks);
	free_splited(chunks);
	size = ft_lstsize(stack_a);
	stack_a = algo(stack_a, stack_b, size);
	clean_stack(&stack_a);
	clean_stack(&stack_b);
	return (0);
}
