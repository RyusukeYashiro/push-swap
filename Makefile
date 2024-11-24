NAME = pushSwap.a

CC = cc

SRCS = src/main.c \
		src/sort_algo.c \
		src/ft_command/ft_push.c \
		src/ft_command/ft_reverse_rotate.c \
		src/ft_command/ft_swap.c \
		src/ft_command/ft_rotate.c \
		src/ft_sortalgo/ft_sort_mid.c \
		src/ft_sortalgo/ft_sort_min.c \
		src/utils/free.c \
		src/utils/ft_count_stack_len.c \
		src/utils/ft_push_a.c \
		src/utils/ft_stack_min.c \
		src/utils/ft_stack_max.c \
		src/utils/parse_check_and_push.c \

OBJS    = $(SRCS:.c=.o)

INCLUDES = include

CFLAGS = -Wall -Wextra -Werror -g -O0 -I $(INCLUDES)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

all : ${NAME}

LIBFT_PATH = ./Libft

LIBFT_NAME = libft.a


$(NAME):$(OBJS)
	make -C $(LIBFT_PATH) all
	ar -rcs $(NAME) $(OBJS)
	$(CC) $(CFLAGS) src/main.c $(NAME) $(LIBFT_PATH)/$(LIBFT_NAME) -o push_swap

clean:
	rm -f $(OBJS)
	@make -C $(LIBFT_PATH) clean 

fclean: clean 
		rm -f $(NAME)
		rm -f push_swap
		rm -f $(LIBFT_PATH)/$(LIBFT_NAME)
		
re:  fclean all

.PHONY: all clean fclean re		