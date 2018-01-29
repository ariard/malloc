#include <string.h>
#include <stdio.h>
#include <stdlib.h>

# define SIZE1	1500
# define SIZE2 	150000

int		main(void)
{
	char	a[SIZE1 + 1];
	char	b[SIZE2 + 1];
	char	*c;
	char	*ptr[5];

	memset(a, 'A', SIZE1);
	memset(b, 'B', SIZE2);
	c = "hello world";
	
	ptr[0] = malloc(strlen(c) + 1);
	strcpy(ptr[0], c);
	printf("[21] 1 %s\n", ptr[0]);
	ptr[1] = malloc(strlen(a) + 1);
	strcpy(ptr[1], a);
	printf("[22] 2 %s\n", ptr[1]);
	ptr[2] = malloc(strlen(b) + 1);
	strcpy(ptr[2], b);
	printf("[22] 3 %s\n", ptr[2]);
	exit(0);
}
