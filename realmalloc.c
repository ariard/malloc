int		main(void)
{
	char	*addr;

	addr = malloc(16);
	free((void *)addr + 6);
	realloc((void *)addr + 5, 10);
	return (0);
}
