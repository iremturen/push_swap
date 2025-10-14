/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituren <ituren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:36:44 by ituren            #+#    #+#             */
/*   Updated: 2025/10/14 14:36:45 by ituren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack **s, char *msg)
{
	t_stack	*first;
	t_stack	*second;

	if (!s || !(*s) || !((*s)->next))
		return ;
	first = *s;
	second = (*s)->next;
	first->next = second->next;
	second->next = first;
	*s = second;
	write_message(msg);
}

void	swap_ab(t_stack **a, t_stack **b)
{
	swap_stack(a, NULL);
	swap_stack(b, NULL);
	write_message("ss\n");
}
