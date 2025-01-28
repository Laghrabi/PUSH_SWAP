/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:20:01 by claghrab          #+#    #+#             */
/*   Updated: 2025/01/28 19:20:04 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * is_number - Checks if a string represents a valid number.
 * @av: The string to check.
 *
 * Considers optional leading signs ('+' or '-') followed by digits.
 * Returns 1 for valid numbers, 0 otherwise.
 *
 * Return: 1 if the string is a number, 0 otherwise.
 */

int is_number(char *av)
{
    int    i;

    if (!av)
        return 0;
    i = 0;
    if (is_sign(av[i]) && av[i + 1] != '\0')
        i++;
    while (av[i] && is_digit(av[i]))
        i++;
    if (av[i] && !is_digit(av[i]))
        return (0);
    return (1);
}

/**
 * is_dup - Checks for duplicate numbers in a string array.
 * @av: The array of strings to check.
 *
 * Converts each string to an integer and compares for duplicates.
 * Returns 1 if no duplicates are found, 0 otherwise.
 *
 * Return: 1 if no duplicates, 0 otherwise.
 */

int is_dup(char **av)
{
    int a;
    int b;
    int j;
    int i;
  

    if (!av || !(*av))
        return 0;
    i = 0;
    while (av[i])
    {
        a = ft_atoi(av[i]);
        j = i + 1;
        while (av[j])
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

/**
 * exit_error - Cleans up and exits with an error message.
 * @stackA: Pointer to the first stack to clean.
 * @stackB: Pointer to the second stack to clean.
 *
 * Frees both stacks (if not NULL), writes "Error\n" to stderr, and exits.
 *
 * Return: Does not return (exits program).
 */

void    exit_error(t_stack **stackA, t_stack **stackB)
{
    if (stackA != NULL && *stackA != NULL)
        clean_stack(stackA);
    if (stackB != NULL && *stackB != NULL)
        clean_stack(stackB);
    write(2, "Error\n", 6);
    exit (1);
}

/**
 * join - Concatenates two strings with a space in between.
 * @s1: The first string (can be NULL).
 * @s2: The second string.
 *
 * Allocates memory for the concatenated result. Frees the first string
 * (if not NULL) and appends the second string with a trailing space.
 *
 * Return: Pointer to the concatenated string or NULL on failure.
 */

char	*join(char *s1, char *s2)
{
	char	*new;

	int (i), (j);
	i = 0;
	j = 0;
    if (!s2[i]) 
        return (NULL);
	else if (!s1)
	{
		new = malloc(sizeof(char) * (ft_strlen(s2) + 2));
		if (!new)
			return (NULL);
		while (s2[j])
			new[i++] = s2[j++];
		return (new[i++] = ' ', new[i] = '\0', new);
	}
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!new)
		return (free(s1), NULL);
	while (s1[i])
		new[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new[j++] = s2[i++];
	new[j++] = ' ';
	return (new[j] = '\0', free(s1), new);
}

/**
 * check_input - Validates and processes program input.
 * @ac: Argument count.
 * @av: Argument vector (array of strings).
 * @str: Pointer to an array of strings (output).
 *
 * Joins all arguments into a single string, splits it into words,
 * validates each word as a number, and checks for duplicates. Frees
 * resources and returns 0 on error.
 *
 * Return: 1 if input is valid, 0 otherwise.
 */

int check_input(int ac, char **av, char ***str)
{
    int i;
    char *buffer = NULL;

    i = 1;
    while (i < ac)
    {
        buffer = join(buffer, av[i]);
        if (!buffer)
            return (0);
        i++;
    }
    *str = ft_split(buffer);
    free(buffer);
    if (!(*str) || !(*str[0]))
        return (0);
    i = 0;
    while ((*str)[i])
    {
        if (!is_number((*str)[i]))
            return (free_splited(*str), 0);
        i++;
    }
    if (!is_dup(*str))
        return (free_splited(*str), 0);
    return (1);
}
