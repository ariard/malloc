#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	char	*a;
	char	*b;
	char	*ptr;

	a = "hello world";
	b = NULL;
	ptr = malloc(strlen(a) + 1);
	strcpy(ptr, a);
	printf("[12] %s\n", ptr);
	free(b);
	exit(0);
}
