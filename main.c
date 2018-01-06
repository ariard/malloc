#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define SIZE	1028

int	main(void)
{
	char	*a;
	char	*c;
	char	*d;
	int		b;

	a = malloc(SIZE + 1 );
	b = SIZE;
	while (b--)
		strcat(a, "A");
	printf("%s\n", a);

	c = malloc(SIZE / 4);
	b = SIZE / 4;
	while (b--)
		strcat(c, "C");
	printf("%s\n", c);

	d = malloc(SIZE / 8);
	b = SIZE / 8;
	while (b--)
		strcat(d, "D");
	printf("%s", d);

	return (0);
}
