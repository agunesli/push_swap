/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunesli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:12:58 by agunesli          #+#    #+#             */
/*   Updated: 2021/11/29 17:02:45 by agunesli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static char	**ft_big_malloc(char const *s, char c)
{
	size_t	i;
	size_t	cpt;
	char	**dst;

	i = 0;
	cpt = 0;
	while (s[i])
	{
		if (s[i + 1] && s[i] == c && s[i + 1] != c && i != 0)
			cpt++;
		i++;
	}
	if (!cpt)
		dst = (char **)malloc(sizeof(char *));
	else 
		dst = (char **)malloc(sizeof(char *) * (cpt + 2));
	if (!dst)
		return (NULL);
	return (dst);
}

static void	ft_free_all(char **d)
{
	int	i;

	i = 0;
	while (d[i] == NULL)
	{
		free(d[i]);
		i++;
	}
	free(d[i]);
	free(d);
}

static char	**ft_subsplit(char const *s, char **dst, char c, size_t i)
{
	size_t	len;
	size_t	j;

	j = 0;
	while (s[i])
	{
		len = 0;
		while (s[i + len] && s[i + len] != c)
			len++;
		if (len != 0)
		{
			dst[j] = ft_substr(s, i, len);
			if (!dst[j])
			{
				ft_free_all(dst);
				break ;
			}
			j++;
			if (len + i == ft_strlen(s))
				len--;
		}
		i += (len + 1);
	}
	dst[j] = NULL;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**dst;

	if (!s)
		return (NULL);
	dst = ft_big_malloc(s, c);
	i = 0;
	dst = ft_subsplit(s, dst, c, i);
	return (dst);
}
