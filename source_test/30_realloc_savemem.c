#include <string.h>
#include <stdio.h>
#include <stdlib.h>

# define SIZE 756

int		main(void)
{
	char	*ptr[8000];
	char	a[SIZE + 1];
	char	*b;
	char	*c;
	int		nbr;

	memset(a, 'A', SIZE);

	nbr = -1;
	while (++nbr < 7709)
		ptr[nbr] = malloc(256);
	strcpy(ptr[--nbr], b);
	c = realloc(ptr[nbr], 500);
	strcpy(c, a);
	printf("[30] %s\n", c);
	exit(0);
}
