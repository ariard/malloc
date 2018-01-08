/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 21:17:14 by ariard            #+#    #+#             */
/*   Updated: 2018/01/08 23:55:28 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			free(void *ptr)
{
	t_bin 		*bs;
	t_chunk		freechunk;
	size_t		a_size;

	DBG(GREEN "FREE\n" RESET);
	if (!ptr || !(bs = chunk_find(ptr)))
		return;
	bs.bin->freespace += (a == 0) ? align(BT(ptr), 16) : align(BT(ptr), 512);
	a_size = (a == 0) ? area.cfg.tiny_area : area.cfg.small_area;
	a_size = (a == 2) ? BT(ptr) + sizeof(t_bin) : a_size;
	if (a == 2 || bs.bin->freespace == a_size)
	{
		if (bs.prev)
			bs.prev = bs.bin->next;
		munmap(bs.bin, a_size);
	}
	freechunk = bs.bin->first;	
	while (freechunk->next && (freechunk = freechunk->next))
		;
	((t_chunk*)ptr)->next = NULL;
	freechunk->next = ptr;
	BT(ptr) = SET_FREE(*(size_t *)((void *)ptr - sizeof(size_t)));
	BT_FINAL(ptr) = BT(ptr);
}
