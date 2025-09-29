#include "push_swap.h"
//*a localde değiştirir
//**a adreisni alır yerinde değiiklik yapar

void swap_stack(t_stack **s, char *msg)
{
    t_stack *first;
    t_stack *second;

    if (!s || !(*s) || !((*s)->next))
        return;

    first = *s;
    second = (*s)->next;

    first->next = second->next;
    second->next = first;
    *s = second;
    write_message(msg); //burda msg null mı diye kontrol etmeli miiym
}

void swap_ab(t_stack **a, t_stack **b)
{
    swap_stack(a, NULL);
    swap_stack(b, NULL);
    write_message("ss");
}

