#include "push_swap.h"

t_stacks	sa(t_stacks stacks)
{
	int tmp;

	if (stacks.sizeA == 0 || stacks.sizeA == 1)
		return (stacks);
	tmp = stacks.stackA[0];
	stacks.stackA[0] = stacks.stackA[1];
	stacks.stackA[1];
	return (stacks);
}

t_stacks	sb(t_stacks stacks)
{
	int tmp;

	if (stacks.sizeA == 0 || stacks.sizeA == 1)
		return (stacks);
	tmp = stacks.stackB[0];
	stacks.stackB[0] = stacks.stackB[1];
	stacks.stackB[1];
}
