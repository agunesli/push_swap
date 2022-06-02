#include "pushswap.h"

t_stack	*found_good_place2(t_stack **a, int nbr)
{
	int			i;
	t_extremum	exta;
	t_stack		*tmp;

	if ((*a)->size == 1)
		return (*a);
	i = -1;
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
		if ((*a)->nbr > nbr && nbr > (*a)->next->nbr)
			tmp = *a;
		*a = (*a)->next;
	}
	return (tmp->next);
}

void	init_best_push(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*tmp;

	if (*b == NULL)
		return;
	i = -1;
	while (++i < (*a)->size)
	{
		tmp = found_good_place2(b, (*a)->nbr);
		(*a)->best_push = (*a)->top_get + tmp->top_get;
		*a = (*a)->next;
	}
}

t_stack	*found_less_op(t_stack **a, t_stack **b)
{
	int		min;
	int		i;
	t_stack	*tmp;

	min = 2147483647;
	i = -1;
	tmp = NULL;
	init_best_push(a, b);
	while (++i < (*a)->size)
	{
		if (!(*a)->stay && min > (*a)->best_push)
		{
			tmp = *a;
			min = (*a)->best_push;
		}
		*a = (*a)->next;
	}
	return (tmp);
}

void	algo_push_b(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tmpb;

	tmp = found_less_op(a, b);
	while (tmp != NULL)
	{
		get_top(a, tmp, 97);
		if (*b != NULL)
		{
			tmpb = found_good_place2(b, (*a)->nbr);
			get_top(b, tmpb, 98);
		}
		push(a, b, 98);
		tmp = found_less_op(a ,b);
	}
	// printf("\n\n -------------- END 1 STEP --------------\n\n");
	}
