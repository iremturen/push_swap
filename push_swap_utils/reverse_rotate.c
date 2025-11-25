/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituren <ituren@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:36:36 by ituren            #+#    #+#             */
/*   Updated: 2025/11/25 16:19:32 by ituren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_stack(t_stack **s, char *msg)
{
	t_stack	*temp;
	t_stack	*last;
	t_stack	*prev;

	if (!s || !(*s) || !((*s)->next))
		return ;
	prev = NULL;
	last = *s;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev)
		prev->next = NULL;
	temp = last;
	temp->next = *s;
	*s = temp;
	write_message(msg);
}

void	reverse_rotate_ab(t_stack **a, t_stack **b)
{
	reverse_rotate_stack(a, NULL);
	reverse_rotate_stack(b, NULL);
	write_message("rrr\n");
}
