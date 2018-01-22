/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_range.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 23:22:29 by ariard            #+#    #+#             */
/*   Updated: 2018/01/23 00:13:23 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static char		bin_in(t_bin *bin, void *ptr, char a)
{
	if (a == 2)
		if ((char *)ptr > (char *)bin && (char *)ptr < (char *)bin + BT(ptr))
			return (1);
	if (a == 1)
		if ((char *)ptr > (char *)bin
			&& (char *)ptr < (char *)bin + g_cfg.small_area)
			return (1);
	if (a == 0)
		if ((char *)ptr > (char *)bin
			&& (char *)ptr < (char *)bin + g_cfg.tiny_area)
			return (1);
	return (0);
}

char			bin_range(t_area *ar, void *ptr)
{
	t_bin	*bin;
	int		a;

	a = -1;
	while (++a != 3 && !(bin = ar->list[a]))
		;
	while (bin)
	{
		if (bin_in(bin, ptr, a))
			return (1);
		if (!(bin = bin->next))
			while (++a != 3 && !(bin = ar->list[a]))
				;
	}
	return (0);
}
