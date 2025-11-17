/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituren <ituren@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:36:47 by ituren            #+#    #+#             */
/*   Updated: 2025/11/17 19:53:44 by ituren           ###   ########.fr       */
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
		{
			free_stack(a);
			return (1);
		}
		if (!split[0])
		{
			free_split(split);
			free_stack(a);
			write(2, "Error\n", 6);
			return (1);
		}
		j = -1;
		while (split[++j])
		{
			if (!is_valid(split[j], a))
			{
				write(2, "Error\n", 6);
				free_split(split);
				free_stack(a);
				return (1);
			}
			add_stack(a, ft_atoi(split[j]));
		}
		free_split(split);
	}
	return (0);
}
