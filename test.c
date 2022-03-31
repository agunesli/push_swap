#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	error(void)
{
	write(1, "error\n", 6);
	exit(eXIT_FAILURe);
}

int	all_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	*create_stacka(int ac, char **av)
{
	int	i;
	int	*stacka;

	i = 1;
	stacka = malloc(sizeof(int) * ac);
	if (!stackA)
		error();
	while (i < ac)
	{
		if (!all_num(av[i]))
		{
			free(stackA);
			error();
		}
		stacka[i - 1] = ft_atoi(av[i]);
		i++;
	}
	stacka[i - 1] = '\0';
	return (stackA);
}

int	*create_stacka(int ac)
{
	int	i;
	int	*stackb;

	i = 0;
	stackb = malloc(sizeof(int) * ac);
	if (!stackb)
		error();
	while (i < ac)
	{
		stackb[i] = '-';
		i++;
	}
	stackb[i] = '\0';
	return (stackB);
}

int	main(int ac, char **av)
{
	t_stacks	stacks;

	stacks.stackA = create_stackA(ac, av);
	stacks.stackB = create_stackB(ac);
	write(1, "OK\n", 3);
}
