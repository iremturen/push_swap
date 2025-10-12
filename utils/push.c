#include "push_swap.h"

void	push_stack(t_stack **stack_from, t_stack **stack_to, char *msg)
{
	t_stack	*temp;

	if (!stack_from || !(*stack_from))
		return ;
	temp = *stack_from;
	*stack_from = (*stack_from)->next;
	temp->next = *stack_to;
	*stack_to = temp;
	write_message(msg);
}

void	pa( t_stack **a, t_stack **b)
{
	push_stack(b, a, "pa\n");
}

void	pb( t_stack **a, t_stack **b)
{
	push_stack(a, b, "pb\n");
}