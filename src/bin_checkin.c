/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_checkin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:23:07 by ariard            #+#    #+#             */
/*   Updated: 2018/02/02 17:50:13 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int			bin_checkin(t_bin *bin, void *ptr, char a, char pos)
{
	size_t		max;

	if (a == 2)
		return (0);
	max = (a == 0) ? g_cfg.tiny_area : g_cfg.small_area;
	if ((pos < 0 || pos == 0) && (char *)ptr - (LT_PREV((void *)ptr)
		& ~(1 << 0)) + 1 > (char *)bin)
		return (1);
	if ((pos > 0 || pos == 0) && (char *)ptr + (BT(ptr)
		& ~(1 << 0)) - 1 < (char *)bin + max)
		return (1);
	return (0);
}
