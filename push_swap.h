/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunesli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 22:47:57 by agunesli          #+#    #+#             */
/*   Updated: 2022/03/29 23:01:07 by agunesli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdlib.h>
#include <unistd.h>

// Structure
typedef struct s_stack
{
	int	nbr;
	int	index;
	int	size;
 	int	stay;
    	int	top_get;
 	int	best_start;   // nb aui permet de trouver la plus longue liste
  	int	best_back;  // nb de coup de revenir au bon endroi dans la stack A
	struct s_stack	*next;
}	t_stack;

#endif
