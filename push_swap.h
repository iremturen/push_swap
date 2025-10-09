#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h> 

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
void	add_stack(t_stack **a, int argc, char **argv);
t_stack	*create_node(int value);
int		is_sorted(t_stack *a);
int		ft_stack_size(t_stack *stack);
long	ft_atol(const char *str);

#endif