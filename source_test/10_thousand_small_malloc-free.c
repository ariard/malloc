#include <string.h>
#include <stdio.h>
#include <stdlib.h>

# define NBR	1000
# define SIZE	1500

int		main(void)
{
	char	a[SIZE + 1];
	char	*ptr[NBR + 1];
	int		nbr;
	size_t	size;

	memset(a, 'A', SIZE);

	size = SIZE;
	nbr = -1;
	while (++nbr < NBR)
	{
		ptr[nbr] = malloc(size + 1);
		strcpy(ptr[nbr], a);
		printf("[10] nb %d %s\n", nbr, ptr[nbr]);
	}	
	nbr -= 1;
	while (++nbr < NBR)
		free(ptr[nbr]);
	exit(0);
}
