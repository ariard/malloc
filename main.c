#include "includes/malloc.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*str;
	char	test[20000];
	int		size = 16000;
	int		i = 0;
	
/*	DBG(RESET "\n\nMAIN\n");
	DBG(RED "str sizeof %d\n", size);
*/	while (size--)
	{
		strcat(test, "A");
		i++;
	}
	str = NULL;
	str = malloc(1);
	strcpy(str, test);
	printf("%s", str);
	return (0);
}
