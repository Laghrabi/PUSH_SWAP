#include <push_swap.h>

static size_t	count(char const *s, char c, char a)
{
	size_t	i;
	size_t	count;
	int		word;

	i = 0;
	word = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c || s[i] == a)
			word = 0;
		if (s[i] != c && s[i] != a && word == 0)
		{
			count++;
			word = 1;
		}
		i++;
	}
	return (count);
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

char	**ft_split(char const *s, char c, char a)
{
	char	**arr;

	int (flag1), (flag2), (i), (j);
	flag1 = 0;
	flag2 = 0;
	if (!s)
		return (NULL);
	arr = ft_calloc(sizeof(char *), (count(s, c, a) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while ((s[i] == c || s[i] == a) && s[i])
			flag1 = ++i;
		while (s[i] && s[i] != c && s[i] != a)
			flag2 = ++i;
		if (flag2 < flag1)
			break ;
		arr[j++] = ft_substr(s, flag1, (size_t)(flag2 - flag1));
		if (!arr[j - 1])
			return (free_array(arr, j));
	}
	return (arr);
}