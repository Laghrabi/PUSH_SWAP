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
    int index;
    int position;
    int below_line;
    struct t_stack *next;
} t_stack;

/* FUNCTIONS */
void    into_stackB_500(t_stack **stackA, t_stack **stackB);
void    sort_stackB(t_stack **stackA, t_stack **stackB);
void    put_on_top(t_stack **stackA, t_stack **stackB, int b_size);
t_stack *greater_index(t_stack *stackB, int b_size);
void    bettom_or_top(t_stack *stackB);
void    set_position_stackB(t_stack *stackB);
void    into_stackB_100(t_stack **stackA, t_stack **stackB);
void    set_index_stackA(t_stack *stackA, int *arr, int size);
void    bubble_sort(int *arr, int size);
int *allocate_array(t_stack *stackA, int size);
void    push_min_to_b(t_stack **stackA, t_stack **stackB, int min_pos);
t_stack *only_4(t_stack **stackA, t_stack **stackB);
t_stack *algo(t_stack *stackA, t_stack *stackB, int size);
t_stack *only_3(t_stack **stackA, t_stack **stackB);
int find_position(t_stack *stack);
int	ft_lstsize(t_stack *stack);
void print_stack(t_stack *stack, char *name);
void    rrr(t_stack **stackA, t_stack **stackB);
void    rrb(t_stack **stackB);
void    rra(t_stack **stackA);
void    rr(t_stack **stackA, t_stack **stackB);
void    rb(t_stack **stackB);
void    ra(t_stack **stackA);
void    pb(t_stack **stackA, t_stack **stackB);
void    pa(t_stack **stackA, t_stack **stackB);
void	ft_lstadd_front(t_stack **stack, t_stack *new);
int is_dup(char **av);
char	*join(char *s1, char *s2);
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