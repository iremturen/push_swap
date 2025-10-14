/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituren <ituren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:37:04 by ituren            #+#    #+#             */
/*   Updated: 2025/10/14 17:21:33 by ituren           ###   ########.fr       */
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
				last = last->next;
			last->next = new;
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
