/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_show_allow_mem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:32:22 by ariard            #+#    #+#             */
/*   Updated: 2018/01/09 18:40:14 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		print_area(t_bin *bin, int a)	
{
	char		*ar;

	ar = (a == 0) ? "TINY" : "SMALL";
	ar = (a == 2) ? "LARGE" : ar;
	DBG("[%s] : %p\n", ar, bin);
}
	
static int		range(void *bt, int a)
{
	if (a == 2)
		return (*(size_t *)bt);
	return ((a == 1) ? area.cfg.small_area : area.cfg.tiny_area);
}

static int		print_mem(t_bin *bin, int a, size_t *total)
{
	size_t		sizebt;
	void		*bt;

	bt = (void *)bin + sizeof(t_bin);
	while (1)
	{
		sizebt = SET_FREE(*(size_t *)bt);
		if ((_BUSY(*(size_t *)bt) || a == 2) && (*total += sizebt))
			DBG("%p - %p : %zu octets \n", bt, (char *)bt + sizebt, sizebt);
		if ((char *)bt + sizebt >= (char *)bin + range(bt, a))
			break;
		bt = (char *)bt + sizebt;
	}
	return (0);
}

void			show_alloc_mem(void)
{
	t_bin		*bin;
	int			a;
	size_t		total;

	a = -1;
	total = 0;
	while (++a != 3 && !(bin = area.list[a]))
		;
	while (bin)
	{
		print_area(bin, a);	
		print_mem(bin, a, &total);
		if (!(bin = bin->next))
			while (++a != 3 && !(bin = area.list[a]))
				;
	}
	DBG("Total : %zu octets\n", total);
}
