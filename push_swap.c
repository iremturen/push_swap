/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituren <ituren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:36:59 by ituren            #+#    #+#             */
/*   Updated: 2025/10/14 14:37:00 by ituren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	radix_sort(t_stack **a, t_stack **b)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	size = ft_stack_size(*a); //stackde kaç eleman var
	max_bits = get_max_bit(*a); //en büyük indeex kaç bitlik
	i = 0;
	j = 0;

	while (i < max_bits) // her elemanın kaçıncı biti
	{
		j = 0;
		while (j < size) //elemanlaarı bitlere göre ontorl ediyoruz
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

int	main(int argc, char const **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (error_check(argc, argv))
		return (1); //hata diye 1 yoksa 0 mı olmalı
	add_stack(&a, argc, argv);
	indexing(&a);
	radix_sort(&a, &b);
	free_stack(a);
	free_stack(b);
	return (0);
}
