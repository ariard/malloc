/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 20:36:20 by ariard            #+#    #+#             */
/*   Updated: 2018/02/04 18:29:33 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		malloc_print(int fd, void *add_one, void *add_two, size_t size)
{
	print_addr(fd, (unsigned long)add_one);
	write(fd, " - ", 3);
	print_addr(fd, (unsigned long)add_two);
	write(fd, " : ", 3);
	print_value(fd, size);
	write(fd, " octets \n", 9);
}

void		area_print(int fd, t_bin *bin, int a)
{
	char	*ar;

	ar = (a == 0) ? "TINY" : "SMALL";
	ar = (a == 2) ? "LARGE" : ar;
	write(fd, "[", 1);
	write(fd, ar, ft_strlen(ar));
	write(fd, "] : ", 4);
	print_addr(fd, (unsigned long)bin);
	write(fd, "\n", 1);
}

void		total_print(int fd, size_t total)
{
	write(fd, "Total : ", 8);
	print_value(fd, total);
	write(fd, " octets\n", 7);
}
