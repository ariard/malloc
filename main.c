#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "malloc.h"
#include <pthread.h>

# define SIZE	1028

// 	TEST multi tiny malloc

//int	main(void)
//{
//	char	*a;
//	char	*c;
//	char	*d;
//	int		b;
//
//	a = malloc(SIZE + 1 );
//	b = SIZE;
//	while (b--)
//		strcat(a, "A");
//	printf("%s\n", a);
//
//	c = malloc(SIZE / 4);
//	b = SIZE / 4;
//	while (b--)
//		strcat(c, "C");
//	printf("%s\n", c);
//
//	d = malloc(SIZE / 8);
//	b = SIZE / 8;
//	while (b--)
//		strcat(d, "D");
//	printf("%s", d);
//
//	read_freelist();	
//	return (0);
//}

// TEST free

//int		main(void)
//{
//	char	*a;
//
//	a = malloc(10);	
//	free(a);
//	return (0);
//}


///*  TEST free list */
//
//int			main(void)
//{	
//	char	*a;
//	char	*b;
//	char	*c;
//	char	*d;
//
//	a = malloc(20);
//	b = malloc(30);
//	c = malloc(40);
//	d = malloc(50);
//
//
//	free(a);
//	free(b);
//	free(c);
//
//	show_free_chunk();
//}

/*	TEST	coalescing */

//int		main(void)
//{
//	char	*a[20000];					
//	char	*b[10001];
//	int		i;
//	int		j;
//
//	i = -1;
//	j = 0;
//	while (++i < 10000)
//	{
//		if (!(a[j++] = malloc(52)))
//			return (printf("error little %d\n", j - 1));
//		read_freelist();
//		if (!(a[j++] = malloc(52)))
//			return (printf("error little %d\n", j - 1));
//		read_freelist();
//		if (!(b[i] = malloc(104)))
//			return (printf("error big %d\n", i));
//		printf("[ROT] %d", i);
//		read_freelist();
//	}
//	read_freelist();
//	j = -1;
//	printf("\n");
//	while (++j < 10000)
//	{
//		write(1, "0", 1);
//		free(a[j]);
//	}
//
//	return (0);
//}

// 		TEST		one of each size

//int		main(void)
//{
//	char	*a;
//	char	*b;
//	char	*c;
//
//	a = malloc(10);
//	b = malloc(1100);
//	c = malloc(130000);
//
//	free(a);
//	free(b);
//	free(c);
//	return (0);
//}
//

//		TEST		show_allow_mem

//int			main(void)
//{
//	int		i;	
//	char	*a[20];
//	char	*b[20];
//	char	*c[20];
//
//	i = 0;
//	while (i < 5)
//		a[i++] = malloc(128);
//
//	i = 0;
//	while (i < 5)
//		b[i++] = malloc(1024);
//
//	i = 0;
//	while (i < 5)
//		c[i++] = malloc(130000);
//
//	DBG("gonna use show_allow_mem...\n");
//	show_alloc_mem();
//	return (0);
//}

/*	TEST		aggregation forward aka realloc */

//int			main(void)
//{
//	char	*a;
//	char	*b;
//	char	*c;
//	char	*d;
//
//	a = malloc(100);
//	b = malloc(20);
//	c = malloc(80);
//	d = malloc(140);
//
//	free(b);
//	free(c);
//	free(d);
//	show_alloc_mem();
//	show_free_chunk();
//	a = realloc(a, 120);	
//	show_alloc_mem();
//	return (0);
//}


// 7709 256, create 744 hole before, after

// proof of coalescing backward
// proof of coalescing forward

//int		main(void)
//{
//	char	*a[10000];
//	char	*b;
//	int	i;
//
//	i = -1;
//	while (++i < 7709)
//		a[i] = malloc(256);
//	DBG(RED);
//	//show_alloc_mem();	
//	
//	i = -1;
//	while (++i < 7709)
//		free(a[i]);
//	DBG(GREEN);
//	show_free_chunk();
//	b = malloc(744);
////	DBG(RED);
////	DBG(GREEN);
//	show_free_chunk();
//	show_alloc_mem();
//	return (0);
//}

pthread_t		ntid1;
pthread_t		ntid2;
pthread_t		ntid3;
pthread_t		ntid4;
pthread_t		ntid5;
pthread_t		ntid6;
pthread_t		ntid7;
pthread_t		ntid8;
pthread_t		ntid9;
pthread_t		ntid10;
pthread_t		ntid11;
pthread_t		ntid12;
pthread_t		ntid13;
pthread_t		ntid14;
pthread_t		ntid15;
pthread_t		ntid16;

/*	THREAD */

//void	*thr_func(void *arg)
//{
//	char	*a[150];
//	int		i;
//	
//	i = -1;
//	while (++i < 100)
//		a[i] = malloc(100);
//	//lshow_alloc_mem();
//	return (0);
//}
//
//int		main(void)
//{
//
//	DBG("\n\n");
//	pthread_key_create(&thrfd, NULL);
//	pthread_create(&ntid1, NULL, thr_func, NULL);
//	pthread_create(&ntid2, NULL, thr_func, NULL);
//	pthread_create(&ntid3, NULL, thr_func, NULL);
//	pthread_create(&ntid4, NULL, thr_func, NULL);
//	pthread_create(&ntid5, NULL, thr_func, NULL);
//	pthread_create(&ntid6, NULL, thr_func, NULL);
//	pthread_create(&ntid7, NULL, thr_func, NULL);
//	pthread_create(&ntid8, NULL, thr_func, NULL);
//	pthread_create(&ntid9, NULL, thr_func, NULL);
//	pthread_create(&ntid10, NULL, thr_func, NULL);
//	pthread_create(&ntid11, NULL, thr_func, NULL);
//	pthread_create(&ntid12, NULL, thr_func, NULL);
//	pthread_create(&ntid13, NULL, thr_func, NULL);
//	pthread_create(&ntid14, NULL, thr_func, NULL);
//	pthread_create(&ntid15, NULL, thr_func, NULL);
//	pthread_create(&ntid16, NULL, thr_func, NULL);
//	
//	pthread_join(ntid1, NULL);
//	pthread_join(ntid2, NULL);
//	pthread_join(ntid3, NULL);
//	pthread_join(ntid4, NULL);
//	pthread_join(ntid5, NULL);
//	pthread_join(ntid6, NULL);
//	pthread_join(ntid7, NULL);
//	pthread_join(ntid8, NULL);
//	pthread_join(ntid9, NULL);
//	pthread_join(ntid10, NULL);
//	pthread_join(ntid11, NULL);
//	pthread_join(ntid12, NULL);
//	pthread_join(ntid13, NULL);
//	pthread_join(ntid14, NULL);
//	pthread_join(ntid15, NULL);
//	pthread_join(ntid16, NULL);
//	return (0);
//}

//int	main(void)
//{
//	char	*ptr[8000];
//	char	*b;
//	char	*c;;
//	int	nbr;
//
//	b = "hello world";
//
//	nbr = -1;	
//	while (++nbr < 7709)
//		ptr[nbr] = malloc(256);
//		
//	strcpy(ptr[--nbr], b);
//	printf("str %s\n", ptr[nbr]);
//	c = realloc(ptr[nbr], 500);
//	printf("str2 %s\n", c);
//	return (0);
//}

//int		main(void)
//{
//	int		i;
//	char	*addr;
//
//	i = 0;
//	while (i < 2)
//	{
//		addr = (char *)malloc(1024);
//		addr[0] = 42;
//		show_free_chunk();
//		free(addr);
//		show_free_chunk();
//		i++;
//	}
//	return (0);
//}
