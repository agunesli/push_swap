#include "pushswap.h"
#include <stdio.h>

void	rot(t_stack *x)
{
	int	i;

	i = -1;
	while (++i < x->size)
	{
//		printf("index is %d ", x->index);
		x->index = (x->index - 1) % x->size;
		if (x->index < 0)
			x->index += x->size;
//		printf("index after is %d (size is %d)\n", x->index, x->size);
		x = x->next;
	}
	x = x->next;
	printf("x is %p %d\n", x, x->nbr);
	init_topget(x, x->size);
	print_data(x, x->size);
}

void	rotate(t_stack **x, t_stack **y, char c)
{
	printf("******** ROTATE *********\n");
	printf("Begin is %p %d\n", *x, (*x)->nbr);
	rot(*x);
	*x = (*x)->next;
	if (y)
		rot(*y);
	write(1, "r", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
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
	print_data(x, x->size);
}

void	rev_rotate(t_stack **x, t_stack **y, char c)
{
	printf("******** REV ROT *********\n");
	rot(*x);
	if (y)
		rot(*y);
	write(1, "rr", 2);
	write(1, &c, 1);
	write(1, "\n", 1);
}
