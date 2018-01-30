#include <string.h>
#include <stdio.h>
#include <stdlib.h>

# define SIZE 	1500

int		main(void)
{
	char	a[SIZE + 1];
	char	*ptr;

	memset(a, 'A', SIZE);
	a[SIZE] = 0;
	
	ptr = malloc(SIZE);
	strcpy(ptr, a);
	printf("[16] 1 %s\n", ptr);
	memset(a, 'B', SIZE);
	a[SIZE] = 0;
	ptr = realloc(ptr, SIZE);	
	strcat(ptr, a);
	printf("[16] 2 %s\n", ptr);
	free(ptr);
	exit(0);
}
