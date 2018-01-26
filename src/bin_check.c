/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 18:23:42 by ariard            #+#    #+#             */
/*   Updated: 2018/01/26 19:24:46 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void		list_browse(t_bin *bin, void *ptr, int a)
{
	size_t		s_clean;

	s_clean = 1;
	while (bin_checkin(bin, ptr, (char)a, 1) && s_clean)
	{
		if (!(s_clean = BT(ptr) & ~(1 << 0)))
			return;
		if (SUM(ptr) == 0 || SUM(ptr) != checksum(BT(ptr)))
			chunk_error(ptr, 2);
		ptr = (char *)ptr + s_clean;
	}
}

static int		wr_getenv(char *str)
{
	char		*s;

	s = getenv(str);
	return ((s) ? ft_atoi(s) : -1);
}

void			bin_check(t_area *ar)
{
	static int	start;
	static int	op;
	int			a;
	void		*ptr;
	t_bin		*bin;

	write(3, "bin_check\n", 10);
	start = (!start) ? wr_getenv("MallocCheckHeapStart") : start;
	op = (!op) ? wr_getenv("MallocCheckHeapEach") : op;
	start = (!(--start)) ? -1 : start;
	op = (start < 0) ? --op : op;
	a = -1;
	if (!op && ar)
	{
		while (++a != 3 && !(bin = ar->list[a]))
			;
		while (bin)
		{
			ptr = (void *)bin + sizeof(t_bin) + sizeof(size_t) + sizeof(int);
			list_browse(bin, ptr, a);
			if (!(bin = bin->next))
				while (++a != 3 && !(bin = ar->list[a]))
					;
		}
	}
	write(3, "bin_check - end\n", 16);
}
