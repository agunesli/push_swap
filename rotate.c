#include "pushswap.h"

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

void	rotate(t_stack **x, t_stack **y, char c)
{
	// printf("\n******** ROTATE *********\n");
	rot(*x);
	while ((*x)->index != 0)
		*x = (*x)->next;
	// print_data(*x, (*x)->size, c);
	if (y)
	{
		rot(*y);
		// print_data(*x, (*x)->size, c);
	}
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
}

void	rev_rotate(t_stack **x, t_stack **y, char c)
{
	// printf("\n******** REV ROT *********\n");
	rev(*x);
	while ((*x)->index != 0)
		*x = (*x)->next;
	// print_data(*x, (*x)->size, c);
	if (y)
	{
		rev(*y);
		// print_data(*x, (*x)->size, c);
	}
	write(1, "rr", 2);
	write(1, &c, 1);
	write(1, "\n", 1);
}
