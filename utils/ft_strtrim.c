/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituren <ituren@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:03:15 by ituren            #+#    #+#             */
/*   Updated: 2025/11/17 19:51:07 by ituren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_set_char(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	if (end == 0)
		return (ft_strdup(""));
	while (s1[start] && is_set_char(s1[start], (char *)set))
		start++;
	while (end > start && is_set_char(s1[end], (char *)set))
		end--;
	str = ft_substr(s1, start, end - start + 1);
	return (str);
}
