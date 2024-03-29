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

#ifndef PUSHSWAP_BONUS_H
# define PUSHSWAP_BONUS_H
# define BUFFER_SIZE 1
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

// get_start
t_stack		*get_start(char **av, int ac);
void		init_topget(t_stack *begin, int size);
void		print_data(t_stack *begin, int size, char c);

// rules
void		push(t_stack **src, t_stack **dst);
void		rotate(t_stack **x, t_stack **y);
void		rev_rotate(t_stack **x, t_stack **y);
void		swap(t_stack **x);
void		sswap(t_stack **x, t_stack **y);

//GNL
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr2(char const *s, unsigned int start, size_t end);
char		*get_next_line(int fd);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

// utils
void		error(void);
void		end(t_stack **a, t_stack **b);
void		free_all(char **d);
void		error_parsing(char **str);
void		error_stack(t_stack **a, t_stack **b, char *gnl);
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
