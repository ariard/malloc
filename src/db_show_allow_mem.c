/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_show_allow_mem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:32:22 by ariard            #+#    #+#             */
/*   Updated: 2018/01/09 23:23:41 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void		mem_print(t_bin *bin, void *ptr, int a, size_t *total)
{
	size_t		s_clean;

	while (bin_checkin(bin, ptr, (char)a, 1))
	{
		s_clean = BT(ptr) & ~(1 << 0);
		if (s_clean == 0)
			return;
		if (BT(ptr) & 1)
			DBG("%p - %p : %zu octets\n", ptr, (char *)ptr + s_clean, s_clean);
		*total += s_clean;
		ptr = (char *)ptr + s_clean;
	}
}

void			show_alloc_mem(void)
{
	t_bin		*bin;
	int			a;
	void		*ptr;
	size_t		total;

	a = -1;
	total = 0;
	while (++a != 3 && !(bin = area.list[a]))
		;
	while (bin)
	{
		area_print(bin, a);
		ptr = (void *)bin + sizeof(t_bin) + sizeof(size_t);
		if (a == 2)
		{
			DBG("%p - %p : %zu octets \n", ptr, (char *)ptr + BT(ptr) - 1, BT(ptr) -1);
			total += SET_FREE(*(size_t *)ptr);
		}
		mem_print(bin, ptr, a, &total);
		if (!(bin = bin->next))
			while (++a != 3 && !(bin = area.list[a]))
				;
	}
	DBG("Total : %zu octets\n", total);
}
