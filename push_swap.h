#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
	int				value;
	long			index;
	struct s_list	*next;
}	t_stack;

char	*write_message(char *rule);
int		ft_strlen(char *str);
int		error_check(char **argv, int argc);
void	free_stack(t_stack **stack);

#endif