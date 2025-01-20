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
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
t_stack *fill_stack(char **av);
int     is_sign(char c);
int     is_digit(char c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	**free_array(char **ptr, size_t i);
size_t	count(char const *s);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstnew(int content);
void    exit_error(t_stack **stackA, t_stack **stackB);
void    free_splited(char **splited);
char	**ft_split(char const *s);
int     check_input(int ac, char **av, char ***str);
void    clean_stack(t_stack **stack);
void    swap(t_stack *stack);
void    sa(t_stack **stackA);
void    sb(t_stack **stackB);
ssize_t     ft_atoi(const char *str);
void    ss(t_stack **stackA, t_stack **stackB);

#endif