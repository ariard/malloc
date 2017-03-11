#include "malloc.h"

int	check_bin(t_bin	*temp, size_t size)
{
	if (temp->size > size)
		return (1);
	return (0);
}
