#include <pthread.h>
#include <stdio.h>

pthread_t		ntid1;
pthread_t		ntid2;
pthread_t		ntid3;
pthread_t		ntid4;
pthread_t		ntid5;
pthread_key_t	key;

void	*thr_func(void *arg)
{

	printf("thread : %d\n", (int)pthread_self());
	return (0);
}
	
int		main(void)
{
	pthread_create(&ntid1, NULL, thr_func, NULL);
	pthread_create(&ntid2, NULL, thr_func, NULL);
	pthread_create(&ntid3, NULL, thr_func, NULL);
	pthread_create(&ntid4, NULL, thr_func, NULL);
	pthread_create(&ntid5, NULL, thr_func, NULL);
	pthread_join(ntid1, NULL);
	pthread_join(ntid2, NULL);
	pthread_join(ntid3, NULL);
	pthread_join(ntid4, NULL);
	pthread_join(ntid5, NULL);
	return (0);
}
