/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunesli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:11:44 by agunesli          #+#    #+#             */
/*   Updated: 2022/06/03 12:12:24 by agunesli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
