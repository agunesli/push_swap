/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunesli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:11:44 by agunesli          #+#    #+#             */
/*   Updated: 2022/06/03 12:12:24 by agunesli         ###   ########.fr       */
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

void	get_max_top(t_stack **a)
{
	int		max;
	int		i;
	t_stack	*tmp;

	max = -2147483648;
	i = -1;
	while (++i < (*a)->size)
	{
		if (max < (*a)->nbr)
		{
			tmp = *a;
			max = (*a)->nbr;
		}
		(*a) = (*a)->next;
	}
	get_top(a, tmp, 98);
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

int	ft_min(int nb1, int nb2)
{
	if (nb1 < nb2)
		return (nb1);
	else
		return (nb2);
}

int	ft_max(int nb1, int nb2)
{
	if (nb1 < nb2)
		return (nb2);
	else
		return (nb1);
}

// gp = Good Place
// x c'est b
// tmp is in a
void	get_top2(t_stack **a, t_stack **b, t_stack *tmp)
{
	int		i;
	int		top;
	int		topgp;
	t_stack	*gp;

	i = -1;
	top = tmp->top_get;
	if (*b == NULL)
		return (get_top(a, tmp, 97));
	gp = found_good_place2(*b, tmp->nbr);
	topgp = gp->top_get;
	// printf("\ntmp (less_op) is %p %d [%d] and gp is %p %d [%d]\n", tmp, tmp->nbr, tmp->index, gp, gp->nbr, gp->index);
	// printf("the topget of tmp is %d and the topget of gp is %d\n",top, topgp);
	// printf(" => the min is %d\n",ft_min(top, topgp));
	// printf(" => the max is %d\n",ft_max(top, topgp));
	if (tmp->index <= tmp->size / 2 && gp->index <= gp->size / 2)
	{
		// printf("A\n");
		while (++i < ft_min(top, topgp))
			rotate(a, b, 114);
		i = -1;
		if (top > topgp)
		{
			while (++i < ft_max(top, topgp)- ft_min(top, topgp))
				rotate(a, NULL, 97);
		}
		else
		{
			while (++i < ft_max(top, topgp)- ft_min(top, topgp))
				rotate(b, NULL, 98);
		}
	}
	else if (tmp->index > tmp->size / 2 && gp->index > gp->size / 2)
	{
		// printf("B\n");
		while (++i < ft_min(top, topgp))
			rev_rotate(a, b, 114);
		i = -1;
		if (top > topgp)
		{
			while (++i < ft_max(top, topgp) - ft_min(top, topgp))
				rev_rotate(a, NULL, 97);
		}
		else
		{
			while (++i < ft_max(top, topgp)- ft_min(top, topgp))
				rev_rotate(b, NULL, 98);
		}
	}
	else
	{
		if (tmp->index <= tmp->size / 2)
		{
			while (++i < top)
				rotate(a, NULL, 97);
		}
		else
		{
			while (++i < top)
				rev_rotate(a, NULL, 97);
		}
		i = -1;
		if (gp->index <= gp->size / 2)
		{
			while (++i < topgp)
				rotate(b, NULL, 98);
		}
		else
		{
			while (++i < topgp)
				rev_rotate(b, NULL, 98);
		}
	}
}
