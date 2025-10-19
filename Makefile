NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

SRC = utils/ft_atoi.c \
utils/ft_atol.c \
utils/ft_isdigit.c \
utils/ft_split.c \
utils/ft_substr.c \
utils/ft_strdup.c \
utils/ft_strlen.c \
push_swap_utils/error_check.c \
push_swap_utils/push.c \
push_swap_utils/reverse_rotate.c \
push_swap_utils/rotate.c  \
push_swap_utils/rules_msg.c  \
push_swap_utils/stack_size.c \
push_swap_utils/swap.c \
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
