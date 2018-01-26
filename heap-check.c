#include "includes/malloc.h"
#include "libft/includes/libft.h"

int		main(void)
{
	char	*addr[100];
	int		i;

	i = -1;	
	write(3, "in main\n", 8);
	while (++i < 15)
	{
		addr[i] = (char *)malloc(1024);
		ft_dprintf(2, "%p\n", addr[i]);
	}
	i--;
//	write(3, "corrupt addr :\n", 15);
	ft_dprintf(2, "%p\n", addr[i]);
	strcpy(addr[i] - 20, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	malloc(10);
//	while (++i < 100)
//		addr[i] = (char *)malloc(1024);
	return (0);
}
