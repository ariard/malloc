#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	char	*a;
	char	*ptr;

	a = "hello world";
	ptr = malloc(strlen(a) + 1);
	strcpy(ptr, a);
	printf("[00] %s\n", ptr);
	exit(0);
}
