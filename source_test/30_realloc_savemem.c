#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	char	*ptr[8000];
	char	*b;
	char	*c;
	int	nbr;

	b = "hello world";	
	nbr = -1;
	while (++nbr < 7709)
		ptr[nbr] = malloc(256);
	strcpy(ptr[--nbr], b);
	c = realloc(ptr[nbr], 500);
	exit(0);
}
