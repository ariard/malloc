#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	char	*a;
	char	*b;
	char	*ptr;

	a = "hello world";
	b = "far far far far far far far far far far longuer";
	ptr = malloc(strlen(a) + 1);
	strcpy(ptr, b);
	printf("[14] %s\n", ptr);
	ptr = malloc(10);
	exit(0);
}
