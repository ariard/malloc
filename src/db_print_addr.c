/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_print_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 22:56:27 by ariard            #+#    #+#             */
/*   Updated: 2018/01/20 00:10:33 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static char		*ft_conv_hex(unsigned long long int i, char new[])
{
	char	s[1024];
	char	*base;
	int		index;
	int		j;

	ft_bzero(s, 1024);
	ft_bzero(new, 1024);
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
	ft_strcpy(new, s);
	return (new);
}

void	print_addr(void *ptr)
{
	char	str[1024];

	ft_conv_hex((unsigned long long int)ptr, str);
	write(3, "0x", 2);
	write(3, &str[0], ft_strlen(str));
	write(3, "\n", 1);
}
