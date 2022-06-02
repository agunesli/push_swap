#include "pushswap.h"

t_extremum	found_extremum(t_stack *begin1, t_stack *begin2)
{
	t_extremum	ext;
	int			i;

	ext.min = 2147483647;
	ext.max = -2147483648;
	i = -1;
	while (begin1 && ++i < begin1->size)
	{
		if (ext.min > begin1->nbr)
			ext.min = begin1->nbr;
		if (ext.max < begin1->nbr)
			ext.max = begin1->nbr;
		begin1 = begin1->next;
	}
	// printf("[A] le min est %d et max est %d\n",ext.min, ext.max);
	i = -1;
	while (begin2 && ++i < begin2->size)
	{
		if (ext.min > begin2->nbr)
			ext.min = begin2->nbr;
		if (ext.max < begin2->nbr)
			ext.max = begin2->nbr;
		begin2 = begin2->next;
	}
	// printf("[B] le min est %d et max est %d\n\n",ext.min, ext.max);
	return (ext);
}

t_stack	*found_good_place(t_stack **a, int nbr, t_extremum *ext)
{
	int			i;
	t_extremum	exta;
	t_stack		*tmp;

	i = -1;
	exta = found_extremum(*a, NULL);
	// printf("[ALL] le min est %d et max est %d\n",ext->min, ext->max);
	// printf("[A] le min est %d et max est %d\n",exta.min, exta.max);
	if (nbr == ext->min)
	{
		while (++i < (*a)->size && (*a)->nbr != exta.min)
			*a = (*a)->next;
		return (*a);
	}
	if (nbr == ext->max)
	{
		while (++i < (*a)->size && (*a)->nbr != exta.max)
			*a = (*a)->next;
		return (*a);
	}
	while (++i < (*a)->size)
	{
		write(1, "bouh\n", 5);
		if ((*a)->nbr < nbr && nbr < (*a)->next->nbr)
			tmp = *a;
		*a = (*a)->next;
	}
	// printf("Good place is %p %d [%d]\n", tmp, tmp->nbr, tmp->index);
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

void	get_min_top(t_stack **a)
{
	int		min;
	int		i;
	t_stack	*tmp;

	min = 2147483647;
	i = -1;
	while (++i < (*a)->size)
	{
		if (min > (*a)->nbr)
		{
			tmp = *a;
			min = (*a)->nbr;
		}
		(*a) = (*a)->next;
	}
	// printf("tmp is %p %d\n", tmp, tmp->nbr);
	get_top(a, tmp, 97);
}

void	algo_back_a(t_stack **a, t_stack **b)
{
	t_stack		*tmp;
	t_extremum	ext;

//	init_bestback(a, b);
	ext = found_extremum(*a, *b);
	while (*b != NULL)
	{
		tmp = found_good_place(a, (*b)->nbr, &ext);
		// printf("Good place is %p %d for %p %d\n", tmp, tmp->nbr, *b, (*b)->nbr);
		get_top(b, *b, 98);
		get_top(a, tmp, 97);
		push(b, a, 97);
	}
	get_min_top(a);
}


