#include "pushswap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_stack *a;
//	t_stack	b;


//	printf("ac = %d argv[0] = [%s]\n", argc, argv[0]);
	if (argc == 1) 
		exit(0);
	else if (argc == 2 && !argv[1][0])
		error();
	else
	{
		if (arg(argc, argv))
			exit(1);
	}
	a = get_start(argv, argc);	

}
