/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremturen <iremturen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:36:59 by ituren            #+#    #+#             */
/*   Updated: 2025/11/24 19:29:15 by iremturen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	default_index(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp)
	{
		temp->index = -1;
		temp = temp->next;
	}
}

t_stack	*find_min(t_stack *a)
{
	t_stack	*temp;
	t_stack	*min_node;
	int		min_value;

	min_node = NULL;
	min_value = INT_MAX;
	temp = a;
	while (temp)
	{
		if (temp->index == -1 && temp->value < min_value)
		{
			min_value = temp->value;
			min_node = temp;
		}
		temp = temp->next;
	}
	return (min_node);
}

void	indexing(t_stack **a)
{
	t_stack	*min_node;
	int		index;

	index = 0;
	default_index(a);
	min_node = find_min(*a);
	while (min_node != NULL)
	{
		min_node->index = index++;
		min_node = find_min(*a);
	}
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	size = stack_size(*a);
	max_bits = get_max_bit(*a);
	i = 0;
	j = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size && *a)
		{
			if ((((*a)->index >> i) & 1) == 0)
				pb(a, b);
			else
				rotate_stack(a, "ra\n");
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	if (argc < 2)
		return (1);
	a = NULL;
	b = NULL;
	if (error_check(&a, argc, argv))
		return (1);
	if (is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	size = stack_size(a);
	indexing(&a);
	if (size <= 5)
		small_stack_sort(&a, &b, size);
	else
		radix_sort(&a, &b);
	return (free_stack(&a), free_stack(&b), 0);
}
