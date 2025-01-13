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

int is_dup(int ac, char **av, int flag)
{
    int a;
    int b;
    unsigned int    j;
  
    while (av[flag])
    {
        a = ft_atoi(av[flag]);
        j = flag + 1;
        while (j < ac)
        {
            b = ft_atoi(av[j]);
            if (a == b)
                return (0);
            j++;
        }
        flag++;
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

int check_input(int ac, char **av, char ***str)
{
    int (i), (flag);

    flag = 1;
    if (ac == 2)
    {
        *str = ft_split(av[1], ' ', '\t');
        if (!(*str) || !(*str[0]))
            return (0);
        av = *str;
        flag = 0;
    }
    i = -1;
    while (av[flag + ++i])
    {
        if (!is_number(av[flag + i]))
            return (free_splited(*str), 0);
        if (!is_zero(av[flag + i]))
            return (free_splited(*str), 0);
    }
    if (!is_dup(ac, av, flag))
    {
        if (flag == 0)
            free_splited(*str);
        return (0);
    }
    return (1);
}
