#include <unistd.h>

void	inside(void)
{
	write(1, "i'm inside\n", 10);
}
