#include "push_swap.h"

int is_sign(char c)
{
    return (c == '+' || c == '-');
}

int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

int is_number(char *av)
{
    unsigned int    i;

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

int is_dup(int ac, char **av)
{
    (void)ac;
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

void    exit_error(t_stack **stackA, t_stack **stackB)
{
    if (!stackA || *stackA)
        clean_stack(stackA);
    if (!stackB || *stackB)
        clean_stack(stackB);
    write(2, "Error\n", 6);
    exit (1);
}

// int check_input(int ac, char **av, char ***str)
// {
//     int (i), (flag);
//     flag = 1;
//     if (ac == 2)
//     {
//         *str = ft_split(av[1]);
//         if (!(*str) || !(*str[0]))
//             return (0);
//         av = *str;
//         flag = 0;
//     }
//     i = -1;
//     while (av[flag + ++i])
//     {
//         if (!is_number(av[flag + i]))
//         {
//             if (flag == 0)
//                 free_splited(*str);
//             return (0);
//         }
//     }
//     if (!is_dup(ac, av, flag))
//     {
//         if (flag == 0)
//             free_splited(*str);
//         return (0);
//     }
//     return (1);
// }

char	*join(char *s1, char *s2)
{
	char	*new;

	int (i), (j);
	i = 0;
	j = 0;
	if (!s1)
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
    if (!(*str) || !(*str[0]))
        return (0);
    i = 0;
    while ((*str)[i])
    {
        if (!is_number((*str)[i]))
        {
            free_splited(*str);
            return (0);
        }
        i++;
    }
    if (!is_dup(ac, *str))
    {
        free_splited(*str);
        return (0);
    }
    return (1);
}

