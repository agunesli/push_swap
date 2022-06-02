#include "pushswap.h"

void	init_index(t_stack *x)
{
	int		i;

	i = -1;
	while (++i < x->size)
	{
		x->index = i;
		x = x->next;
	}
}

void	swap(t_stack **x, char c)
{
	t_stack	*tmp;

	// printf("\n******** SWAP *********\n");
	*x = (*x)->next;
	tmp = (*x)->next;
	(*x)->next = tmp->next;
	tmp->next = *x;
	(*x)->next->next= tmp;
	*x = tmp;
	init_index(*x);
	init_topget(*x, (*x)->size);
	print_data(*x, (*x)->size, c);
	write(1, "s", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}
