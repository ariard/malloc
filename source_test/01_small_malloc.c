#include <string.h>
#include <stdio.h>
#include <stdlib.h>

# define SIZE 	1500

int		main(void)
{
	char	a[SIZE + 1];
	char	*ptr;

	memset(a, 'A', SIZE);
	
	ptr = malloc(strlen(a) + 1);
	strcpy(ptr, a);
	printf("[01] %s\n", ptr);
	exit(1);
}
