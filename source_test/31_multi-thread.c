#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t	ntid1;
pthread_t	ntid2;
pthread_t	ntid3;
pthread_t	ntid4;
pthread_t	ntid5;
pthread_t	ntid6;
pthread_t	ntid7;
pthread_t	ntid8;
pthread_t	ntid9;
pthread_t	ntid10;
pthread_t	ntid11;
pthread_t	ntid12;
pthread_t	ntid13;
pthread_t	ntid14;
pthread_t	ntid15;
pthread_t	ntid16;


void		*thr_func(void *arg)
{
	char	*ptr[100];
	int	i;

	i = -1;
	while (++i < 100)
		ptr[i] = malloc(100);
	i = -1;
	while (++i < 100)
		free(ptr[i]);
	return (0);
}

int		main(void)
{
	pthread_create(&ntid1, NULL, thr_func, NULL);
	pthread_create(&ntid2, NULL, thr_func, NULL);
	pthread_create(&ntid3, NULL, thr_func, NULL);
	pthread_create(&ntid4, NULL, thr_func, NULL);
	pthread_create(&ntid5, NULL, thr_func, NULL);
	pthread_create(&ntid6, NULL, thr_func, NULL);
	pthread_create(&ntid7, NULL, thr_func, NULL);
	pthread_create(&ntid8, NULL, thr_func, NULL);
	pthread_create(&ntid9, NULL, thr_func, NULL);
	pthread_create(&ntid10, NULL, thr_func, NULL);
	pthread_create(&ntid11, NULL, thr_func, NULL);
	pthread_create(&ntid12, NULL, thr_func, NULL);
	pthread_create(&ntid13, NULL, thr_func, NULL);
	pthread_create(&ntid14, NULL, thr_func, NULL);
	pthread_create(&ntid15, NULL, thr_func, NULL);
	pthread_create(&ntid16, NULL, thr_func, NULL);

	pthread_join(ntid1, NULL);
	pthread_join(ntid2, NULL);
	pthread_join(ntid3, NULL);
	pthread_join(ntid4, NULL);
	pthread_join(ntid5, NULL);
	pthread_join(ntid6, NULL);
	pthread_join(ntid7, NULL);
	pthread_join(ntid8, NULL);
	pthread_join(ntid9, NULL);
	pthread_join(ntid10, NULL);
	pthread_join(ntid11, NULL);
	pthread_join(ntid12, NULL);
	pthread_join(ntid13, NULL);
	pthread_join(ntid14, NULL);
	pthread_join(ntid15, NULL);
	pthread_join(ntid16, NULL);

	exit(0);
}
