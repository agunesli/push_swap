#include "pushswap.h"

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

void	push(t_stack **src, t_stack **dst, char c)
{
	t_stack	*tmp;
	t_stack	*tmpp;

	tmp = *src;
	tmpp = *src;
	// printf("\n**********PUSH********\n"); //
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
	// if (c == 97 && *src)
	// 	print_data(*src, (*src)->size, c + 1);
	// else if (*src)
	// 	print_data(*src, (*src)->size, c - 1);
	if (!*dst)
	{
		*dst = tmpp;
		(*dst)->size = 1;
		(*dst)->next = *dst;
		// print_data(*dst, (*dst)->size, (c));//
	}
	else
	{
		tmpp->next = *dst;
		while ((*dst)->index != (*dst)->size - 1)
			*dst = (*dst)->next;
		(*dst)->next = tmpp;
		*dst = (*dst)->next;
		update_dst(*dst);
		// print_data(*dst, (*dst)->size, (c));//
	}
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}
