/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunesli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:18:39 by agunesli          #+#    #+#             */
/*   Updated: 2022/06/03 12:19:17 by agunesli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

void	swap(t_stack **x, char c)
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
	write(1, "s", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	sswap(t_stack **x, t_stack **y)
{
	t_stack	*tmp;

	tmp = (*x)->next;
	(*x)->next = tmp->next;
	tmp->next = *x;
	(*x)->next->next = tmp;
	*x = tmp;
	init_index(*x);
	init_topget(*x, (*x)->size);
	tmp = (*y)->next;
	(*y)->next = tmp->next;
	tmp->next = *y;
	(*y)->next->next = tmp;
	*y = tmp;
	init_index(*y);
	init_topget(*y, (*y)->size);
	write(1, "ss\n", 3);
}
