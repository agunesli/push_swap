/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_back_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunesli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:02:55 by agunesli          #+#    #+#             */
/*   Updated: 2022/06/03 12:06:36 by agunesli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*found_good_place(t_stack *a, int nbr)
{
	int			i;
	t_stack		*tmp;
	t_extremum	exta;

	exta = found_extremum(a, NULL);
	i = -1;
	if (a->size == 1)
		return (a);
	if (nbr < exta.min)
	{
		while (++i < a->size && a->nbr != exta.min)
			a = a->next;
		return (a);
	}
	if (nbr > exta.max)
	{
		while (++i < a->size && a->nbr != exta.max)
			a = a->next;
		return (a);
	}
	while (++i < a->size)
	{
		if (a->nbr < nbr && nbr < a->next->nbr)
			tmp = a;
		a = a->next;
	}
	return (tmp->next);
}

void	algo_back_a(t_stack **a, t_stack **b)
{
	t_stack		*tmp;
	while (*b != NULL)
	{
		tmp = found_good_place(*a, (*b)->nbr);
		get_top(b, *b, 98);
		get_top(a, tmp, 97);
		push(b, a, 97);
	}
	get_min_top(a);
}
