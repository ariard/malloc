#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define SIZE	1028

int	main(void)
{
	char	*a;
	int		b;

	a = malloc(SIZE + 1 );
	b = SIZE;
	while (b--)
		strcat(a, "A");
	printf("%s", a);

	return (0);
}
