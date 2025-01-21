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

// int check_input(int ac, char **av, char ***str)
// {
//     int (i), (flag);
//     flag = 1;
//     int j = 1;
//     int num;

//     num = 0;
//     while (av[j])
//         num += count(av[j++]);

//     while (j < ac)
//     {
//         *str = ft_split(av[j]);
//         if (!(*str) || !(*str[0]))
//             return (0);
//         av = *str;
//         //flag = 0;
//         j++;
//     }
//     i = 0;
//     while ((*str)[i])
//     {
//         if (!is_number((*str)[i]))
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

// char *spt(char **av)
// {
//     char *s;
//     int len;
//     static int i = 1;
//     static int j = 0;

//     len = 0;
//     while (av[i])
//     {
//         while (av[i][j] && av[i][j] == ' ')
//             j++;
//         while (av[i][j + len] && av[i][j + len] != ' ')
//             len++;
//         if (len != 0)
//         {
//             s = ft_substr(av[i], j, len);
//             j += len;
//             return (s);       
//         }
//         i++;
//         j = 0;
//     }
// }
