/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_push_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunesli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:08:29 by agunesli          #+#    #+#             */
/*   Updated: 2022/06/03 12:11:31 by agunesli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	i = -1;
	while (begin2 && ++i < begin2->size)
	{
		if (ext.min > begin2->nbr)
			ext.min = begin2->nbr;
		if (ext.max < begin2->nbr)
			ext.max = begin2->nbr;
		begin2 = begin2->next;
	}
	return (ext);
}

t_stack	*found_good_place2(t_stack *a, int nbr)
{
	int			i;
	t_stack		*tmp;
	t_extremum	exta;

	exta = ((i = -1, found_extremum(a, NULL)));
	if ((a)->size == 1)
		return (a);
	if (nbr < exta.min)
	{
		while (++i < (a)->size && (a)->nbr != exta.max)
			a = (a)->next;
		return (a);
	}
	if (nbr > exta.max)
	{
		while (++i < (a)->size && (a)->nbr != exta.max)
			a = (a)->next;
		return (a);
	}
	while (++i < (a)->size)
	{
		if ((a)->nbr > nbr && nbr > (a)->next->nbr)
			tmp = a;
		a = (a)->next;
	}
	return (tmp->next);
}

void	init_best_push(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*tmp;

	if (*b == NULL)
		return ;
	i = -1;
	while (++i < (*a)->size)
	{
		tmp = found_good_place2(*b, (*a)->nbr);
		if (tmp->index <= tmp->size / 2 && (*a)->index <= (*a)->size / 2)
			(*a)->best_push = ft_max((*a)->top_get, tmp->top_get);
		else if (tmp->index > tmp->size / 2 && (*a)->index > (*a)->size / 2)
			(*a)->best_push = ft_max((*a)->top_get, tmp->top_get);
		else
			(*a)->best_push = (*a)->top_get + tmp->top_get;
		*a = (*a)->next;
	}
}

t_stack	*found_less_op(t_stack *a, t_stack **b)
{
	int		min;
	int		i;
	t_stack	*tmp;

	min = 2147483647;
	i = -1;
	tmp = NULL;
	init_best_push(&a, b);
	while (++i < a->size)
	{
		if (!a->stay && min > a->best_push)
		{
			tmp = a;
			min = a->best_push;
		}
		a = (a)->next;
	}
	return (tmp);
}

void	algo_push_b(t_stack **a, t_stack **b)
{
	t_stack		*tmp;

	tmp = found_less_op(*a, b);
	while (tmp != NULL)
	{
		get_top2(a, b, tmp);
		push(a, b, 98);
		tmp = found_less_op(*a, b);
	}
	if (*b)
		get_max_top(b);
}
