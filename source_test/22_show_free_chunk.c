#include <string.h>
#include <stdio.h>
#include <stdlib.h>

# define SIZE1	1500
# define SIZE2 	150000

int		main(void)
{
	char	a[SIZE1 + 1];
	char	b[SIZE2 + 1];
	char	c;
	char	*ptr[5];

	memset(a, 'A', SIZE1);
	memset(b, 'B', SIZE2);
	c = "hello world";
	
	ptr[0] = malloc(strlen(c) + 1);
	strcpy(ptr[0], c);
	ptr[1] = malloc(strlen(a) + 1);
	strcpy(ptr[1], a);
	ptr[2] = malloc(strlen(b) + 1);
	strcpy(ptr[2], b);
	free(ptr[0]);
	free(ptr[1]);
	free(ptr[2]);
//	INTERN(show_alloc_mem())
	exit(0);
}
