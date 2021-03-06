#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define		SIZE	768		

int		main(void)
{
	char	*a[10000];
	char	*b;
	char	c[SIZE + 1];
	int	i;

	memset(c, 'A', SIZE);
	i = -1;
	while (++i < 10000)
		a[i] = malloc(256);

	printf("%p | %p\n", a[4999], a[5000]);
	free(a[4999]);
	free(a[5000]);
	write(3, "\n\n", 2);
	b = malloc(448);
	
	strcpy(b, c);
	printf("[32] %p  : %s\n", b, b);
	exit(0);
}
