/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:50:14 by claghrab          #+#    #+#             */
/*   Updated: 2025/01/10 22:14:47 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int is_number(char *av)
{
    unsigned int    i;

    i = 0;
    if (is_sign(av[i]) && av[i + 1] != '\0')
        i++;
    while (av[i] && is_digit(av[i]))
        i++;
    if (av[i] && !is_digit(av[i]))
        return (0);
    return (1);
}

int is_zero(char *av)
{
    unsigned int    i;
    
    if (is_sign(av[i]) && av[i + 1] != '\0')
        i++;
    while (av[i] && av[i] == '0')
        i++;
    if (av[i] != '\0')
        return (0);
    return (1);
}

int is_dup(int ac, char **av)
{
    int a;
    int b;
    unsigned int    i;
    unsigned int    j;

    i = 1;
    while (i < ac - 1)
    {
        a = ft_atoi(av[i]);
        j = i + 1;
        while (j < ac)
        {
            b = ft_atoi(av[j]);
            if (a == b)
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int check_input(int ac, char **av)
{
    unsigned int i;

    i = 1;
    while (av[i])
    {
        if (!is_number(av[i]))
            return (0);
        if (!is_zero(av[i]))
            return (0);
        i++;
    }
    
}