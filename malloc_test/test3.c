#define M	(1024 * 1024)

void	print(char *s)
{
	write(1, s, strlen(s));
}

int		main(void)
{
	char	*addr1;
	char	*addr3;

	write(3, "test 1\n", 7);
	addr1 = (char *)malloc(16*M);
	strcpy(addr1, "Bonjours\n");
	print(addr1);
	write(3, "test 2\n", 7);
	addr3 = (char *)realloc(addr1, 128*M);
	write(3, "test 3\n", 7);
	addr3[127*M] = 42;
	write(3, "test 4\n", 7);
	print(addr3);
	return (0);
}
