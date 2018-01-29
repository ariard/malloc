#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		main(void)
{
	char	*a;
	char	*ptr;

	a = "hello world";
	ptr = malloc(strlen(a) + 1);
//	strcpy(ptr, a);
//	printf("[15] 1 %s\n", ptr);
	ptr = realloc(ptr, strlen(a) + 1);
	strcat(ptr, a);
	printf("[15] 2 %s\n", ptr);
	free(ptr);
	exit(0);
}
