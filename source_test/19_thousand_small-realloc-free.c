#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

# define NBR	1000
# define SIZE	1500

int		main(void)
{
	char	a[SIZE + 1];
	char	*ptr[NBR + 1];
	int		nbr;

	memset(a, 'A', SIZE);
	a[SIZE] = 0;

	nbr = -1;
	while (++nbr < NBR)
	{
		ptr[nbr] = malloc(SIZE);
		strcpy(ptr[nbr], a);
		printf("[19] 1 nb %d %s\n", nbr, ptr[nbr]);
	}	
	nbr = -1;

	memset(a, 'B', SIZE);
	a[SIZE] = 0;
	while (++nbr < NBR)
	{
		ptr[nbr] = realloc(ptr[nbr], SIZE);
		strcat(ptr[nbr], a);
		printf("[19] 2 nb %d %s\n", nbr, ptr[nbr]);
	}
	nbr = -1;
	while (++nbr < NBR)
		free(ptr[nbr]);
	exit(0);
}
