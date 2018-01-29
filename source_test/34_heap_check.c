#include <string.h>
#include <stdlib.h>

int		main(void)
{
	char	*addr[100];
	int		i;

	i = -1;	
	while (++i < 15)
		addr[i] = malloc(1024);
	i--;
	strcpy(addr[i] - 20, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	addr[0] = malloc(10);
	return (0);
}
