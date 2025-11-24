/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremturen <iremturen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:36:47 by ituren            #+#    #+#             */
/*   Updated: 2025/11/24 19:41:34 by iremturen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

static int	handle_error(char **split, t_stack **a)
{
	free_split(split);
	free_stack(a);
	write(2, "Error\n", 6);
	return (1);
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
			return (handle_error(NULL, a));
		if (!split[0])
			return (handle_error(split, a));
		j = -1;
		while (split[++j])
		{
			if (!is_valid(split[j], a))
				return (handle_error(split, a));
			add_stack(a, ft_atol(split[j]));
		}
		free_split(split);
	}
	return (0);
}
