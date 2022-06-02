#include "pushswap.h"

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
	return (tmp);
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

void	algo_push_b(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = found_less_op(*a);
	while (tmp != NULL)
	{
		get_top(a, tmp, 97);
		push(a, b, 98);
		tmp = found_less_op(*a);
	}
	printf("\n\n -------------- END 1 STEP --------------\n\n");
}
