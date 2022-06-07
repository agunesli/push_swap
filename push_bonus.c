/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunesli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:14:36 by agunesli          #+#    #+#             */
/*   Updated: 2022/06/03 12:15:31 by agunesli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

void	update_src(t_stack *begin)
{
	int	size;
	int	i;

	size = begin->size - 1;
	i = -1;
	while (++i < size)
	{
		begin->size = size;
		begin->index = i;
		begin = begin->next;
	}
	init_topget(begin, size);
}

void	update_dst(t_stack *begin)
{
	int	size;
	int	i;

	size = begin->next->size + 1;
	i = -1;
	while (++i < size)
	{
		begin->size = size;
		begin->index = i;
		begin = begin->next;
	}
	init_topget(begin, size);
}

void	change_dst(t_stack *tmpp, t_stack **dst)
{
	if (!*dst)
	{
		*dst = tmpp;
		(*dst)->size = 1;
		(*dst)->next = *dst;
	}
	else
	{
		tmpp->next = *dst;
		while ((*dst)->index != (*dst)->size - 1)
			*dst = (*dst)->next;
		(*dst)->next = tmpp;
		*dst = (*dst)->next;
		update_dst(*dst);
	}
}

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;
	t_stack	*tmpp;

	if (!*src)
		return ;
	tmp = *src;
	tmpp = *src;
	while ((*src)->index != 0)
		*src = (*src)->next;
	while (tmp->index != tmp->size - 1)
		tmp = tmp->next;
	if (tmp == *src)
		*src = NULL;
	else
	{
		tmp->next = (*src)->next;
		tmp = tmp->next;
		*src = tmp;
		update_src(*src);
	}
	change_dst(tmpp, dst);
}
