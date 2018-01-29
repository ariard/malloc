/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 19:08:06 by ariard            #+#    #+#             */
/*   Updated: 2018/01/30 00:11:28 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

char		chunk_check(t_area *ar, void *ptr)
{
	size_t	size;

	write(3, "cc - flag A\n", 12);
	if (!bin_range(ar, ptr))
		return (1);
	if (SUM(ptr) == 0 || SUM(ptr) != checksum(BT(ptr)))
		return (1);
	size = BT(ptr) & ~(1 << 0);
	if (LSUM(ptr, size) == 0 || LSUM(ptr, size) != checksum(LT(ptr, size)))
		return (1);
	write(3, "cc - flag B\n", 12);
	return (0);
}
