#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	char	*a[10000];
	char	*b;
	int	i;

	i = -1;
	while (++i < 7709)
		a[i] = malloc(256);
			
	free(a[5000]);		
	free(a[5001]);
	b = realloc(a[4999], 512);

	//show_alloc_mem();
	exit(0);
}
