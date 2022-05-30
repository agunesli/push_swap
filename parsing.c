#include "pushswap.h"
#include <stdio.h>

void	check_int(char **av)
{
	int	i;
	int	tmp;

	i = -1;
	while (av[++i] != NULL)
	{
		tmp = ft_atoi(av[i]);
		if (!tmp && (av[i][0] != '0'))
			error_parsing(av);
		if (tmp > 2147483647)
			error_parsing(av);
		if (tmp < -2147483647)
			error_parsing(av);
	}
}

int	check_duplicate(char **av)
{
	int	i;
	int	j;
	int	sorted;

	i = 0;
	sorted = 1;
	while (av[i] != NULL)
	{
		j = i + 1;
		while (av[j] != NULL)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				error_parsing(av);
			if (ft_atoi(av[i]) > ft_atoi(av[j]))
				sorted = 0;
			j++;
		}
		i++;
	}
	free_all(av);
	return (sorted);
}

int	check(char **av)
{
	check_int(av);
	return (check_duplicate(av));
}

int	arg(int ac, char **av)
{
	if (ac == 2)
		return (check(ft_split(av[1], ' ')));
	else
		return (check(ft_shift(av, ac)));
}
