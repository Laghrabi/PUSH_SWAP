/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:34:23 by claghrab          #+#    #+#             */
/*   Updated: 2025/01/31 11:35:58 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/**
 * ft_atoi - Converts a string to an integer.
 * @str: The string to convert.
 *
 * Handles optional leading whitespaces, an optional '+' or '-' sign,
 * and numeric characters. Returns the converted value as an ssize_t.
 *
 * Return: The converted integer value.
 */

ssize_t	ft_atoi(const char *str)
{
	int		i;
	ssize_t	sign;
	ssize_t	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] <= 13 && str[i] >= 9))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

/**
 * ft_strlen - Calculates the length of a string.
 * @str: The string to measure.
 *
 * Counts the number of characters until the null-terminator.
 *
 * Return: Length of the string.
 */

// size_t ft_strlen(const char *str)
// {
// 	size_t i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

/**
 * ft_strdup - Duplicates a string.
 * @str: The string to duplicate.
 *
 * Allocates memory for a new string and copies the content of the
 * given string into it.
 *
 * Return: Pointer to the newly allocated duplicate string or NULL on failure.
 */

char	*ft_strdup(char *str)
{
	size_t	i;
	char	*new;

	new = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

/**
 * ft_substr - Creates a substring from a given string.
 * @s: The original string.
 * @start: The starting index of the substring.
 * @len: The maximum length of the substring.
 *
 * Allocates memory for the substring and returns it. Handles cases where

	* the start index is beyond the string length or the length
	exceeds available characters.
 *
 * Return: The substring or NULL on failure.
 */

char	*ft_substr(char *s, int start, size_t len)
{
	size_t	sub_len;
	size_t	i;
	char	*sub;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	sub_len = ft_strlen(s + start);
	if (len > sub_len)
		len = sub_len;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

/**
 * ft_split - Splits a string into words using spaces or tabs as delimiters.
 * @s: The string to split.
 *
 * Allocates memory for an array of strings, where each string is a word.
 * Handles memory allocation errors by freeing partially allocated arrays.
 *
 * Return: Pointer to the array of strings or NULL on failure.
 */

char	**ft_split(char *s)
{
	char	**arr;

	int (flag1), (flag2), (i), (j);
	flag1 = 0;
	flag2 = 0;
	if (!s)
		return (NULL);
	arr = malloc(sizeof(char *) * (count(s) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while ((s[i] == ' ' || s[i] == '\t') && s[i])
			flag1 = ++i;
		while (s[i] && s[i] != ' ' && s[i] != '\t')
			flag2 = ++i;
		if (flag2 < flag1)
			break ;
		arr[j++] = ft_substr(s, flag1, (size_t)(flag2 - flag1));
		if (!arr[j - 1])
			return (free_array(arr, j));
	}
	return (arr[j] = NULL, arr);
}
