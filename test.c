#include "push_swap.h"

int ft_strlen(char  *str)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    while (str[i])
        i++;
    return (i);
}

void    Error(void)
{
    write(1, "Error\n", 6);
    exit(EXIT_FAILURE);
}

int all_num(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!( '0' <= str[i] && str[i] <= '9'))
            return (0);
        i++;
    }
    return (1);
}

int *create_stackA(int ac, char **av)
{
    int i;
    int *stackA;

    i = 1;
    stackA = malloc(sizeof(int) * ac);
    if (!stackA)
        Error();
    while (i < ac)
    {
        if (!all_num(av[i]))
        {
            free(stackA);
            Error();
        }
        stackA[i - 1] = ft_atoi(av[i]);
		i++;
    }
	stackA[i - 1] = '\0';
	return (stackA);
}

int *create_stackB(int ac)
{
    int i;
    int *stackB;

    i = 0;
    stackB = malloc(sizeof(int) * ac);
    if (!stackB)
        Error();
    while (i < ac)
    {
        stackB[i] = '-';
		i++;
    }
	stackB[i] = '\0';
	return (stackB);
}

int main(int ac, char **av)
{
	t_stacks	stacks;

	stacks.stackA = create_stackA(ac, av);
	stacks.stackB = create_stackB(ac);
	write(1, "OK\n", 3);
}
