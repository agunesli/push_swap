#include "pushswap.h"
#include <stdio.h>

t_stack	*found_good_place(t_stack **a, int nbr)
{
	int	i;
	t_stack	*tmp;

	i = -1;
	while (++i < (*a)->size)
	{
		if ((*a)->nbr > nbr)
			tmp = *a;
		*a = (*a)->next;
	}
	printf("Good place is %p %d [%d]\n", tmp, tmp->nbr, tmp->index);
	return (tmo);
}

void	init_back_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = found_good_place(a, (*b)->nbr);

}

void	algo_back_a(t_stack **a, t_stack **b)
{
	init_bestback(a, b);
}
