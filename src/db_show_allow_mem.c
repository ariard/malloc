/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_show_allow_mem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:32:22 by ariard            #+#    #+#             */
/*   Updated: 2018/01/08 22:20:02 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void		print_area(t_bin *bin, int a)	
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

void			show_alloc_mem(void)
{
	t_bin		*bin;
	void		*bt;
	size_t		sizebt;
	int		a;

	a = -1;
	while (++a != 3 && !(bin = area.list[a]));
	while (bin)
	{
		print_area(bin, a);	
		bt = (void *)bin + sizeof(t_bin);
		while (1)
		{
			//DBG("test business of chunk %zu \n", SET_FREE(*(size_t *)bt));
			sizebt = SET_FREE(*(size_t *)bt);
			if (_BUSY(*(size_t *)bt) || a == 2)
				DBG("%p - %p : %zu\n", bt, (char *)bt + sizebt, sizebt);
			//DBG("bt %p : %p a  %d range %d \n", (char *)bt + sizebt, (char *)bin + range(bt, a), a, range(bt, a));
			if ((char *)bt + sizebt >= (char *)bin + range(bt, a))
				break;
			bt = (char *)bt + sizebt;
		}
		if (!(bin = bin->next))
			while (++a != 3 && !(bin = area.list[a]));	
	}
}
