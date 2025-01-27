#include "push_swap.h"

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

void	ft_lstadd_front(t_stack **stack, t_stack *new)
{
	if (!stack || !new)
		return ;
	new->next = *stack;
	*stack = new;
}

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
