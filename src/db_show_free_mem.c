/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_read_freelist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 20:36:57 by ariard            #+#    #+#             */
/*   Updated: 2018/01/24 22:21:44 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "malloc.h"

static void		mem_print(t_chunk *chunk, size_t *total)
{
	while (chunk)
	{
		ft_dprintf(3, "%p - %p : %zu octets\n", chunk, (char *)chunk
			+ BT(chunk), BT(chunk));
		*total += BT(chunk);
		chunk = chunk->next;
	}
}

void			show_free_mem(void)
{
	t_bin		*bin;
	t_chunk		*chunk;
	size_t		total;
	int			a;
	t_area		*ar;

	a = -1;
	total = 0;
	ar = thread_set();
	while (++a != 2 && !(bin = ar->list[a]))
		;
	while (bin)
	{
		area_print(bin, a);
		chunk = bin->first;
		mem_print(chunk, &total);
		if (!(bin = bin->next))
			while (++a != 2 && !(bin = ar->list[a]))
				;
	}
	ft_dprintf(3, "Total : %zu octets\n", total);
	thread_unset2(ar);
}
