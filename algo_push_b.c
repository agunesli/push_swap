#include "pushswap.h"
#include <stdio.h>

t_stack	*found_less_op(t_stack *begin)
{	
	int	min;
	int	i;
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
	printf("\n\nbest sort topget is %p %d %d\n", tmp, tmp->nbr, tmp->top_get);
	return (tmp);
}

void	algo_push_b(t_stack **a, t_stack **b)
{
	int	i;
	int	top;
	t_stack	*tmp;

	tmp = found_less_op(*a);
//	printf("tmp is %p %d %d\n", tmp, tmp->nbr, tmp->top_get);
	while (tmp != NULL)
	{
		i = -1;
		top = tmp->top_get;
		if (tmp->index < tmp->size / 2)
		{
			while (++i < top)
				rotate(a, NULL, 97);
		}
		else
		{
			while (++i < tmp->top_get)
				rev_rotate(a, NULL, 97);
		}
//		write(1, "bouh\n",5);
		push(a, b, 98);
		tmp = found_less_op(*a);
		write(1, "bouh\n", 5);
	}
}
