#include <stdio.h>

void	print(char *s)
{
	write(1, s, strlen(s));
}

int		main(void)
{
	char	*addr;

	write(3, "test\n", 5);
	addr = malloc(16);
	free(NULL);
	free((void *)addr + 6);
	write(3, "test 2 \n", 8);
	if (realloc((void *)addr + 5, 10) == NULL)
		print("Bonjours\n");
}
