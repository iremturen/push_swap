#include "push_swap.h"

void	reverse_rotate_stack(t_stack **s, char *msg)
{
	t_stack	*temp;
	t_stack	*last;
	t_stack	*prev;

	if (!s || !(*s) || !((*s)->next))
		return ;
	prev = NULL;
	last = *s;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev)
		prev->next = NULL;
	temp = last;
	temp->next = *s;
	*s = temp;
	write_message(msg);
}

void	reverse_rotate_ab(t_stack **a, t_stack **b)
{
	reverse_rotate_stack(a, NULL);
	reverse_rotate_stack(b, NULL);
	write_message("rr\n");
}
