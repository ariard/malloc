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

	i = -1;
	while (++i < 7709)
		free(a[i]);
	
	b = malloc(744);
	exit(0);
}
