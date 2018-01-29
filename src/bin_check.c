/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 18:23:42 by ariard            #+#    #+#             */
/*   Updated: 2018/01/27 00:15:32 by ariard           ###   ########.fr       */
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

static int		wr_getenv(char *str)
{
	char		*s;

	s = getenv(str);
	return ((s) ? ft_atoi(s) : 0);
}

void			bin_check(t_area *ar)
{
	static int	start;
	static int	op;
	int		a;
	void		*ptr;
	t_bin		*bin;

	write(3, "bin_check\n", 10);
	if (start == 0 && !(start = wr_getenv("MallocCheckHeapStart")))
		return;
	start = (--start > 0) ? start : -1;
	if (!op && !(op = wr_getenv("MallocCheckHeapEach")))
		return;
	op = (start == -1) ? --op : op;
	a = -1;
	if (start == -1)
		write(3, "-1\n", 3);
	else
	{
		print_value(3, start);
		write(3, "\n", 1);
	}
	print_value(3, op);
	write(3, "\n", 1);
	if (op == 0 && ar)
	{
		write(3, "gonna check\n", 12);
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
	write(3, "bin_check - end\n", 16);
}
