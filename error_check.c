/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituren <ituren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:36:47 by ituren            #+#    #+#             */
/*   Updated: 2025/10/14 14:36:48 by ituren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	is_duplicate(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_number(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		if (!argv[i][j])
			return (0);
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_int_range(char *str)
{
	long	num;

	num = ft_atol(str);
	return (num >= -2147483648 && num <= 2147483647);
}

int	error_check(int argc, char **argv)
{
	int	i;

	if (argc < 2 || !is_number(argv, argc) || is_duplicate(argv, argc))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		if (!is_int_range(argv[i]))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		i++;
	}
	return (0);
}
