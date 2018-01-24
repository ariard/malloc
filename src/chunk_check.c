/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 19:08:06 by ariard            #+#    #+#             */
/*   Updated: 2018/01/24 23:55:37 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

char		chunk_check(t_area *ar, void *ptr)
{
	if (!bin_range(ar, ptr))
		return (1);
	if (SUM(ptr) != checksum(BT(ptr)))
		return (1);
	write(3, "cc - flag D\n", 12);
	return (0);
}
