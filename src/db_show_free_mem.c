/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_read_freelist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 20:36:57 by ariard            #+#    #+#             */
/*   Updated: 2018/01/21 19:29:22 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "malloc.h"

static void		fuck_norme(t_chunk *chunk, size_t *total)
{
	while (chunk)
	{
		DBG("%p - %p : %zu octets\n", chunk, (char *)chunk
			+ BT(chunk), BT(chunk));
		*total += BT(chunk);
		chunk = chunk->next;
	}
}

void			show_free_chunk(void)
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
		fuck_norme(chunk, &total);
		if (!(bin = bin->next))
			while (++a != 2 && !(bin = ar->list[a]))
				;
	}
	DBG("Total : %zu octets\n", total);
	thread_unset2(&ar->mutex);
}
