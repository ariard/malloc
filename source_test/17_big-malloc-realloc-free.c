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
//	INTERN(show_alloc_mem())
	ptr = realloc(ptr, strlen(a) + 1);
	strcat(ptr, a);
	free(ptr);
//	INTERN(show_free_chunk())
	exit(0);
}
