/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituren <ituren@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 18:53:38 by ituren            #+#    #+#             */
/*   Updated: 2025/11/17 19:55:23 by ituren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_duplicate(t_stack **a, int num)
{
	t_stack	*head;

	head = *a;
	while (head != NULL)
	{
		if (head->value == num)
			return (1);
		head = head->next;
	}
	return (0);
}

static int	is_number(char *num)
{
	int	i;

	i = 0;
	if (num[i] == '-' || num[i] == '+')
		i++;
	if (!num[i])
		return (0);
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_int_range(char *str)
{
	long	num;
	int		i;
	int		digits;

	if (!str || !*str)
		return (0);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] == '0' && ft_isdigit(str[i + 1]))
		i++;
	digits = 0;
	while (ft_isdigit(str[i + digits]))
		digits++;
	if (digits > 10)
		return (0);
	num = ft_atol(str);
	return (num >= -2147483648L && num <= 2147483647L);
}

int	is_valid(char *str, t_stack **a)
{
	int	num;

	num = 0;
	if (!is_number(str))
		return (0);
	num = ft_atoi(str);
	if (!is_int_range(str))
		return (0);
	if (is_duplicate(a, num))
		return (0);
	return (1);
}
