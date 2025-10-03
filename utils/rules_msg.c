#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*write_message(char *rule)
{
	write(1, rule, ft_strlen(rule));
}
