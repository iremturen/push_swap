#include "push_swap.h"

int	main(int argc, char const *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (error_check(argc, argv))
		return (1); //hata diye 1 yoksa 0 mı olmalı
	//argümanları stack e atma 
	free_stack(a);
	free_stack(b);
	return (0);
}
