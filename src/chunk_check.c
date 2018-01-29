/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 19:08:06 by ariard            #+#    #+#             */
/*   Updated: 2018/01/26 22:38:27 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

char		chunk_check(t_area *ar, void *ptr)
{
	size_t	size;

	if (!bin_range(ar, ptr))
		return (1);
	if (SUM(ptr) == 0 || SUM(ptr) != checksum(BT(ptr)))
		return (1);
	size = BT(ptr);
	if (LSUM(ptr, size) == 0 || LSUM(ptr, size) != checksum(LT(ptr, size)))
		return (1);
	return (0);
}
