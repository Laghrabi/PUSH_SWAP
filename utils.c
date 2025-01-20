#include "push_swap.h"

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

ssize_t	ft_atoi(const char *str)
{
	int	i;
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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
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

char	*ft_substr(const char *s, unsigned int start, size_t len)
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

char	**ft_split(char const *s)
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
	return (arr);
}