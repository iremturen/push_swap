#include "push_swap.h"

void	rotate_stack(t_stack **s, char *msg)
{
	t_stack	*temp;
	t_stack	*last;

	if (!s || !(*s) || !((*s)->next))
		return ;
	temp = *s;
	*s = (*s)->next;
	temp->next = NULL;
	last = *s;
	while (last->next)
		last = last->next;
	last->next = temp;
	write_message(msg);
}

void	rotate_ab(t_stack **a, t_stack **b)
{
	rotate_stack(a, NULL);
	rotate_stack(b, NULL);
	write_message("rr");
}
