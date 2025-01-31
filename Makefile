CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS =  Mandatory/error.c  Mandatory/error_utils.c  Mandatory/initialization.c  Mandatory/stack.c  Mandatory/swap.c  Mandatory/utils.c	Mandatory/main.c	Mandatory/libft.c	Mandatory/libft_utils.c	Mandatory/push.c	Mandatory/rotate.c	Mandatory/reverse_rotate.c	Mandatory/sort.c	Mandatory/bubble_sort.c	Mandatory/indexing.c	Mandatory/push_swap.c
OBJS = $(SRCS:.c=.o)
BSRCS =  Bonus/checker.c	Bonus/error.c  Bonus/error_utils.c  Bonus/initialization.c  Bonus/stack.c  Bonus/swap.c	Bonus/libft.c	Bonus/libft_utils.c	Bonus/push.c	Bonus/rotate.c	Bonus/utils.c	Bonus/reverse_rotate.c	Bonus/gnl/get_next_line.c	Bonus/gnl/get_next_line_utils.c
BOBJS = $(BSRCS:.c=.o)
NAME = push_swap
BNAME = checker


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BOBJS)
	$(CC) $(CFLAGS) $(BOBJS) -o $(BNAME)

clean:
	rm -rf $(OBJS) $(BOBJS)


fclean: clean
	rm -rf $(NAME) $(BNAME)

re: fclean all

.SECONDARY: $(OBJS) $(SRCS)