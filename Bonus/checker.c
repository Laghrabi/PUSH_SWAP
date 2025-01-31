/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 20:46:18 by claghrab          #+#    #+#             */
/*   Updated: 2025/01/31 10:41:02 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	if (!s1 || !s2)
	{
		return (-1);
	}
	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
}

void	write_and_exit(void)
{
	write(2, "Error\n", 6);
	exit(1337);
}

void	apply_operation(char *op, t_stack **stackA, t_stack **stackB)
{
	if (ft_strcmp(op, "sa\n") == 0)
		sa(stackA);
	else if (ft_strcmp(op, "sb\n") == 0)
		sb(stackB);
	else if (ft_strcmp(op, "ss\n") == 0)
		ss(stackA, stackB);
	else if (ft_strcmp(op, "pa\n") == 0)
		pa(stackA, stackB);
	else if (ft_strcmp(op, "pb\n") == 0)
		pb(stackA, stackB);
	else if (ft_strcmp(op, "ra\n") == 0)
		ra(stackA);
	else if (ft_strcmp(op, "rb\n") == 0)
		rb(stackB);
	else if (ft_strcmp(op, "rr\n") == 0)
		rr(stackA, stackB);
	else if (ft_strcmp(op, "rra\n") == 0)
		rra(stackA);
	else if (ft_strcmp(op, "rrb\n") == 0)
		rrb(stackB);
	else if (ft_strcmp(op, "rrr\n") == 0)
		rrr(stackA, stackB);
	else
		write_and_exit();
}

void	read_operations(t_stack **stackA, t_stack **stackB)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		apply_operation(line, stackA, stackB);
		free(line);
		line = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	char	**chunks;
	t_stack	*stack_a;
	t_stack	*stack_b;

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
	read_operations(&stack_a, &stack_b);
	if ((if_sorted(stack_a) == 1) && (ft_lstsize(stack_b) == 0))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	clean_stack(&stack_a);
	clean_stack(&stack_b);
	return (0);
}
