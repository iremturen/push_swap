/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituren <ituren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 12:28:08 by ituren            #+#    #+#             */
/*   Updated: 2025/10/19 13:14:30 by ituren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	sort_three(t_stack **a)
{
	int	min;
	int	max;

	max = get_max(*a);
	min = get_min(*a);
	if ((*a)->index == max)
		rotate_stack(a, "ra\n");
	else if ((*a)->next->index == max)
		reverse_rotate_stack(a, "rra\n");
	if ((*a)->index != min)
		swap_stack(a, "sa\n");
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
	sort_three(a);
	pa(a, b);
	pa(a, b);
}

void	small_stack_sort(t_stack **a, t_stack **b, int size)
{
	int	min;

	min = 0;
	if (size == 2)
		swap_stack(a, "sa\n");
	else if (size == 3)
		sort_three(a);
	else if (size == 5)
		sort_five(a, b);
	else if (size == 4)
	{
		min = get_min(*a);
		while ((*a)->index != min)
			rotate_stack(a, "ra\n");
		pb(a, b);
		sort_three(a);
		pa(a, b);
	}
}
