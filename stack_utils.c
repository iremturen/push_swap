#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	add_stack(t_stack **a, int argc, char **argv)
{
	int		i;
	int		num;
	t_stack	*new;
	t_stack	*last;

	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		new = create_node(num);
		if (!new)
			return ;
		if (!*a)
			*a = new;
		else
		{
			last = *a;
			while (last->next)
			{
				last = last->next;
				last->next = new;
			}
		}
		i++;
	}
}

t_stack	*create_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);

}