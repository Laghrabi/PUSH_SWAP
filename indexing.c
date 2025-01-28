/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 00:44:13 by claghrab          #+#    #+#             */
/*   Updated: 2025/01/28 15:23:24 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    set_index_stackA(t_stack *stackA, int *arr, int size)
{
    int i;

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

void    set_position_stackB(t_stack *stackB)
{
    int pos;
    
    if (stackB == NULL)
        return ;
    pos = 0;
    while (stackB)
    {
        stackB->position = pos++;
        stackB = stackB->next;
    }
}

void    bottom_or_top(t_stack *stack)
{
    int size;
    
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

t_stack *greater_index(t_stack *stack, int b_size)
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
