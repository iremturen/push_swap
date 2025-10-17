#include "push_swap.h"

int	get_max(t_stack *a)
{
	int		max;
	t_stack	*temp;

	if (!a)
		return (-1);
	max = a->index;
	temp = a->next;
	while (temp)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	return (max);
}

int	get_min(t_stack *a)
{
	int		min;
	t_stack	*temp;

	if (!a)
		return (-1);
	min = a->index;
	temp = a->next;
	while (temp)
	{
		if (temp->index < min)
			min = temp->index;
		temp = temp->next;
	}
	return (min);
}

void	sort_three(t_stack **a, t_stack **b)
{
	int	max;

	max = get_max(*a);
	if ((*a)->index == max)
		pb(a, b);
	else if ((*a)->next->index == max)
	{
		rotate_stack(a, "ra\n");
		pb(a, b);
	}
	else
	{
		reverse_rotate_stack(a, "rra\n");
		pb(a, b);
	}
	if (ft_stack_size(*a) > 1 && !is_sorted(*a))
		swap_stack(a, "sa\n");
	pa(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	min1;
	int	min2;

	min1 = get_min(*a);
	while ((*a)->index != min1)
		rotate_stack(a, "ra\n");
	pb(a, b);
	min2 = get_min(*a);
	while ((*a)->index != min2)
		rotate_stack(a, "ra\n");
	pb(a, b);
	sort_three(a, b);
	pa(a, b);
	pa(a, b);
}

void	small_stack_sort(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		swap_stack(a, "sa\n");
	else if (size == 3)
		sort_three(a, b);
	else if (size == 5)
		sort_five(a, b);
}
