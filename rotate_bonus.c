/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunesli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:18:14 by agunesli          #+#    #+#             */
/*   Updated: 2022/06/03 12:18:28 by agunesli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

void	rot(t_stack *x)
{
	int	i;

	i = -1;
	while (++i < x->size)
	{
		x->index = (x->index - 1) % x->size;
		if (x->index < 0)
			x->index += x->size;
		x = x->next;
	}
	x = x->next;
	init_topget(x, x->size);
}

void	rotate(t_stack **x, t_stack **y)
{
	// printf("\n******** ROTATE *********\n");
	rot(*x);
	while ((*x)->index != 0)
		*x = (*x)->next;
	// print_data(*x, (*x)->size, c);
	if (y)
	{
		rot(*y);
		while ((*y)->index != 0)
			*y = (*y)->next;
		// print_data(*y, (*y)->size, c);
	}
}

void	rev(t_stack *x)
{
	int	i;

	i = -1;
	while (++i < x->size)
	{
		x->index = (x->index + 1) % x->size;
		x = x->next;
	}
	while (x->index != 0)
		x = x->next;
	init_topget(x, x->size);
}

void	rev_rotate(t_stack **x, t_stack **y)
{
	// printf("\n******** REV ROT *********\n");
	rev(*x);
	while ((*x)->index != 0)
		*x = (*x)->next;
	// print_data(*x, (*x)->size, c);
	if (y)
	{
		rev(*y);
		while ((*y)->index != 0)
			*y = (*y)->next;
		// print_data(*y, (*y)->size, c);
	}
}
