/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_read_freelist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 20:36:57 by ariard            #+#    #+#             */
/*   Updated: 2018/01/10 21:27:18 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "malloc.h"

void			show_free_chunk(void)
{
	t_bin		*bin;
	t_chunk		*chunk;
	size_t		total;
	int			a;

	a = -1;
	total = 0;
	while (++a != 2 && !(bin = area.list[a]))
		;
	while (bin)
	{
		area_print(bin, a);
		chunk = bin->first;
		while (chunk)
		{
			DBG("%p - %p : %zu octets\n", chunk, (char *)chunk + BT(chunk), BT(chunk));
			total += BT(chunk);
			chunk = chunk->next;
		}
		if (!(bin = bin->next))
			while (++a != 2 && !(bin = area.list[a]))
				;
	}
	DBG("Total : %zu octets\n", total);
}
