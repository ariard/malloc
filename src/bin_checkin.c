/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_checkin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:23:07 by ariard            #+#    #+#             */
/*   Updated: 2018/01/09 19:30:22 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int			bin_checkin(t_bin *bin, void *ptr, char area, char pos)
{
	size_t		max;	

	if (a = 2)
		return (0);
	max = (a == 0) ? area.cfg.tiny_area : area.cfg.small_area;
	if (pos < 0 && (char *)ptr - BT_prev(ptr) > (char *)bin)
		return (1);
	if (pos > 0 && (char *)ptr + BT(ptr) < (char *)bin + max)
		return (1);
	return (0);
}
