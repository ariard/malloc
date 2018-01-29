#include <string.h>
#include <stdio.h>
#include <stdlib.h>

# define NBR	10000
# define SIZE	1500

int		main(void)
{
	char	*a;
	char	b[SIZE + 1];
	char	*ptr[NBR + 1];
	char	*ptr2[NBR + 1];
	int		nbr;
	size_t	size;

	a = "hello world";
	memset(b, 'A', SIZE);

	size = strlen(a);
	nbr = -1;
	while (++nbr < NBR)
	{
		ptr[nbr] = malloc(size + 1);
		strcpy(ptr[nbr], a);
		printf("[27] nb %d %s\n", nbr, ptr[nbr]);
	}

	nbr = -1;
	size = SIZE;
	while (++nbr < NBR)
	{
		ptr2[nbr] = malloc(size + 1);
		strcpy(ptr2[nbr], b);
		printf("[27] nb %d %s\n", nbr, ptr2[nbr]);
	}
	nbr -=1;
	while (++nbr < NBR)
	{
		free(ptr[nbr]);
		free(ptr2[nbr]);
	}
	exit(0);
}
