#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define		SIZE	768		

int		main(void)
{
	char	*a[10000];
	char	*b;
	char	c[SIZE + 1];
	int	i;

	memset(c, 'A', SIZE);
	i = -1;
	while (++i < 7709)
		a[i] = malloc(256);

	free(a[4999]);
	free(a[5000]);
	b = realloc(a[5001], 512);
	
	strcpy(b, c);
	printf("[32] %s\n", b);
	exit(0);
}
