/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_other.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunesli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:07:51 by agunesli          #+#    #+#             */
/*   Updated: 2022/06/03 12:08:17 by agunesli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	all_stay(t_stack *a)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		if (!(a)->stay)
			return (0);
		a = (a)->next;
	}
	return (1);
}

t_stack	*found_no_stay(t_stack **a)
{
	int		i;
	t_stack	*tmp;

	i = -1;
	while (++i < 3)
	{
		if (!(*a)->stay)
			tmp = *a;
		*a = (*a)->next;
	}
	return (tmp);
}

void	algo_3(t_stack **a)
{
	if (all_stay(*a))
		get_min_top(a);
	else
	{
		swap(a, 97);
		get_min_top(a);
	}
	end(a, NULL);
}
