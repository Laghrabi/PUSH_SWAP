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

/*FUNCTIONS PROTOTYPE*/

void    swap(t_stack *stack);
void    sa(t_stack **stackA);
void    sb(t_stack **stackB);
int     ft_atoi(const char *str);
void    ss(t_stack **stackA, t_stack **stackB);

#endif