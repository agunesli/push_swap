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

#include "pushswap.h"

t_stack	*init_b(t_stack *b)
{
	b->size = 0;
	b->index = -1;
	return (b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

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
	if (a->size == 3)
		algo_3(&a);
	algo_push_b(&a, &b);
	algo_back_a(&a, &b);
	end(&a, &b);
}
