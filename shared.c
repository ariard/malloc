#include "shared.h"
#include <unistd.h>

void	*malloc(size_t b)
{
	char	*a;

	a = "hello world";
	inside();
	return (a);
}
