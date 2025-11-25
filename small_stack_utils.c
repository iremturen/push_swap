/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituren <ituren@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:20:40 by ituren            #+#    #+#             */
/*   Updated: 2025/11/25 16:20:48 by ituren           ###   ########.fr       */
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
