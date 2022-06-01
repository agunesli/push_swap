#include "pushswap.h"
#include <stdio.h>

// need to put *b after good place
t_stack	*found_good_place(t_stack **a, int nbr)
{
	int		i;
	t_stack	*tmp;

	i = -1;
	while (++i < (*a)->size)
	{
		if ((*a)->nbr < nbr)
			tmp = *a;
		*a = (*a)->next;
	}
	printf("Good place is %p %d [%d]\n", tmp, tmp->nbr, tmp->index);
	return (tmp);
}

void	init_bestback(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		i;

	i = -1;
	while (++i < (*b)->size) //optimisation avec index
	{
		tmp = found_good_place(a, (*b)->nbr);
		(*b)->best_back = (*b)->top_get + tmp->top_get + 1;
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
}

void	algo_back_a(t_stack **a, t_stack **b)
{
	// int	i;
	// int	top;

	init_bestback(a, b);
	// while ((*b)->size > 0)
	// {
	// 	i = -1;
	// 	top = (*b)->top_get;
	// 	if ((*b)->index < (*b)->size / 2)
	// 	{
	// 		while (++i < top)
	// 			rotate(b, NULL, 98);
	// 	}
	// 	else
	// 	{
	// 		while (++i < top)
	// 			rev_rotate(b, NULL, 98);
	// 	}
	// 	//write(1, "bouh\n",5);
	// 	//push(a, b, 98);
	// }

}
