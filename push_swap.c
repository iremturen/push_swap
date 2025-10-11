#include "push_swap.h"


void	indexing(t_stack **a)
{
	t_stack	*temp;
	t_stack	*min_node;
	int		min_value;
	int		stack_size;
	int		index;

	temp = *a;
	index = 0;
	min_node = NULL;
	stack_size = ft_stack_size(*a);
	while (temp)
	{
		temp->index = -1;
		temp = temp->next;
	}
	while (index < stack_size)
	{
		temp = *a;
		min_node = NULL;
		min_value = INT_MAX;
		while (temp)
		{
			if (temp->index == -1 && temp->value < min_value)
			{
				min_value = temp->value;
				min_node = temp;
			}
			temp = temp->next;
		}
		if (min_node)
			min_node->index = index;
		index++;
	}
}

int	main(int argc, char const **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (error_check(argc, argv))
		return (1); //hata diye 1 yoksa 0 mı olmalı
	add_stack(&a, argc, argv);
	free_stack(a);
	free_stack(b);
	return (0);
}
