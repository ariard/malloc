/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 19:08:06 by ariard            #+#    #+#             */
/*   Updated: 2018/01/30 21:20:50 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

char		chunk_check(t_area *ar, void *ptr)
{
	size_t	size;

	write(3, "cc - flag A\n", 12);
	if (!bin_range(ar, ptr))
		return (1);
	write(3, "cc - flag B\n", 12);
	if (SUM(ptr) == 0 || SUM(ptr) != checksum(BT(ptr)))
	{
		write(3, "cc - flag C\n", 12);
		return (1);
	}
	write(3, "cc - flag D\n", 12);
	size = BT(ptr) & ~(1 << 0);
//	print_value(3, BT(ptr));
//	write(3, "\n", 1);
//	print_value(3, LSUM(ptr, size));
//	write(3, "\n", 1);
//	print_value(3, checksum(LT(ptr, size)));
//	write(3, "\n", 1);
	if (LSUM(ptr, size) == 0 || LSUM(ptr, size) != checksum(LT(ptr, size)))
		return (1);
	return (0);
}
