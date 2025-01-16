#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*INCLUDES*/

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>

/*STRUCTURE*/

typedef struct t_stack {
    int data;
    struct t_stack *next;
} t_stack;

/* FUNCTIONS */
t_stack *fill_stack(int ac, char **av);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstnew(void *content);
void    exit_error(t_stack **stackA, t_stack **stackB);
void    free_splited(char **splited);
char	**ft_split(char const *s, char c, char a);
int     check_input(int ac, char **av, char ***str);
void    clean_stack(t_stack **stack);
void    swap(t_stack *stack);
void    sa(t_stack **stackA);
void    sb(t_stack **stackB);
int     ft_atoi(const char *str);
void    ss(t_stack **stackA, t_stack **stackB);

#endif