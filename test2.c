#include <stdio.h>

char	*str(void)
{
	char	*a;
	
	a = "hello world";
	return (a);
}

int		main(void)
{
	char	*a;

	a = str();
	printf("%s\n", a);
	return (0);
}
