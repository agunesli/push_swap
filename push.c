#include "pushswap.h"
#include <stdio.h>

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
	printf("\n_______stack a_______\n"); //
	print_data(begin, size);//
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
	printf("\n_______stack b_______\n"); //
	print_data(begin, size); //
}

void	push(t_stack **src, t_stack **dst, char c)
{
	t_stack	*tmp;
	t_stack	*tmpp;

	tmp = *src;
	tmpp = *src;
	printf("\n**********PUSH********\n"); //
//	printf("src %p %d [%d]\n", *src, (*src)->nbr, (*src)->index); //
//	if (*dst) //
//		printf("dst %p %d [%d]\n", *dst, (*dst)->nbr, (*dst)->index); //
	while ((*src)->index != 0)
		*src = (*src)->next;
	printf("src is %p %d et ", *src, (*src)->nbr);
	while (tmp->index != tmp->size - 1)
		tmp = tmp->next;
	printf("tmp is %p %d\n", tmp, tmp->nbr);
	tmp->next = (*src)->next;
	tmp = tmp->next;
	*src = tmp;
	update_src(*src);
	if (!*dst)
	{
		*dst = tmpp;
		(*dst)->size = 1;
		(*dst)->next = *dst;
		printf("\n_______stack b_______\n"); //
		print_data(*dst, (*dst)->size); //
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
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}
