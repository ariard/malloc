#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

# define SIZE 	150000

int		main(void)
{
	char	a[SIZE + 1];
	char	*ptr;

	memset(a, 'A', SIZE);
	a[SIZE] = 0;
	
	ptr = malloc(SIZE);
	strcpy(ptr, a);
	printf("[08] %s\n", ptr);
	free(ptr);
	exit(0);
}
