/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituren <ituren@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:37:04 by ituren            #+#    #+#             */
/*   Updated: 2025/11/25 16:20:51 by ituren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static t_stack	*create_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	add_stack(t_stack **a, int num)
{
	t_stack	*new;
	t_stack	*last;

	new = create_node(num);
	if (!new)
		return ;
	if (!*a)
		*a = new;
	else
	{
		last = *a;
		while (last->next)
			last = last->next;
		last->next = new;
	}
}

int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
		{
			return (0);
		}
		a = a->next;
	}
	return (1);
}

int	get_max_bit(t_stack *stack)
{
	t_stack		*temp;
	long		max;
	int			bits;

	bits = 0;
	max = 0;
	if (!stack)
		return (0);
	temp = stack;
	while (temp)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	while (max >> bits != 0)
		bits++;
	return (bits);
}
