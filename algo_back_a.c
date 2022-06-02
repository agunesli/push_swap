#include "pushswap.h"

t_stack	*found_good_place(t_stack **a, int nbr)
{
	int			i;
	t_extremum	exta;
	t_stack		*tmp;

	i = -1;
	if ((*a)->size == 1)
		return (*a);
	exta = found_extremum(*a, NULL);
	if (nbr < exta.min)
	{
		while (++i < (*a)->size && (*a)->nbr != exta.min)
			*a = (*a)->next;
		return (*a);
	}
	if (nbr > exta.max)
	{
		while (++i < (*a)->size && (*a)->nbr != exta.max)
			*a = (*a)->next;
		return (*a);
	}
	while (++i < (*a)->size)
	{
		if ((*a)->nbr < nbr && nbr < (*a)->next->nbr)
			tmp = *a;
		*a = (*a)->next;
	}
	return (tmp->next);
}
/*
void	init_bestback(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		i;

	i = -1;
	while (++i < (*b)->size) //optimisation avec index
	{
		tmp = found_good_place(a, (*b)->nbr);
		(*b)->best_back = (*b)->top_get + tmp->top_get;
		printf("for %p %d [%d]", *b, (*b)->nbr, (*b)->index);
		printf(" => best_back is %d (%d + %d)\n\n", (*b)->best_back, (*b)->top_get, tmp->top_get);
		*b = (*b)->next;
	}
}

t_stack	*found_less_op2(t_stack *begin)
{
	int		min;
	int		i;
	t_stack	*tmp;

	min = 2147483647;
	i = -1;
	tmp = NULL;
	while (++i < begin->size)
	{
		if (min > begin->best_back)
		{
			tmp = begin;
			min = begin->top_get;
		}
		begin = begin->next;
	}
	if (tmp)
		printf("\n\nbest sort topget is %p %d %d\n", tmp, tmp->nbr, tmp->top_get);
	return (tmp);
} */

void	algo_back_a(t_stack **a, t_stack **b)
{
	t_stack		*tmp;

//	init_bestback(a, b);
	while (*b != NULL)
	{
		tmp = found_good_place(a, (*b)->nbr);
		// printf("Good place is %p %d for %p %d\n", tmp, tmp->nbr, *b, (*b)->nbr);
		get_top(b, *b, 98);
		get_top(a, tmp, 97);
		push(b, a, 97);
	}
	get_min_top(a);
}


