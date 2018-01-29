#include <string.h>
#include <stdio.h>
#include <stdlib.h>

# define NBR	1000

int		main(void)
{
	char	*a;
	char	*ptr[NBR + 1];
	int		nbr;
	size_t	size;

	a = "hello world";
	size = strlen(a);
	nbr = -1;
	while (++nbr < NBR)
	{
		ptr[nbr] = malloc(size + 1);
		strcpy(ptr[nbr], a);
		printf("[09] nb %d %s\n", nbr, ptr[nbr]);
	}	
	nbr -=1;
	while (++nbr < NBR)
		free(ptr[nbr]);
	exit(0);
}
