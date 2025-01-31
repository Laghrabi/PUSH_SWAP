/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 23:16:11 by claghrab          #+#    #+#             */
/*   Updated: 2025/01/28 19:19:02 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * allocate_array - Allocates and fills an array with stack data.
 * @stackA: Pointer to the stack containing data.
 * @size: Number of elements in the stack.
 *
 * Extracts data from the stack into an array, sorts it using bubble sort, 
 * and returns a pointer to the allocated array. Returns NULL on failure.
 *
 * Return: Pointer to the sorted array, or NULL on failure.
 */

int	*allocate_array(t_stack *stackA, int size)
{
	int	i;
	int	*arr;

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

/**
 * bubble_sort - Sorts an array of integers using bubble sort.
 * @arr: Pointer to the array to be sorted.
 * @size: Size of the array.
 *
 * Repeatedly compares adjacent elements and swaps them if out of order.
 */

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

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
