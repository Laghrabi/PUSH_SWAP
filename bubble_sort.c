/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 23:16:11 by claghrab          #+#    #+#             */
/*   Updated: 2025/01/27 00:21:38 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *allocate_array(t_stack *stackA, int size)
{
    int i;
    int *arr;
    
    if (stackA == NULL)
        return (NULL);
    arr = malloc(sizeof(int) * size);
    if (arr == NULL)
        return (NULL);
    i = 0;
    while (stackA)
    {
        arr[i++] = stackA->data;
        stackA = stackA->next;
    }
    bubble_sort(arr, size);
    return (arr);
}

void    bubble_sort(int *arr, int size)
{
    int i;
    int j;
    int tmp;
    
    i = 0;
    while (i < size - 1)
    {
        j = 0;
        while (j < size - i - 1)
        {
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
            j++;
        }
        i++;
    }
}
