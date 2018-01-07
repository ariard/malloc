#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "malloc.h"

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


// TEST free list

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
//	free(a);
//	free(b);
//	free(c);
//
//	read_freelist();
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

int		main(void)
{
	char	*a;
	char	*b;
	char	*c;

	a = malloc(10);
	b = malloc(1100);
	c = malloc(130000);

	free(a);
	free(b);
	free(c);
	return (0);
}
