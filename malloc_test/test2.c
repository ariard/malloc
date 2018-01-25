int		main(void)
{
	int		i;
	char	*addr;

	i = 0;
	write(3, "test\n", 5);
	while (i < 1024)
	{
		addr = (char *)malloc(1024);
		addr[0] = 42;
		free(addr);
		i++;
	}
	return (0);
}
