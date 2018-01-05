#include <stdio.h>
#include <sys/mman.h>

int	main(void)
{
	void	*tmp;
	int		a;
	
	tmp = mmap(0, 10000, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	while (tmp)
	{
		printf("[addr] %p\n", tmp);
		a = *(int *)(tmp + 1);
		*tmp = *(void *)(tmp + 1);
		printf("[test] %x\n", a);
		break;
	}
	return (0);
}
