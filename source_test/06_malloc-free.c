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
	printf("[06] %s\n", ptr);
	free(ptr);
	exit(0);
}
