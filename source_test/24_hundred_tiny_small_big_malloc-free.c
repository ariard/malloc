#include <string.h>
#include <stdio.h>
#include <stdlib.h>

# define SIZE1	1500
# define SIZE2 	150000
# define NBR	100
# define NBR2	5

int		main(void)
{
	char	a[SIZE1 + 1];
	char	b[SIZE2 + 1];
	char	*c;
	char	*ptr1[150];
	char	*ptr2[150];
	char	*ptr3[150];
	int		nbr;
	size_t	size;

	memset(a, 'A', SIZE1);
	memset(b, 'B', SIZE2);
	c = "hello world";
	

	size = strlen(c);
	nbr = -1;
	while (++nbr < NBR)
	{
		ptr1[nbr] = malloc(size + 1);
		strcpy(ptr1[nbr], c);
		printf("[24] 1 %s\n", ptr1[nbr]);
	}

	size = SIZE1;
	nbr = -1;
	while (++nbr < NBR)
	{
		ptr2[nbr] = malloc(size + 1);
		strcpy(ptr2[nbr], a);
		printf("[24] 2 %s\n", ptr2[nbr]);
	}

	size = SIZE2;
	nbr = -1;
	while (++nbr < NBR2)
	{
		ptr3[nbr] = malloc(size + 1);
		strcpy(ptr3[nbr], b);
		printf("[24] 3 %s\n", ptr3[nbr]);
	}

	nbr = -1;
	while (++nbr < NBR)
	{
		free(ptr1[nbr]);
		free(ptr2[nbr]);
	}
	nbr = -1;
	while (++nbr < NBR2)
		free(ptr3[nbr]);
	exit(0);
}
