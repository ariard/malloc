/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 18:23:42 by ariard            #+#    #+#             */
/*   Updated: 2018/01/29 22:02:50 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void		list_browse(t_bin *bin, void *ptr)
{
	size_t		s_clean;
	int		nbr;

	s_clean = 1;
	nbr = bin->nb;
	while (nbr--)
	{
		s_clean = BT(ptr) & ~(1 << 0);
		if (SUM(ptr) == 0 || SUM(ptr) != checksum(BT(ptr)))
			chunk_error(ptr, 2);
		if (LSUM(ptr, s_clean) == 0 
			|| LSUM(ptr, s_clean) != checksum(LT(ptr, s_clean)))
			chunk_error(ptr, 2);
		ptr = (char *)ptr + s_clean;
	}
}

void			bin_check(t_area *ar)
{
	static int	start;
	static int	op;
	int			a;
	void		*ptr;
	t_bin		*bin;

	if (start == 0 && !(start = g_cfg.start))
		return;
	start = (--start > 0) ? start : -1;
	if (!op && !(start = g_cfg.check))
		return;
	op = (start == -1) ? --op : op;
	a = -1;
	if (op == 0 && ar)
	{
		while (++a != 3 && !(bin = ar->list[a]))
			;
		while (bin)
		{
			ptr = (void *)bin + sizeof(t_bin) + sizeof(size_t) + sizeof(int);
			list_browse(bin, ptr);
			if (!(bin = bin->next))
				while (++a != 3 && !(bin = ar->list[a]))
					;
		}
	}
}
