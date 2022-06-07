/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunesli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:11:44 by agunesli          #+#    #+#             */
/*   Updated: 2022/06/03 12:12:24 by agunesli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	in_the_first_part(t_stack **a, t_stack **b, int top, int topgp)
{
	int	i;

	i = -1;
	while (++i < ft_min(top, topgp))
		rotate(a, b, 114);
	i = -1;
	if (top > topgp)
	{
		while (++i < ft_max(top, topgp) - ft_min(top, topgp))
			rotate(a, NULL, 97);
	}
	else
	{
		while (++i < ft_max(top, topgp) - ft_min(top, topgp))
			rotate(b, NULL, 98);
	}
}

void	in_the_second_part(t_stack **a, t_stack **b, int top, int topgp)
{
	int	i;

	i = -1;
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
		while (++i < ft_max(top, topgp) - ft_min(top, topgp))
			rev_rotate(b, NULL, 98);
	}
}

void	anywhere_tmp(t_stack **a, int top, t_stack *tmp)
{
	int	i;

	i = -1;
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
}

void	anywhere_gp(t_stack **b, int topgp, t_stack *gp)
{
	int	i;

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

// gp = Good Place
void	get_top2(t_stack **a, t_stack **b, t_stack *tmp)
{
	int		top;
	int		topgp;
	t_stack	*gp;

	top = tmp->top_get;
	if (*b == NULL)
		return (get_top(a, tmp, 97));
	gp = found_good_place2(*b, tmp->nbr);
	topgp = gp->top_get;
	if (tmp->index <= tmp->size / 2 && gp->index <= gp->size / 2)
		in_the_first_part(a, b, top, topgp);
	else if (tmp->index > tmp->size / 2 && gp->index > gp->size / 2)
		in_the_second_part(a, b, top, topgp);
	else
	{
		anywhere_tmp(a, top, tmp);
		anywhere_gp(b, topgp, gp);
	}
}
