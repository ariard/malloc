#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	char	*a;
	char	*ptr;

	a = "hello world";
	b = "far far far far longuer";
	ptr = malloc(strlen(a) + 1);
	strncpy(ptr, b);
//	INTERN(show_alloc_mem())
	exit(0);
}
