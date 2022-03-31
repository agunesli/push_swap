#include "push_swap.h"

t_stacks	ra(t_stacks stacks)
{
	int	tmp;
	int	i;

	tmp = stacks.stacksA[0];
	i = 0;
	while (i < stacks.sizeA)
	{
		stacks.stackA[i] = stacks.stackA[i + 1];
		i++;
	}
	stacks.stackA[i] = tmp;
	write(1, "ra ", 3);
	return (stacks);
}

t_stacks	rb(t_stacks stacks)
{
	int	tmp;
	int	i;

	tmp = stacks.stacksB[0];
	i = 0;
	while (i < stacks.sizeB)
	{
		stacks.stackB[i] = stacks.stackB[i + 1];
		i++;
	}
	stacks.stackB[i] = tmp;
	write(1, "rb ", 3);
	return (stacks);
}

t_stacks	rr(t_stacks stacks)
{
	int	tmpa;
	int	tmpb;
	int	i;

	tmpa = stacks.stacksA[0];
	tmpb = stacks.stacksB[0];
	i = -1;
	while (++i < stacks.sizeA)
		stacks.stackA[i] = stacks.stackA[i + 1];
	stacks.stackA[i] = tmpa;
	i = -1;
	while (++i < stacks.sizeB)
		stacks.stackB[i] = stacks.stackB[i + 1];
	stacks.stackB[i] = tmpb;
	write(1, "rr ", 3);
	return (stacks);
}
