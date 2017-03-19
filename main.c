#include "includes/malloc.h"
#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	char	*str;
	char	*str2;
	char	test[50000];
	int	size = atoi(argv[1]);
	
	while (size--)
		strcat(test, "A");
	str = malloc(atoi(argv[1]));
	strcpy(str, test);
	printf("%s", str);
	printf("\n");
	strcpy(str2, test);
	printf("%s", str2);	
	return (0);
}
