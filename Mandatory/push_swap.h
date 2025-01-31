/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:29:17 by claghrab          #+#    #+#             */
/*   Updated: 2025/01/31 12:30:48 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* INCLUDES */
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* STRUCTURES */
typedef struct t_stack
{
	int				data;
	int				index;
	int				position;
	int				below_line;
	struct t_stack	*next;
}					t_stack;

/* UTILITY FUNCTIONS */
size_t				ft_strlen(const char *str);
ssize_t				ft_atoi(const char *str);
char				*ft_strdup(const char *str);
char				*ft_substr(const char *s, unsigned int start, size_t len);
char				**ft_split(char const *s);
char				*join(char *s1, char *s2);
void				free_splited(char **splited);
char				**free_array(char **ptr, size_t i);
size_t				count(char const *s);
void				exit_error(t_stack **stackA, t_stack **stackB);
void				clean_stack(t_stack **stack);

/* LINKED LIST OPERATIONS */
t_stack				*ft_lstnew(int content);
t_stack				*ft_lstlast(t_stack *lst);
void				ft_lstadd_back(t_stack **lst, t_stack *new);
void				ft_lstadd_front(t_stack **stack, t_stack *new);
int					ft_lstsize(t_stack *stack);

/* VALIDATION FUNCTIONS */
int					is_sign(char c);
int					is_digit(char c);
int					is_dup(char **av);
int					if_only_space(int ac, char **av);
int					check_input(int ac, char **av, char ***str);

/* STACK OPERATIONS */
void				sa(t_stack **stackA);
void				sb(t_stack **stackB);
void				ss(t_stack **stackA, t_stack **stackB);
void				pa(t_stack **stackA, t_stack **stackB);
void				pb(t_stack **stackA, t_stack **stackB);
void				ra(t_stack **stackA);
void				rb(t_stack **stackB);
void				rr(t_stack **stackA, t_stack **stackB);
void				rra(t_stack **stackA);
void				rrb(t_stack **stackB);
void				rrr(t_stack **stackA, t_stack **stackB);
void				swap(t_stack *stack);

/* SORTING UTILITIES */
t_stack				*fill_stack(char **av);
int					*allocate_array(t_stack *stackA, int size);
void				bubble_sort(int *arr, int size);
void				set_index_stacka(t_stack *stackA, int *arr, int size);
void				set_position_stackb(t_stack *stackB);
void				bottom_or_top(t_stack *stack);
t_stack				*greater_index(t_stack *stack, int b_size);
int					find_position(t_stack *stack);
void				push_min_to_b(t_stack **stackA, t_stack **stackB,
						int min_pos);
void				push_min_second_to_b(t_stack **stackA, t_stack **stackB,
						int min_pos);

/* SORTING FUNCTIONS */
t_stack				*only_3(t_stack **stackA, t_stack **stackB, int size);
t_stack				*only_4(t_stack **stackA, t_stack **stackB);
t_stack				*only_5(t_stack **stackA, t_stack **stackB);
void				into_stackb(t_stack **stackA, t_stack **stackB, int size);
void				sort_stackb(t_stack **stackA, t_stack **stackB);
t_stack				*algo(t_stack *stackA, t_stack *stackB, int size);

#endif