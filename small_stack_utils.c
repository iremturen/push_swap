/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremturen <iremturen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 20:16:25 by iremturen         #+#    #+#             */
/*   Updated: 2025/11/24 19:29:47 by iremturen        ###   ########.fr       */
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
