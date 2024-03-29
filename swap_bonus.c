/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunesli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:18:39 by agunesli          #+#    #+#             */
/*   Updated: 2022/06/08 09:16:38 by agunesli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

void	init_index(t_stack *x)
{
	int		i;

	i = -1;
	while (++i < x->size)
	{
		x->index = i;
		x = x->next;
	}
}

void	swap(t_stack **x)
{
	t_stack	*tmp;

	tmp = (*x)->next;
	(*x)->next = tmp->next;
	tmp->next = *x;
	while ((*x)->index != (*x)->size - 1)
		(*x) = (*x)->next;
	(*x)->next = tmp;
	*x = tmp;
	init_index(*x);
	init_topget(*x, (*x)->size);
}

void	sswap(t_stack **x, t_stack **y)
{
	t_stack	*tmp;

	if (!*x || !*y)
		return ;
	tmp = (*x)->next;
	(*x)->next = tmp->next;
	tmp->next = *x;
	while ((*x)->index != (*x)->size - 1)
		(*x) = (*x)->next;
	(*x)->next = tmp;
	*x = tmp;
	init_index(*x);
	init_topget(*x, (*x)->size);
	tmp = (*y)->next;
	(*y)->next = tmp->next;
	tmp->next = *y;
	while ((*y)->index != (*y)->size - 1)
		(*y) = (*y)->next;
	(*x)->next = tmp;
	*y = tmp;
	init_index(*y);
	init_topget(*y, (*y)->size);
}
