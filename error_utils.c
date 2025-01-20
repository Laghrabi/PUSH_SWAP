/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laghrabichaimaa <laghrabichaimaa@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:14:51 by claghrab          #+#    #+#             */
/*   Updated: 2025/01/17 17:31:24 by laghrabicha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int is_sign(char c)
// {
//     return (c == '+' || c == '-');
// }

// int is_digit(char c)
// {
//     return (c >= '0' && c <= 9);
// }

void    clean_stack(t_stack **stack)
{
    t_stack *tmp;

    if (!stack || !(*stack))
        return ;
    while (*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
    *stack = NULL;
}

void free_splited(char **splited)
{
    unsigned int i = 0;
    if (!splited)
        return;
    while (splited[i])
    {
        free(splited[i]);
        i++;
    }
    free(splited);
}
