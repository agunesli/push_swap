/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunesli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 22:47:57 by agunesli          #+#    #+#             */
/*   Updated: 2022/05/30 22:12:26 by agunesli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
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

// get_start
t_stack	*get_start(char **av, int ac);
void	init_topget(t_stack *begin, int size);

// utils
void	error(void);
void	free_all(char **d);
void	error_parsing(char **str);
int	ft_strlen_split(char **str);
char	**ft_shift(char **str, int size);

// utils_lst

// else
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *src);
int	ft_atoi(const char *str);
int	arg(int ac, char **av);
#endif
