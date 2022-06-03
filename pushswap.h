/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunesli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 22:47:57 by agunesli          #+#    #+#             */
/*   Updated: 2022/06/03 12:17:59 by agunesli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

// Structure
typedef struct s_stack
{
	int				nbr;
	int				index;
	int				size;
	int				stay;
	int				best_start;
	int				top_get;
	int				best_push;
	struct s_stack	*next;
}	t_stack;

typedef struct s_extremum
{
	int	min;
	int	max;
}	t_extremum;

// get_start
t_stack		*get_start(char **av, int ac);
void		init_topget(t_stack *begin, int size);
void		print_data(t_stack *begin, int size, char c);

// rules
void		push(t_stack **a, t_stack **b, char c);
void		rotate(t_stack **x, t_stack **y, char c);
void		rev_rotate(t_stack **x, t_stack **y, char c);
void		swap(t_stack **x, char c);

//algo
void		algo_push_b(t_stack **a, t_stack **b);
void		get_top(t_stack **x, t_stack *tmp, char c);
void		algo_back_a(t_stack **a, t_stack **b);
void		algo_3(t_stack **a);
void		get_min_top(t_stack **a);
void		get_max_top(t_stack **a);
t_extremum	found_extremum(t_stack *begin1, t_stack *begin2);
void		get_top2(t_stack **a, t_stack **b, t_stack *tmp);
t_stack		*found_good_place2(t_stack *a, int nbr);

// utils
void		error(void);
void		end(t_stack **a, t_stack **b);
void		free_all(char **d);
void		error_parsing(char **str);
int			ft_strlen_split(char **str);
void		free_stack(t_stack **begin);
char		**ft_shift(char **str, int size);
int			ft_max(int nb1, int nb2);
// utils_lst

// else
char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *src);
int			ft_atoi(const char *str);
int			arg(int ac, char **av);
#endif
