#include <string.h>
#include <stdio.h>
#include <stdlib.h>

# define SIZE 	150000

int		main(void)
{
	char	a[SIZE + 1];
	char	*ptr;

	memset(a, 'A', SIZE);
	
	ptr = malloc(strlen(a) + 1);
	strcpy(ptr, a);
	printf("[17] 1 %s\n", ptr);
	ptr = realloc(ptr, strlen(a) + 1);
	strcat(ptr, a);
	printf("[17] 2 %s\n", ptr);
	free(ptr);
	exit(0);
}
