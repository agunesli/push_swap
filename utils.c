#include "pushswap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int	ft_strlen_split(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}
