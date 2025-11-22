/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremturen <iremturen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 12:28:08 by ituren            #+# #+#             */
/*   Updated: 2025/11/22 19:13:39 by iremturen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack **a)
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

static void	sort_four(t_stack **a, t_stack **b)
{
	int		min;
	int		pos;
	t_stack	*temp;

	min = get_min(*a);
	pos = 0;
	temp = *a;
	while (temp && temp->index != min && ++pos)
		temp = temp->next;
	if (pos <= 1)
		while ((*a)->index != min)
			rotate_stack(a, "ra\n");
	else
		while ((*a)->index != min)
			reverse_rotate_stack(a, "rra\n");
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

static void	sort_five(t_stack **a, t_stack **b)
{
	int		min;
	int		pos;
	t_stack	*temp;
	int		i;

	i = -1;
	while (++i < 2)
	{
		min = get_min(*a);
		pos = 0;
		temp = *a;
		while (temp && temp->index != min && ++pos)
			temp = temp->next;
		if (pos <= 2)
			while ((*a)->index != min)
				rotate_stack(a, "ra\n");
		else
			while ((*a)->index != min)
				reverse_rotate_stack(a, "rra\n");
		pb(a, b);
	}
	sort_three(a);
	pa(a, b);
	pa(a, b);
}

void	small_stack_sort(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		swap_stack(a, "sa\n");
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
}
