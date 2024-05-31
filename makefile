NAME = push_swap

SRCS = catch_error.c push_swap.c radixbin.c sort.c \
		stack.c utils1.c utils2.c utils3.c utils4.c

OBJS = $(SRCS:.c=.o)

CC = gcc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
		@$(MAKE) -C ./libft
		@$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

clean:
		make clean -C libft
		@$(RM) *.o

fclean: clean
		make fclean -C libft
		@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re