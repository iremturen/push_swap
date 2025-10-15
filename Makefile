
NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

SRC = utils/error_check.c \
utils/ft_stack_size.c \
utils/reverse_rotate.c \
utils/rules_msg.c \
utils/ft_atol.c \
utils/push.c \
utils/rotate.c \
utils/swap.c \
utils/ft_atoi.c \
utils/ft_isdigit.c \
push_swap.c \
stack_utils.c \
small_stack_sort.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
 
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
