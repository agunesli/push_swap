#include "push_swap.h"

t_stacks	rra(t_stacks stacks)
{
	int	tmp;
	int	i;

	tmp = stacks.stacksA[stacks.sizeA];
	i = stacks.sizeA;
	while (0 < i)
	{
		stacks.stackA[i] = stacks.stackA[i - 1];
		i--;
	}
	stacks.stackA[i] = tmp;
	write(1, "rra ", 4);
	return (stacks);
}

t_stacks	rrb(t_stacks stacks)
{
	int	tmp;
	int	i;

	tmp = stacks.stacksB[stacks.sizeB];
	i = stacks.sizeB;
	while (0 < i)
	{
		stacks.stackB[i] = stacks.stackB[i - 1];
		i--;
	}
	stacks.stackB[i] = tmp;
	write(1, "rrb ", 4);
	return (stacks);
}

t_stacks	rr(t_stacks stacks)
{
	int	tmpa;
	int	tmpb;
	int	i;

	tmpa = stacks.stacksA[stacks.sizeA];
	tmpb = stacks.stacksB[stacks.sizeB];
	i = stacks.sizeA;
	while (0 < i)
	{
		stacks.stackA[i] = stacks.stackA[i - 1];
		i--;
	}
	stacks.stackA[i] = tmpa;
	i = stacks.sizeB;
	while (0 < i)
	{
		stacks.stackB[i] = stacks.stackB[i + 1];
		i--;
	}
	stacks.stackB[i] = tmpb;
	write(1, "rrr ", 4);
	return (stacks);
}
