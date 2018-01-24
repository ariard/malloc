/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_print_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 23:05:13 by ariard            #+#    #+#             */
/*   Updated: 2018/01/24 23:58:01 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

# define FT_ABS(x)	(((x) < 0) ? -(x) : (x))

void		print_value(int n)
{
	int		i;
	int		neg;
	char	a[100];

	i = 0;
	bzero(a, 100);
	neg = (n < 0) ? 1 : 0;
	if (n == 0)
	{
		a[i++] = '0';
		a[i] = '\0';
	}
	while (n)
	{
		a[i++] = FT_ABS(n % 10) + '0';
		n /= 10;
	}
	if (neg)
		a[i++] = '-';
	a[i] = '\0';
	ft_strrev(a);
	write(3, &a, ft_strlen(a));
	write(3, "\n", 1);
}
