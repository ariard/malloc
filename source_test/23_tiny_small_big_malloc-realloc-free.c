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
	a[SIZE1] = 0;
	memset(b, 'B', SIZE2);
	b[SIZE2] = 0;
	c = "hello world";
	
	ptr[0] = malloc(strlen(c) + 1 );
	strcpy(ptr[0], c);
	ptr[1] = malloc(SIZE2);
	strcpy(ptr[1], a);
	ptr[2] = malloc(SIZE2);
	strcpy(ptr[2], b);

	memset(a, 'C', SIZE1);
	a[SIZE1] = 0;
	memset(b, 'D', SIZE2);
	b[SIZE2] = 0;

	ptr[0] = realloc(ptr[0], strlen(c) + 1);
	strcat(ptr[0], c);
	printf("[21] 1 %s\n", ptr[0]);
	ptr[1] = realloc(ptr[1], SIZE1);
	strcat(ptr[1], a);
	printf("[21] 2 %s\n", ptr[1]);
	ptr[2] = realloc(ptr[2], SIZE2);
	strcat(ptr[2], b);
	printf("[21] 3 %s\n", ptr[2]);

	free(ptr[0]);
	free(ptr[1]);
	free(ptr[2]);
	exit(0);
}
