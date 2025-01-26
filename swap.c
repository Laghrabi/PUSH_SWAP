/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:04:17 by claghrab          #+#    #+#             */
/*   Updated: 2025/01/26 16:57:35 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * swap - Swaps the top two elements of the stack.
 * 
 * This function swaps the first two elements of the stack. 
 * 
 * Return: Nothing. If the stack has fewer than two elements, no operation is performed.
 */
void    swap(t_stack *stack)
{
    int tmp;

    if (stack && stack->next)
    {
        // tmp = stack->next;
        // stack->next = tmp->next;
        // tmp->next = stack;
        tmp = stack->data;
        stack->data = stack->next->data;
        stack->next->data = tmp;
    }
}

/**
 * sa - Swaps the top two elements of stack A.
 * @stackA: A pointer to the top of stack A.
 * 
 * This function swaps the first two elements of the stack A. 
 * The function prints the operation ("sa\n") to standard output.
 * 
 * Return: Nothing. If the stack has fewer than two elements, no operation is performed.
 */
void    sa(t_stack **stackA)
{
    if (stackA && *stackA)
    {
        swap(*stackA);
        write(1, "sa\n", 3);
    }
}

/**
 * sb - Swaps the top two elements of stack B.
 * @stackB: A pointer to the top of stack B.
 *
 * This function swaps the first two elements of the stack B.
 * The function prints the operation ("sb\n") to standard output.
 * 
 * Return: Nothing. If the stack has fewer than two elements, no operation is performed.
 */
void    sb(t_stack **stackB)
{
    if (stackB && *stackB)
    {
        swap(*stackB);
        write(1, "sb\n", 3);
    }
}

/**
 * ss - Swaps the top two elements of stack A and B at the same time.
 * @stackA: A pointer to the top of stack A.
 * @stackB: A pointer to the top of stack B.
 *
 * This function swaps the first two elements of the stack A and B.
 * The function prints the operation ("ss\n") to standard output.
 * 
 * Return: Nothing. If the stacks have fewer than two elements, no operation is performed.
 */
void    ss(t_stack **stackA, t_stack **stackB)
{
    if (stackA && stackB && *stackA && *stackB)
    {
        swap(*stackA);
        swap(*stackB);
        write(1, "ss\n", 3);
    }
}
