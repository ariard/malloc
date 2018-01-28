/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_print_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 22:56:27 by ariard            #+#    #+#             */
/*   Updated: 2018/01/28 20:59:17 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			print_addr(int fd, unsigned long i)
{
	char		s[1024];
	char		*base;
	int			index;
	int			j;

	ft_bzero(s, 1024);
	base = "0123456789abcdef";
	j = 0;
	if (i == 0)
		s[j++] = '0';
	while (i)
	{
		index = i % 16;
		s[j] = base[index];
		j++;
		i = i / 16;
	}
	s[j] = 0;
	ft_strrev(s);
	write(fd, "0x", 2);
	write(fd, &s[0], ft_strlen(s));
}
