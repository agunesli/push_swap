/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunesli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:39:04 by agunesli          #+#    #+#             */
/*   Updated: 2022/05/31 23:52:20 by agunesli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_data(t_stack *begin, int size, char c)
{
	int	i = 0;
	printf("\n_______stack %c_______\n", c);
	while (i < size)
	{
		printf("%p nb = %d, index = %d, size = %d, beststart = %d, stay = %d, top_get = %d, next = %p\n",begin, begin->nbr, begin->index, begin->size, begin->best_start, begin->stay, begin->top_get, begin->next);
		begin = begin->next;
		i++;
	}
}

t_stack	*init_a(char **dst, int size, t_stack *begin)
{
	int		i;
	t_stack	*tmp;

	i = size;
	tmp = NULL;
	while (--i > -1)
	{
		tmp = (t_stack *)malloc(sizeof(t_stack));
		if (!tmp)
			error(); //free les t_stack deja alloue
		tmp->nbr = ft_atoi(dst[i]);
		tmp->index = i;
		tmp->size = size;
		tmp->next = begin;
		begin = tmp;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = begin;
	return (begin);
}

void	init_beststart(t_stack *begin, int size)
{
	int		i;
	int		j;
	t_stack	*tmp;
	t_stack	*fix;

	i = -1;
	fix = begin;
	while (++i < size)
	{
		fix->best_start = 1;
		tmp = fix;
		j = -1;
		while (++j < size)
		{
			if (tmp->nbr < begin->next->nbr)
			{
				fix->best_start++;
				tmp = begin->next;
			}
			begin = begin->next;
		}
		fix = fix->next;
		begin = begin->next;
	}
}

void	init_topget(t_stack *begin, int size)
{
	int	halfsize;
	int	j;

	halfsize = size / 2 + size % 2;
	j = -1;
	while (++j < halfsize)
	{
		begin->top_get = j;
		begin->best_push = j;
		begin = begin->next;
	}
	if (size % 2 == 0)
	{
		begin->top_get = j;
		begin->best_push = j;
		begin = begin->next;
	}
	while (--j > 0)
	{
		begin->top_get = j;
		begin->best_push = j;
		begin = begin->next;
	}
}

void	init_stay(t_stack *begin, int size)
{
	t_stack	*big;
	int		i;

	i = -1;
	big = begin;
	while (++i < size)
	{
		if (big->best_start < begin->best_start)
			big = begin;
		begin = begin->next;
	}
	i = -1;
	begin = big;
	while (++i < size)
	{
		if (big->nbr < begin->next->nbr)
		{
			big->stay = 1;
			big = begin->next;
		}
		else
			begin->stay = 0;
		begin = begin->next;
	}
	big->stay = 1;
}

t_stack	*get_start(char **av, int ac)
{
	char	**dst;
	t_stack	*begin;
	int		size;

	if (ac == 2)
		dst = ft_split(av[1], ' ');
	else
		dst = ft_shift(av, ac);
	size = ft_strlen_split(dst);
	begin = init_a(dst, size, NULL);
	free_all(dst);
	init_beststart(begin, size);
	init_stay(begin, size);
	init_topget(begin, size);
	// printf("********** START **********\n");
	// print_data(begin, size, 'a');
	return (begin);
}
