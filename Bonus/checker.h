/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:38:47 by claghrab          #+#    #+#             */
/*   Updated: 2025/01/31 10:38:50 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

/* INCLUDES */
# include "gnl/get_next_line.h"
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

/* FUNCTIONS */
void				write_and_exit(void);
void				ss(t_stack **stackA, t_stack **stackB);
void				sb(t_stack **stackB);
void				sa(t_stack **stackA);
void				swap(t_stack *stack);
int					ft_lstsize(t_stack *stack);
void				ft_lstadd_front(t_stack **stack, t_stack *new);
void				ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack				*ft_lstlast(t_stack *lst);
t_stack				*ft_lstnew(int content);
void				rr(t_stack **stackA, t_stack **stackB);
void				rb(t_stack **stackB);
void				ra(t_stack **stackA);
void				rrr(t_stack **stackA, t_stack **stackB);
void				rrb(t_stack **stackB);
void				rra(t_stack **stackA);
void				pb(t_stack **stackA, t_stack **stackB);
void				pa(t_stack **stackA, t_stack **stackB);
char				**ft_split(char *s);
char				*ft_substr(char *s, int start, size_t len);
char				*ft_strdup(char *str);
//size_t ft_strlen(const char *str);
ssize_t				ft_atoi(const char *str);
char				**free_array(char **ptr, size_t i);
size_t				count(char const *s);
t_stack				*fill_stack(char **av);
void				free_splited(char **splited);
void				clean_stack(t_stack **stack);
int					is_digit(char c);
int					is_sign(char c);
int					check_input(int ac, char **av, char ***str);
char				*join(char *s1, char *s2);
void				exit_error(t_stack **stackA, t_stack **stackB);
int					is_dup(char **av);
int					is_number(char *av);
int					if_only_space(int ac, char **av);
int					if_sorted(t_stack *stack);

#endif
