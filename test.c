#include <stdio.h>
#include <unistd.h>

struct 		s_my 
{
	char	*a;
	char	*b;
} typedef	t_my;

t_my		*my = NULL;

t_my		*my_gen(void)
{
	t_my	*my;

	my->a = "hello";
	my->b = "world";
	return (my);
}

int			main(void)
{
	char	*c;

	my = my_gen();
	c = my->a;
	return (0);
}
