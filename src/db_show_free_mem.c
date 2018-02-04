/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_read_freelist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 20:36:57 by ariard            #+#    #+#             */
/*   Updated: 2018/02/04 18:29:10 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "malloc.h"

static void		mem_print(t_chunk *chunk, size_t *total)
{
	while (chunk)
	{
		malloc_print(2, chunk, (char *)chunk + BT(chunk), BT(chunk));
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
		area_print(2, bin, a);
		chunk = bin->first;
		mem_print(chunk, &total);
		if (!(bin = bin->next))
			while (++a != 2 && !(bin = ar->list[a]))
				;
	}
	total_print(2, total);
	thread_unset2(ar);
}
