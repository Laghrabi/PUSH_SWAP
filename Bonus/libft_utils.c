/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:36:06 by claghrab          #+#    #+#             */
/*   Updated: 2025/01/31 11:36:11 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/**
 * count - Counts the number of words in a string.
 * @s: The string to process.
 *
 * Words are sequences of non-space and non-tab characters. Delimiters
 * are spaces (' ') or tabs ('\t'). Counts transitions into words.
 *
 * Return: The number of words in the string.
 */

size_t	count(char const *s)
{
	size_t	i;
	size_t	count;
	int		word;

	i = 0;
	word = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t')
			word = 0;
		if (s[i] != ' ' && s[i] != '\t' && word == 0)
		{
			count++;
			word = 1;
		}
		i++;
	}
	return (count);
}

/**
 * free_array - Frees a dynamically allocated array of strings.
 * @ptr: The array to free.
 * @i: The number of strings to free.
 *
 * Frees each string in the array and the array itself,
	ensuring no memory leaks.
 *
 * Return: Always returns NULL.
 */

char	**free_array(char **ptr, size_t i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return (NULL);
}
