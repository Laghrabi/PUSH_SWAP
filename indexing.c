/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 00:44:13 by claghrab          #+#    #+#             */
/*   Updated: 2025/01/27 01:01:16 by claghrab         ###   ########.fr       */
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
