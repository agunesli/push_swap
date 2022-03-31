#include "push_swap.h"

t_stacks	sa(t_stacks stacks)
{
	int	tmp;

	if (stacks.sizeA == 0 || stacks.sizeA == 1)
		return (stacks);
	tmp = stacks.stackA[0];
	stacks.stackA[0] = stacks.stackA[1];
	stacks.stackA[1] = tmp;
	write(1, "sa ", 3);
	return (stacks);
}

t_stacks	sb(t_stacks stacks)
{
	int	tmp;

	if (stacks.sizeA == 0 || stacks.sizeA == 1)
		return (stacks);
	tmp = stacks.stackB[0];
	stacks.stackB[0] = stacks.stackB[1];
	stacks.stackB[1] = tmp;
	write(1, "sb ", 3);
	return (stacks);
}

t_stacks	ss(t_stacks stacks)
{
	char	*tmp;

	if (!(stacks.sizeA == 0 || stacks.sizeA == 1))
	{
		tmp = stacks.stackA[0];
		stacks.stackA[0] = stacks.stackA[1];
		stacks.stackA[1] = tmp;
	}
	if (!(stacks.sizeA == 0 || stacks.sizeA == 1))
	{
		tmp = stacks.stackB[0];
		stacks.stackB[0] = stacks.stackB[1];
		stacks.stackB[1] = tmp;
	}
	write(1, "ss ", 3);
	return (stacks);
}

t_stacks	pa(t_stacks stacks)
{
	int	i;

	if (stacks.sizeB == 0)
		return (stacks);
	sizeB--;
	sizeA++;
	i = sizeA;
	while (0 < i)
	{
		stacks.stackA[i] = stacks.stackA[i - 1];
		i--;
	}
	stacks.stackA[0] = stacks.stackB[0];
	i = 0;
	while (i < sizeB)
	{
		stacks.stackB[i] = stacks.stackB[i + 1];
		i++;
	}
	write(1, "pa ", 3);
	return (stacks);
}

t_stacks	pb(t_stacks stacks)
{
	int	i;

	if (stacks.sizeA == 0)
		return (stacks);
	sizeA--;
	sizeB++;
	i = sizeB;
	while (0 < i)
	{
		stacks.stackB[i] = stacks.stackB[i - 1];
		i--;
	}
	stacks.stackB[0] = stacks.stackA[0];
	i = 0;
	while (i < sizeA)
	{
		stacks.stackA[i] = stacks.stackA[i + 1];
		i++;
	}
	write(1, "pb ", 3);
	return (stacks);
}
