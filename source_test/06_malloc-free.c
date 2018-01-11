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
//	INTERN(show_alloc_mem())
	free(ptr);
//	INTERN(show_free_chunk())
	exit(0);
}
