#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

# define SIZE 756

int		main(void)
{
	char	*ptr[8000];
	char	a[SIZE + 1];
	char	*c;
	int		nbr;

	write(3, "in test\n", 8);
	memset(a, 'A', SIZE);
	a[SIZE] = 0;

	nbr = -1;
	while (++nbr < 7709)
		ptr[nbr] = malloc(256);

	strcpy(ptr[--nbr], a);
	printf("%p\n", ptr[nbr]);
	
	c = realloc(ptr[nbr], 500);
	
	memset(a, 'B', SIZE);
	a[SIZE] = 0;

	strcpy(c, a);
	printf("[30] %s\n", c);
	exit(0);
}
