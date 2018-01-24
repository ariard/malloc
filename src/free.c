/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 21:17:14 by ariard            #+#    #+#             */
/*   Updated: 2018/01/24 21:18:51 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void		add_freechk(t_bins bins, void *ptr)	
{
	t_chunk		*listfree;

	listfree = bins.bin->first;
	((t_chunk *)ptr)->next = listfree;
	listfree->prev = ptr;
	bins.bin->first = ptr;
	BT(ptr) = SET_FREE(*(size_t *)((void *)ptr - sizeof(size_t)));
	*(size_t *)((void *)ptr + (*(size_t *)((void *)ptr - sizeof(size_t))
		& ~(1 << 0)) - 2 * sizeof(size_t)) = BT(ptr);
}

void			free(void *ptr)
{
	t_area		*ar;
	t_bins		bs;
	size_t		b_size;

	DBG(GREEN "FREE\n" RESET)
	pthread_once(&g_cfg.once, malloc_init);	
	ar = thread_set();
	if (!chunk_check(ptr))
		chunk_error();
	else if (ptr)
	{
		bs = chunk_find(ar, ptr);
		bs.bin->freespace += (BT(ptr) & ~(1 << 0));
		b_size = (bs.a == 0) ? g_cfg.tiny_area : g_cfg.small_area;
		b_size = (bs.a == 2) ? BT(ptr) + sizeof(t_bin) : b_size;
		if (bs.a == 2 || bs.bin->freespace == b_size)
		{
			if (bs.prev)
				bs.prev = bs.bin->next;
			munmap(bs.bin, b_size);
		}
		else
			add_freechk(bs, ptr);
	}
	DBG("flag free A\n");
	thread_unset2(ar); 
}
