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
	get_top(a, tmp, 97);
}

void	get_top(t_stack **x, t_stack *tmp, char c)
{
	int	i;
	int	top;

	i = -1;
	top = tmp->top_get;
	if (tmp->index <= tmp->size / 2)
	{
		while (++i < top)
			rotate(x, NULL, c);
	}
	else
	{
		while (++i < top)
			rev_rotate(x, NULL, c);

	}
}
