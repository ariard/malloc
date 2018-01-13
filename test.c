#include <pthread.h>

pthread_t		ntid1;
pthread_key_t	key;

void	*thr_func(void *arg)
{

	pthread_key_create(&key, NULL);
}
	
int		main(void)
{
	pthread_create(&ntid1, NULL, thr_func, NULL);
	while (1);
	return (0):
}
