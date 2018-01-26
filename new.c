#include "libft/includes/libft.h"

int		main(void)
{
	char	*a;

	a = malloc(10);
	printf("true %p\n", a);
	ft_printf("false %p\n", a);
	return (0);
}
