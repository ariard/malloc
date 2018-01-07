#include <stdio.h>

int		main(void)
{
	int		a;

	a = -10;
	printf("a %d\n", a);
	a = 1 >> (a << 1);
	printf("a %d\n", a);
	a = 10;
	printf("a %d\n", a);
	a = (a << 1);
	printf("a %d\n", a);
}
