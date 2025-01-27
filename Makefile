CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS =  error.c  error_utils.c  initialization.c  stack.c  swap.c  utils.c	main.c	libft.c	libft_utils.c	push.c	rotate.c	reverse_rotate.c	sort.c	bubble_sort.c	indexing.c	push_swap.c
AR = ar
ARFLAGS = rcs
NAME = pushswap.a
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $^

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.SECONDARY: $(OBJS) $(SRCS)