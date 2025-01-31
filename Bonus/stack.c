/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:39:49 by claghrab          #+#    #+#             */
/*   Updated: 2025/01/31 10:18:22 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/**
 * ft_lstnew - Creates a new stack node.
 * @content: The value to store in the new node.
 *
 * Allocates memory for a new stack node, sets its data to `content`,
	and initializes `next` to NULL.
 * Returns the new node or NULL if allocation fails.
 */

t_stack	*ft_lstnew(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = content;
	new->next = NULL;
	return (new);
}

/**
 * ft_lstlast - Finds the last node in a stack.
 * @lst: Pointer to the first node of the stack.
 *
 * Traverses the stack to find and return the last node.
 * Returns NULL if the stack is empty.
 */

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*current;

	if (!lst)
		return (NULL);
	current = lst;
	while (current->next)
		current = current->next;
	return (current);
}

/**
 * ft_lstadd_back - Adds a new node to the end of a stack.
 * @lst: Double pointer to the first node of the stack.
 * @new: Pointer to the node to add.
 *
 * Adds the `new` node to the end of the stack. If the stack is empty,
	`new` becomes the first node.
 */

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!lst || !new)
		return ;
	tmp = ft_lstlast(*lst);
	if (!tmp)
		*lst = new;
	else
		tmp->next = new;
}

/**
 * ft_lstadd_front - Adds a new node to the front of a stack.
 * @stack: Double pointer to the first node of the stack.
 * @new: Pointer to the node to add.
 *
 * Adds the `new` node to the beginning of the stack.
 */

void	ft_lstadd_front(t_stack **stack, t_stack *new)
{
	if (!stack || !new)
		return ;
	new->next = *stack;
	*stack = new;
}

/**
 * ft_lstsize - Calculates the size of a stack.
 * @stack: Pointer to the first node of the stack.
 *
 * Counts and returns the number of nodes in the stack.
 */

int	ft_lstsize(t_stack *stack)
{
	int		i;
	t_stack	*current;

	i = 0;
	current = stack;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}
