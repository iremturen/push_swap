/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituren <ituren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:37:01 by ituren            #+#    #+#             */
/*   Updated: 2025/10/19 13:30:01 by ituren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				value;
	long			index;
	struct s_list	*next;
}	t_stack;

int		error_check(int argc, char **argv);
void	push_stack(t_stack **stack_from, t_stack **stack_to, char *msg);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	reverse_rotate_stack(t_stack **s, char *msg);
void	reverse_rotate_ab(t_stack **a, t_stack **b);
void	rotate_stack(t_stack **s, char *msg);
void	rotate_ab(t_stack **a, t_stack **b);
void	write_message(char *rule);
size_t	ft_strlen(const char *str);
int		stack_size(t_stack *stack);
void	swap_stack(t_stack **s, char *msg);
void	swap_ab(t_stack **a, t_stack **b);
int		ft_atoi(const char *str);
long	ft_atol(const char *str);
int		ft_isdigit(int c);
char	*ft_strdup(const char *s);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	small_stack_sort(t_stack **a, t_stack **b, int size);
void	free_stack(t_stack **stack);
void	add_stack(t_stack **a, int argc, char **argv);
t_stack	*create_node(int value);
int		is_sorted(t_stack *a);
int		get_max_bit(t_stack *stack);
void	radix_sort(t_stack **a, t_stack **b);
void	indexing(t_stack **a);
t_stack	*find_min(t_stack *a);
void	default_index(t_stack **stack);


#endif