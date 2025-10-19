/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituren <ituren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:36:47 by ituren            #+#    #+#             */
/*   Updated: 2025/10/19 19:20:55 by ituren           ###   ########.fr       */
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
	int		len;
	int		max;

	max = 11;
	if (str[0] == '+' || str[0] == '-')
		max = 10;
	len = ft_strlen(str);
	if (len > max)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	num = ft_atol(str);
	return (num >= -2147483648 && num <= 2147483647);
}

int	error_check(t_stack **a, int argc, char **argv)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	while (++i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (1);
		j = -1;
		while (split[++j])
		{
			if (!is_number(split[j]) || !is_int_range(split[j]) || is_duplicate(a, ft_atoi(split[j])))
			{
				write(2, "Error\n", 6);
				return (1);
			}
			add_stack(a, ft_atoi(split[j]));
		}
	}
	return (0);
}
