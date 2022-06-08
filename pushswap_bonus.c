/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunesli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:15:48 by agunesli          #+#    #+#             */
/*   Updated: 2022/06/08 09:51:46 by agunesli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

void	found_op(char *gnl, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(gnl, "sa\n", 3))
		swap(a);
	else if (!ft_strncmp(gnl, "sb\n", 3))
		swap(b);
	else if (!ft_strncmp(gnl, "ss\n", 3))
		sswap(a, b);
	else if (!ft_strncmp(gnl, "pa\n", 3))
		push(b, a);
	else if (!ft_strncmp(gnl, "pb\n", 3))
		push(a, b);
	else if (!ft_strncmp(gnl, "ra\n", 3))
		rotate(a, NULL);
	else if (!ft_strncmp(gnl, "rb\n", 3))
		rotate(b, NULL);
	else if (!ft_strncmp(gnl, "rr\n", 3))
		rotate(a, b);
	else if (!ft_strncmp(gnl, "rra\n", 4))
		rev_rotate(a, NULL);
	else if (!ft_strncmp(gnl, "rrb\n", 4))
		rev_rotate(b, NULL);
	else if (!ft_strncmp(gnl, "rrr\n", 4))
		rev_rotate(a, b);
	else
		error_stack(a, b, gnl);
}

int	min_in_top(t_stack **a)
{
	int		min;
	int		i;
	t_stack	*tmp;

	min = 2147483647;
	i = -1;
	while (++i < (*a)->size)
	{
		if (min > (*a)->nbr)
		{
			tmp = *a;
			min = (*a)->nbr;
		}
		(*a) = (*a)->next;
	}
	if (tmp->index == 0)
		return (1);
	else
		return (0);
}

void	is_sorted(t_stack **a, t_stack **b)
{
	int	sorted;
	int	i;

	i = -1;
	sorted = 1;
	if (*b)
		write(1, "KO\n", 3);
	else
	{
		while (++i < (*a)->size)
		{
			if ((*a)->index != (*a)->size - 1 && (*a)->nbr > (*a)->next->nbr)
				sorted = 0;
			(*a) = (*a)->next;
		}
		if (sorted && min_in_top(a))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	end(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*gnl;

	if (argc == 1)
		exit(0);
	else if (argc == 2 && !argv[1][0])
		error();
	else
	{
		if (arg(argc, argv))
		{
			write(1, "OK\n", 3);
			exit(1);
		}
	}
	a = ((b = NULL, get_start(argv, argc)));
	gnl = get_next_line(0);
	while (gnl)
	{
		found_op(gnl, &a, &b);
		free(gnl);
		gnl = get_next_line(0);
	}
	is_sorted(&a, &b);
}
