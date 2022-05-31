#include "pushswap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	free_all(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}	
	free(str);
}

void	error_parsing(char **str)
{
	write(2, "Error\n", 6);
	free_all(str);
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

char **ft_shift(char **str, int size)
{
	char	**dst;
	int	i;

	i = 0;
	dst = malloc(sizeof(char *) * size);
	if (!dst)
		error();
	while (i < size - 1)
	{
		dst[i] = ft_strdup(str[i + 1]);
		i++;
	}
	dst[i] = NULL;
	return (dst);
}