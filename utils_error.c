/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunesli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:19:33 by agunesli          #+#    #+#             */
/*   Updated: 2022/06/03 12:19:44 by agunesli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	error_init(t_stack *begin)
{
	while (begin->next)
	{
		free(begin);
		begin = begin->next;
	}
	exit(0);
}

void	error_stack(t_stack **a, t_stack **b)
{
	free_stack(a);
	if (b)
		free_stack(b);
	error();
}

void	error_parsing(char **str)
{
	write(2, "Error\n", 6);
	free_all(str);
	exit(0);
}
