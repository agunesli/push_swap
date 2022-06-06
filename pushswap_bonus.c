/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunesli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:15:48 by agunesli          #+#    #+#             */
/*   Updated: 2022/06/03 12:16:31 by agunesli         ###   ########.fr       */
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
		error_stack(a, b);
}

int	is_sorted(t_stack **a)
{
	int	sorted;
	int	i;

	i = -1;
	sorted = 1;
	while (++i < (*a)->size)
	{
		if ((*a)->index != (*a)->size - 1 && (*a)->nbr > (*a)->next->nbr)
			sorted = 1;
		(*a) = (*a)->next;
	}
	return (sorted);
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
			exit(1);
	}
	a = get_start(argv, argc);
	b = NULL;
	gnl = get_next_line(0);
	while (gnl)
	{
		found_op(gnl, &a, &b);
		free(gnl);
		gnl = get_next_line(0);
	}
	if (b) //Verifier l'etat de ma stack b a la fin du programme
		write(1, "KO\n", 3);
	else if (is_sorted(&a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	end(&a, &b);
}
