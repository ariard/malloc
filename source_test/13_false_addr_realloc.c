#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	char	*a;
	char	b;
	char	*ptr;

	a = "hello world";
	ptr = malloc(strlen(a) + 1);
	strcpy(ptr, a);
//	INTERN(show_alloc_mem())
	realloc(b, 10000);
//	INTERN(show_free_chunk())
	exit(0);
}
