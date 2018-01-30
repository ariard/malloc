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
	
	ptr = malloc(SIZE + 1);
	strcpy(ptr, a);
	printf("[17] 1 %s\n", ptr);
	memset(a, 'B', SIZE);
	a[SIZE] = 0;
	ptr = realloc(ptr, SIZE);
	strcat(ptr, a);
	printf("[17] 2 %s\n", ptr);
	free(ptr);
	exit(0);
}
