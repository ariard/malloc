t.c
 w e <stdio.h>

# define FREE(x)				x & 1
# define SET_VALUE_FREE(x, y)	x | (1 << y)
# define SET_VALUE_BUSY(x, y) 	x & ~(1 << y)

int		main(void)
{
	int		a;

	a = 4;
	printf("a is %d\n", a);
	a = SET_VALUE_FREE(a, 0);
	printf("a is %d\n", a);
	printf("mask a is %d\n", MASK(a));
	a = SET_VALUE_BUSY(a, 0);
	printf("a is %d\n", a);


}
