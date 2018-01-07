#include <stdio.h>

int	main(void)
{
	char	*a;
	char	*b;
	char	*c;

	a = NULL;
	b = a;
	c = "hello";
	b = c;
	printf("a is %s\n", a);
}
