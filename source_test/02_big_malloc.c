#include <string.h>
#include <stdio.h>
#include <stdlib.h>

# define SIZE 	150000

int		main(void)
{
	char	a[SIZE + 1];
	char	*ptr;

	memset(a, 'A', SIZE);
	a[SIZE] = 0;
	
	ptr = malloc(SIZE);
	strcpy(ptr, a);
	printf("[02] %s\n", ptr);
	exit(0);
}
