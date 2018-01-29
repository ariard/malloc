/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_print_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 23:05:13 by ariard            #+#    #+#             */
/*   Updated: 2018/01/29 22:19:22 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		print_value(int fd, size_t n)
{
	int		i;
	char	a[100];

	i = 0;
	ft_bzero(a, 100);
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
	a[i] = '\0';
	ft_strrev(a);
	write(fd, &a, ft_strlen(a));
}
