#include <stdio.h>

int		main(void)
{
	char	*a;

	a = malloc(100);
	strcpy(a, "hello world\n");
	printf("%s", a);
	return (0);
}
