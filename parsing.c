#include "pushswap.h"
#include <stdio.h>

void	check_int(char **av, int size)
{
	int	i;
	int	tmp;

	i = -1;
	while (++i < size)
	{
		tmp = ft_atoi(av[i]);
		if (!tmp && (av[i][0] != '0'
		|| !(av[i][0] == '-' && av[i][1] == '0')))
			error();
		printf("a\n");
		if (tmp > 2147483647)
			error();
		printf("b\n");
		if (tmp < -2147483648)
			error();
		printf("c\n");
	}
	printf("A\n");
}

int	check_duplicate(char **av, int size)
{
	int	i;
	int	j;
	int	sorted;

	i = 0;
	sorted = 1;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				error();
			if (ft_atoi(av[i]) > ft_atoi(av[j]))
				sorted = 0;
			j++;
		}
		i++;
	}
	printf("B\n");
	return (sorted);
}

int	check(char **av, int size)
{
	check_int(av, size);
	return (check_duplicate(av, size));
}

int	arg(int ac, char **av)
{
	char	**str;

	str = NULL;
	if (ac == 2)
	{
		str = ft_split(av[1], ' ');
		return (check(str, ft_strlen_split(str)));
	}
	else
		return (check(av, ac));
}
