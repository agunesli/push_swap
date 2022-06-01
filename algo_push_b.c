#include "pushswap.h"
#include <stdio.h>

t_stack	*found_less_op(t_stack *begin)
{
	int		min;
	int		i;
	t_stack	*tmp;

	min = 2147483647;
	i = -1;
	tmp = NULL;
	while (++i < begin->size)
	{
		if (!begin->stay && min > begin->top_get)
		{
			tmp = begin;
			min = begin->top_get;
		}
		begin = begin->next;
	}
	if (tmp)
		printf("\n\nbest sort topget is %p %d %d\n", tmp, tmp->nbr, tmp->top_get);
	return (tmp);
}

void	get_top(t_stack **x, t_stack tmp, char c)
{
	int	i;
	int	top;

	i = -1;
	top = tmp->top_get;
	if (tmp->index < tmp->size / 2)
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

void	algo_push_b(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = found_less_op(*a);
//	printf("tmp is %p %d %d\n", tmp, tmp->nbr, tmp->top_get);
	while (tmp != NULL)
	{
		get_top(a, tmp, 97);
		//write(1, "bouh\n",5);
		push(a, b, 98);
		tmp = found_less_op(*a);
	}
}
