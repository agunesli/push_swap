#include "pushswap.h"
#include <stdio.h>

void	print_data(t_stack *begin, int size)
{
	int	i = 0;

	while (i < size)
	{
		printf("%p nb = %d, index = %d, size = %d, beststart = %d, stay = %d, top_get = %d, next = %p\n",begin, begin->nbr, begin->index, begin->size, begin->best_start, begin->stay, begin->top_get, begin->next);
		begin = begin->next;
		i++;
	}
}

t_stack	*init_a(char **dst, int size, t_stack *begin)
{
	int	i;
	t_stack	*tmp;
	
	i = size;
//	printf("size = %d\n", size);
	tmp = NULL;
	while (--i > -1 )
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
	int	i;
	int	j;
	t_stack	*tmp;
	t_stack	*fix;

	i = -1;
	fix = begin;
	while (++i < size)
	{
	//	printf("\n-----%p -> %d -----\n", fix, fix->nbr);
		fix->best_start = 1;
		tmp = fix;
		j = -1;
	//	printf("begin est %p  %d\n", begin, begin->nbr);
		while (++j < size)
		{
			if (tmp->nbr < begin->next->nbr)
			{
				fix->best_start++;;
				tmp = begin->next;
	//			printf("max nbr est %p %d => %d\n",tmp, tmp->nbr, fix->best_start);
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
	int	i;
	int	j;

	halfsize = size / 2 + size % 2;
	i = -1;
	j = -1;
//	printf("\nsize is %d, halfsize is %d\n", size, halfsize);
//	printf("Begin is %p %d %d\n", begin, begin->nbr, begin->top_get);
	while (++j < halfsize)
	{
//		printf("j = %d ", j);
		begin->top_get = j;
//		printf("topget = %d\n", begin->top_get);
		begin = begin->next;
	}
//	printf("j = %d\n", j);
	if (size % 2 == 0)
	{
//		write(1, "ded\n",4);
		begin->top_get = j;
		begin = begin->next;
	}
	while (--j > 0)
	{
//		printf("j = %d\n", j);
		begin->top_get = j;
		begin = begin->next;
	}
}

void	init_stay(t_stack *begin, int size)
{
	t_stack	*big;
	int	i;

	i = -1;
	big = begin;
	while (++i < size)
	{
		if (big->best_start < begin->best_start)
			big = begin;
		begin = begin->next;
	}
//	printf("Big is %p %d avec %d\n", big, big->nbr, big->best_start);
	i = -1;
	begin = big;
//	big->stay = 1;
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
//		printf("Now big is %p %d (%d) et begin is %p %d (%d)\n", big, big->nbr, big->stay, begin, begin->nbr, begin->stay);
	}
	big->stay = 1;
}

t_stack	*get_start(char **av, int ac)
{
	char	**dst;
	t_stack	*begin;
	int	size;

	if (ac == 2)
		dst = ft_split(av[1], ' ');
	else
		dst = ft_shift(av, ac);
	size = ft_strlen_split(dst);
	begin = init_a(dst, size, NULL);
	free_all(dst);
	init_beststart(begin, size); // OK
	init_stay(begin, size); // OK
	init_topget(begin, size); // OK
	printf("********** START **********\n");
	print_data(begin, size);
	return (begin);

}
