/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 00:44:13 by claghrab          #+#    #+#             */
/*   Updated: 2025/01/27 20:01:25 by claghrab         ###   ########.fr       */
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

void    bettom_or_top(t_stack *stackB)
{
    int b_size;
    
    if (stackB == NULL)
        return ;
    b_size = ft_lstsize(stackB);
    while (stackB)
    {
        if (stackB->position < (b_size / 2))
            stackB->below_line = 0;
        else
            stackB->below_line = 1;
        stackB = stackB->next;
    }
    
}

t_stack *greater_index(t_stack *stackB, int b_size)
{
    if (stackB == NULL)
        return (NULL);
    while (stackB)
    {
        if (stackB->index == (b_size - 1))
            return (stackB);
        stackB = stackB->next;
    }
    return (NULL);
}

